// Accounts for every byte of the executable blocks: inside a function body, an instruction outside any function,
// defined data, alignment padding (int3 / multi-byte nops between functions), or undefined. Prints the totals and
// the largest stretches outside functions, so the function inventory can be driven to 100%.
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis -readOnly \
//       -scriptPath tools/ghidra -postScript Coverage.java [gaps to list, default 20]
//@category OpenBuilder

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;

import java.util.ArrayList;
import java.util.List;

public class Coverage extends GhidraScript {
    record Gap(long start, long length, String kind) {}

    private static boolean isPadding(Instruction ins) {
        String m = ins.getMnemonicString().toUpperCase();
        if (m.equals("INT3") || m.equals("NOP")) return true;
        // lea r,[r+0] and mov r,r: the multi-byte nops another compiler pads with
        String s = ins.toString().replace(" ", "").toUpperCase();
        return s.matches("LEA(E..),\\[\\1(\\+0X0)?\\]") || s.matches("MOV(E..),\\1")
            || s.matches("LEA(E..),\\[\\1\\+EIZ\\*0X1(\\+0X0)?\\]");
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        int listGaps = args.length > 0 ? Integer.parseInt(args[0]) : 20;
        long inFunction = 0, looseCode = 0, data = 0, padding = 0, undefined = 0;
        List<Gap> gaps = new ArrayList<>();
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            if (!block.isExecute() || !block.isInitialized()) continue;
            Address a = block.getStart();
            Address end = block.getEnd();
            long gapStart = -1, gapLen = 0;
            String gapKind = "";
            while (a.compareTo(end) <= 0 && !monitor.isCancelled()) {
                CodeUnit cu = currentProgram.getListing().getCodeUnitAt(a);
                long len = cu != null ? cu.getLength() : 1;
                String kind;
                if (getFunctionContaining(a) != null) kind = null;
                else if (cu instanceof Instruction ins) kind = isPadding(ins) ? "pad" : "code";
                else if (cu instanceof Data d && d.isDefined()) kind = "data";
                else {
                    byte b = getByte(a);
                    kind = (b == (byte) 0xCC || b == (byte) 0x90) ? "pad" : "undefined";
                }
                if (kind == null) inFunction += len;
                else switch (kind) {
                    case "code" -> looseCode += len;
                    case "data" -> data += len;
                    case "pad" -> padding += len;
                    default -> undefined += len;
                }
                boolean gap = kind != null && !kind.equals("pad");
                if (gap) {
                    if (gapStart < 0) { gapStart = a.getOffset(); gapLen = 0; gapKind = kind; }
                    gapLen += len;
                    if (!gapKind.contains(kind)) gapKind += "+" + kind;
                } else if (gapStart >= 0) {
                    gaps.add(new Gap(gapStart, gapLen, gapKind));
                    gapStart = -1;
                }
                a = a.add(len);
            }
            if (gapStart >= 0) gaps.add(new Gap(gapStart, gapLen, gapKind));
        }
        long total = inFunction + looseCode + data + padding + undefined;
        println(String.format("executable bytes %d: in functions %.2f%%, code outside functions %.2f%%, data %.2f%%,"
                + " padding %.2f%%, undefined %.2f%%", total, 100.0 * inFunction / total, 100.0 * looseCode / total,
                100.0 * data / total, 100.0 * padding / total, 100.0 * undefined / total));
        gaps.sort((x, y) -> Long.compare(y.length(), x.length()));
        long gapBytes = 0;
        for (Gap g : gaps) gapBytes += g.length();
        println(gaps.size() + " stretches outside functions (" + gapBytes + " bytes); largest:");
        for (int i = 0; i < Math.min(listGaps, gaps.size()); ++i)
            println(String.format("  %08x %6d bytes  %s", gaps.get(i).start(), gaps.get(i).length(), gaps.get(i).kind()));
    }
}
