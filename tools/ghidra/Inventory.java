// Prints the function inventory of the analysed program: totals, how Ghidra named them (analysis default,
// Function ID library match, imported, thunk), code bytes per group, and, for each address given as a script
// argument, the containing function and its callers.
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis -readOnly \
//       -scriptPath tools/ghidra -postScript Inventory.java [hexaddr ...]
//@category OpenCityBuilder

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.SourceType;

import java.util.Map;
import java.util.TreeMap;

public class Inventory extends GhidraScript {
    @Override
    protected void run() throws Exception {
        Map<String, long[]> groups = new TreeMap<>();
        long total = 0, bytes = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            String group;
            if (f.isExternal()) group = "external";
            else if (f.isThunk()) group = "thunk";
            else if (f.getSymbol().getSource() == SourceType.DEFAULT) group = "unnamed";
            else if (f.getSymbol().getSource() == SourceType.ANALYSIS) group = "named-by-analysis";
            else group = "named-" + f.getSymbol().getSource().toString().toLowerCase();
            long size = f.isExternal() ? 0 : f.getBody().getNumAddresses();
            long[] g = groups.computeIfAbsent(group, k -> new long[2]);
            g[0]++;
            g[1] += size;
            total++;
            bytes += size;
        }
        println(String.format("functions %d, bytes in function bodies %d", total, bytes));
        for (Map.Entry<String, long[]> e : groups.entrySet())
            println(String.format("  %-22s %7d functions %9d bytes", e.getKey(), e.getValue()[0], e.getValue()[1]));

        for (String arg : getScriptArgs()) {
            Address a = toAddr(Long.parseLong(arg.replaceFirst("^0x", ""), 16));
            Function f = getFunctionContaining(a);
            if (f == null) { println(arg + ": no function"); continue; }
            println(String.format("%s: in %s @ %s (%d bytes)", arg, f.getName(), f.getEntryPoint(),
                    f.getBody().getNumAddresses()));
            for (Function caller : f.getCallingFunctions(monitor))
                println("    called from " + caller.getName() + " @ " + caller.getEntryPoint());
        }
    }
}
