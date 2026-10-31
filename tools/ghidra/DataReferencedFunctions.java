// Creates the functions analysis missed, then saves the program (run it without -readOnly):
//  1. every address a pointer in data leads to (vtable methods, callback and registration tables): aligned 4-byte
//     values in initialised, non-executable blocks that point into an executable block;
//  2. every address an instruction's immediate operand leads to (a callback stored or pushed by code);
//  3. code outside every function that starts right after padding or a return (functions nothing refers to).
// Only targets outside every existing function body count. Repeats until a pass adds nothing, since new functions
// bring new code.
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis \
//       -scriptPath tools/ghidra -postScript DataReferencedFunctions.java
//@category OpenCityBuilder

import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

import java.util.TreeSet;

public class DataReferencedFunctions extends GhidraScript {
    // int3, nop, and the lea r,[r+0] / mov r,r multi-byte nops another compiler pads with
    private static boolean isPadding(Instruction ins) {
        String m = ins.getMnemonicString().toUpperCase();
        if (m.equals("INT3") || m.equals("NOP")) return true;
        String s = ins.toString().replace(" ", "").toUpperCase();
        return s.matches("LEA(E..),\\[\\1(\\+0X0)?\\]") || s.matches("MOV(E..),\\1")
            || s.matches("LEA(E..),\\[\\1\\+EIZ\\*0X1(\\+0X0)?\\]");
    }

    @Override
    protected void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        int total = 0;
        for (int pass = 1;; ++pass) {
            TreeSet<Long> targets = new TreeSet<>();
            for (MemoryBlock block : mem.getBlocks()) {
                if (block.isExecute() || !block.isInitialized()) continue;
                Address start = block.getStart();
                long n = block.getSize() / 4;
                for (long k = 0; k < n && !monitor.isCancelled(); ++k) {
                    Address at = start.add(k * 4);
                    long v = mem.getInt(at) & 0xffffffffL;
                    Address t;
                    try { t = toAddr(v); } catch (Exception e) { continue; }
                    MemoryBlock tb = mem.getBlock(t);
                    if (tb == null || !tb.isExecute()) continue;
                    if (getFunctionContaining(t) != null) continue;
                    targets.add(v);
                }
            }
            InstructionIterator it = currentProgram.getListing().getInstructions(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Instruction ins = it.next();
                for (int op = 0; op < ins.getNumOperands(); ++op) {
                    Scalar s = ins.getScalar(op);
                    if (s == null) continue;
                    long v = s.getUnsignedValue() & 0xffffffffL;
                    Address t;
                    try { t = toAddr(v); } catch (Exception e) { continue; }
                    MemoryBlock tb = mem.getBlock(t);
                    if (tb != null && tb.isExecute() && getFunctionContaining(t) == null) targets.add(v);
                }
                if (getFunctionContaining(ins.getAddress()) == null) {
                    Instruction prev = ins.getPrevious();
                    if (prev != null && !prev.getAddress().add(prev.getLength()).equals(ins.getAddress())) prev = null;
                    String pm = prev == null ? "" : prev.getMnemonicString().toUpperCase();
                    boolean afterEnd = prev == null || pm.equals("RET") || isPadding(prev)
                        || (pm.equals("JMP") && getFunctionContaining(prev.getAddress()) != null);
                    if (afterEnd && !isPadding(ins)) targets.add(ins.getAddress().getOffset());
                }
            }
            int created = 0;
            for (long v : targets) {
                Address t = toAddr(v);
                if (getFunctionContaining(t) != null) continue;
                Instruction ins = getInstructionAt(t);
                if (ins == null) {
                    if (getInstructionContaining(t) != null) continue;  // lands inside an instruction: not code
                    new DisassembleCommand(t, null, true).applyTo(currentProgram, monitor);
                    if (getInstructionAt(t) == null) continue;
                }
                if (createFunction(t, null) != null) ++created;
            }
            println("pass " + pass + ": " + targets.size() + " targets, " + created + " functions created");
            total += created;
            if (created == 0) break;
        }
        println("created " + total + " functions");
    }
}
