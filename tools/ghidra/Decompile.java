// Prints Ghidra's decompilation of the function containing each address given as a script argument, creating the
// function first when analysis did not (functions reached only through a vtable). Output goes to stdout as
// "=== <address> <name>" followed by the C text.
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis \
//       -scriptPath tools/ghidra -postScript Decompile.java <hexaddr> [hexaddr ...]
//@category OpenBuilder

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class Decompile extends GhidraScript {
    @Override
    protected void run() throws Exception {
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        try {
            for (String arg : getScriptArgs()) {
                Address a = toAddr(Long.parseLong(arg.replaceFirst("^0x", ""), 16));
                Function f = getFunctionContaining(a);
                if (f == null) {
                    disassemble(a);
                    f = createFunction(a, null);
                }
                if (f == null) {
                    println("=== " + arg + ": no function could be made here");
                    continue;
                }
                DecompileResults r = dec.decompileFunction(f, 120, monitor);
                if (!r.decompileCompleted()) {
                    println("=== " + arg + " " + f.getName() + ": " + r.getErrorMessage());
                    continue;
                }
                System.out.println("=== " + f.getEntryPoint() + " " + f.getName() + " (asked " + arg + ")");
                System.out.println(r.getDecompiledFunction().getC());
            }
        } finally {
            dec.dispose();
        }
    }
}
