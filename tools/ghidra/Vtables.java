// Finds the vtables: runs of function-start pointers in initialised, non-executable blocks, cut wherever code loads
// an address of the run as an immediate (a constructor's `mov [ecx], vtable`, a secondary base's `mov [ecx+N], ...`).
// Each cut starts one vtable, ending at the next cut or the end of the run. Writes one line per vtable to the file
// given as the script argument: "<vtable> <slots> <functions loading it, comma-separated> <slot targets, comma-
// separated>" (all hex).
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis -readOnly \
//       -scriptPath tools/ghidra -postScript Vtables.java <out.tsv>
//@category OpenBuilder

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

public class Vtables extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("usage: Vtables.java <out.tsv>");
        Memory mem = currentProgram.getMemory();

        // Every immediate in code that is an address in a data block -> the functions using it.
        Map<Long, TreeSet<Long>> loadedBy = new HashMap<>();
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Instruction ins = it.next();
            for (int op = 0; op < ins.getNumOperands(); ++op) {
                Scalar s = ins.getScalar(op);
                if (s == null) continue;
                long v = s.getUnsignedValue() & 0xffffffffL;
                Address t;
                try { t = toAddr(v); } catch (Exception e) { continue; }
                MemoryBlock b = mem.getBlock(t);
                if (b == null || b.isExecute()) continue;
                Function f = getFunctionContaining(ins.getAddress());
                loadedBy.computeIfAbsent(v, k -> new TreeSet<>()).add(f != null ? f.getEntryPoint().getOffset() : 0L);
            }
        }

        int vtables = 0;
        long slots = 0;
        try (PrintWriter out = new PrintWriter(args[0])) {
            for (MemoryBlock block : mem.getBlocks()) {
                if (block.isExecute() || !block.isInitialized()) continue;
                Address start = block.getStart();
                long n = block.getSize() / 4;
                List<long[]> run = new ArrayList<>();  // {address, target}
                for (long k = 0; k <= n && !monitor.isCancelled(); ++k) {
                    long target = -1;
                    Address at = k < n ? start.add(k * 4) : null;
                    if (at != null) {
                        Address t;
                        try { t = toAddr(mem.getInt(at) & 0xffffffffL); } catch (Exception e) { t = null; }
                        // A function, or code outside the first piece of every function: the pure-virtual stub is reached
                        // only through vtables and is no function to the analyser, and functions it merged into another's
                        // body as a later piece are functions of their own. A pointer into a function's first piece is no
                        // slot.
                        if (t != null && (getFunctionAt(t) != null || (isCode(mem, t) && !inFirstPiece(t))))
                            target = t.getOffset();
                    }
                    if (target >= 0) { run.add(new long[] {at.getOffset(), target}); continue; }
                    // the run ended: cut it at every address code loads
                    int cut = -1;
                    for (int i = 0; i <= run.size(); ++i) {
                        boolean isCut = i < run.size() && loadedBy.containsKey(run.get(i)[0]);
                        if ((isCut || i == run.size()) && cut >= 0) {
                            StringBuilder fns = new StringBuilder(), targets = new StringBuilder();
                            for (long f : loadedBy.get(run.get(cut)[0])) fns.append(fns.length() > 0 ? "," : "").append(Long.toHexString(f));
                            for (int j = cut; j < i; ++j) targets.append(j > cut ? "," : "").append(Long.toHexString(run.get(j)[1]));
                            out.printf("%08x %d %s %s%n", run.get(cut)[0], i - cut, fns, targets);
                            ++vtables;
                            slots += i - cut;
                        }
                        if (isCut) cut = i;
                    }
                    run.clear();
                }
            }
        }
        println("found " + vtables + " vtables, " + slots + " slots");
    }

    private boolean inFirstPiece(Address a) {
        Function f = getFunctionContaining(a);
        if (f == null) return false;
        AddressRange first = f.getBody().getRangeContaining(f.getEntryPoint());
        return first != null && first.contains(a);
    }

    private static boolean isCode(Memory mem, Address a) {
        MemoryBlock b = mem.getBlock(a);
        return b != null && b.isExecute() && b.isInitialized();
    }
}
