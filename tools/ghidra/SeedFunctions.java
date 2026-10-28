// Pre-script: disassembles and creates a function at every hex address listed in the file given as the script
// argument (one per line), so analysis also finds functions nothing calls, such as a library's public API.
//
//   analyzeHeadless ... -import <binary> -scriptPath tools/ghidra -preScript SeedFunctions.java <addresses.txt>
//@category OpenBuilder

import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

import java.nio.file.Files;
import java.nio.file.Path;

public class SeedFunctions extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("usage: SeedFunctions.java <addresses.txt>");
        int created = 0;
        for (String line : Files.readAllLines(Path.of(args[0]))) {
            line = line.trim();
            if (line.isEmpty()) continue;
            Address a = toAddr(Long.parseLong(line, 16));
            new DisassembleCommand(a, null, true).applyTo(currentProgram, monitor);
            if (getFunctionAt(a) == null && createFunction(a, null) != null) ++created;
        }
        println("seeded " + created + " functions");
    }
}
