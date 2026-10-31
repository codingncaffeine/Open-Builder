// Writes every function of the analysed program as one line "<entry> <size> <name> <source>" (hex entry and
// size), to the file given as the script argument. Size is the contiguous run of the body that starts at the
// entry, which is what the compare tools read; functions whose body has more pieces are marked "split", one-jump
// functions (thunks to the analyser) "thunk".
//
//   analyzeHeadless <project dir> <project> -process <program> -noanalysis -readOnly \
//       -scriptPath tools/ghidra -postScript ExportFunctions.java <out.tsv>
//@category OpenCityBuilder

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

import java.io.PrintWriter;

public class ExportFunctions extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("usage: ExportFunctions.java <out.tsv>");
        int count = 0;
        try (PrintWriter out = new PrintWriter(args[0])) {
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Function f = it.next();
                // A thunk to the analyser is a function whose body is one jump: real code (a one-line override that
                // forwards, compiled as a tail jump), marked as such.
                if (f.isExternal()) continue;
                AddressRange first = f.getBody().getRangeContaining(f.getEntryPoint());
                if (first == null) continue;
                String source = f.isThunk() ? "thunk" : f.getBody().getNumAddressRanges() > 1 ? "split" : "whole";
                out.printf("%08x %x %s %s%n", f.getEntryPoint().getOffset(), first.getLength(), f.getName(), source);
                ++count;
            }
        }
        println("exported " + count + " functions to " + args[0]);
    }
}
