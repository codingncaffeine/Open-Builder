// Dump a Ghidra data type archive (.gdt) to TSV: every type, every structure field, every function definition.
// Usage: analyzeHeadless <proj-dir> <proj> -noanalysis -preScript ExportGdt.java <archive.gdt> <out-dir>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

public class ExportGdt extends GhidraScript {
    static String clean(String s) { return s == null ? "" : s.replace('\n', ' ').replace('\t', ' '); }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File gdt = new File(args[0]);
        File outDir = new File(args[1]);
        outDir.mkdirs();
        FileDataTypeManager dtm = FileDataTypeManager.openFileArchive(gdt, false);
        int n = 0;
        try (PrintWriter types = new PrintWriter(new FileWriter(new File(outDir, "types.tsv")));
             PrintWriter fields = new PrintWriter(new FileWriter(new File(outDir, "fields.tsv")));
             PrintWriter funcs = new PrintWriter(new FileWriter(new File(outDir, "funcdefs.tsv")))) {
            Iterator<DataType> it = dtm.getAllDataTypes();
            while (it.hasNext()) {
                DataType dt = it.next();
                n++;
                types.println(dt.getClass().getSimpleName() + "\t" + dt.getCategoryPath() + "\t" + dt.getName() + "\t"
                    + dt.getLength() + "\t" + clean(dt.getDescription()));
                if (dt instanceof Structure) {
                    Structure s = (Structure) dt;
                    for (DataTypeComponent c : s.getDefinedComponents()) {
                        fields.println(dt.getCategoryPath() + "\t" + dt.getName() + "\t" + Integer.toHexString(c.getOffset())
                            + "\t" + c.getLength() + "\t" + c.getDataType().getName() + "\t" + clean(c.getFieldName())
                            + "\t" + clean(c.getComment()));
                    }
                } else if (dt instanceof FunctionDefinition) {
                    FunctionDefinition f = (FunctionDefinition) dt;
                    funcs.println(dt.getCategoryPath() + "\t" + dt.getName() + "\t" + f.getPrototypeString() + "\t"
                        + f.getCallingConventionName());
                }
            }
        } finally {
            dtm.close();
        }
        println("ExportGdt: " + n + " types -> " + outDir);
    }
}
