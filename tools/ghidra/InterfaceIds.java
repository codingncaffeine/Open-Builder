// For every vtable (tools/ghidra/Vtables.java output), reads slot 0, the QueryInterface of the engine's COM-style
// classes, and lists the interface IDs it compares against: named from an ID table where known ("<hex> <name>" per
// line), as hex otherwise. Writes "<vtable> <slots> <names or ids, comma-separated>" per vtable whose slot 0
// compares at least one 32-bit constant, to the output file.
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis -readOnly \
//       -scriptPath tools/ghidra -postScript InterfaceIds.java <ids.txt> <vtables.tsv> <out.tsv>
//@category OpenCityBuilder

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.scalar.Scalar;

import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;

public class InterfaceIds extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) throw new IllegalArgumentException("usage: InterfaceIds.java <ids> <vtables> <out>");
        Map<Long, String> names = new HashMap<>();
        for (String line : Files.readAllLines(Path.of(args[0]))) {
            String[] p = line.trim().split("\\s+");
            if (p.length == 2) names.putIfAbsent(Long.parseLong(p[0], 16), p[1]);
        }
        int withIds = 0, named = 0;
        try (PrintWriter out = new PrintWriter(args[2])) {
            for (String line : Files.readAllLines(Path.of(args[1]))) {
                String[] p = line.split(" ");
                if (p.length < 4) continue;
                long slot0 = Long.parseLong(p[3].split(",")[0], 16);
                Function f = getFunctionAt(toAddr(slot0));
                if (f == null) continue;
                LinkedHashSet<String> ids = new LinkedHashSet<>();
                boolean anyNamed = false;
                for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                    if (!ins.getMnemonicString().equalsIgnoreCase("CMP")) continue;
                    Scalar s = ins.getScalar(1);
                    if (s == null || s.bitLength() < 16) continue;
                    long v = s.getUnsignedValue() & 0xffffffffL;
                    if (v < 0x10000) continue;
                    String n = names.get(v);
                    anyNamed |= n != null;
                    ids.add(n != null ? n : String.format("%08x", v));
                }
                if (ids.isEmpty()) continue;
                ++withIds;
                if (anyNamed) ++named;
                out.printf("%s %s %s%n", p[0], p[1], String.join(",", ids));
            }
        }
        println(withIds + " vtables compare interface IDs in slot 0, " + named + " of them with a known name");
    }
}
