// For every function of the current program, the most similar functions of the other programs in a BSim database
// (tools/names/bsim.sh): the pairs a function-level name transfer starts from.
//   postScript BSimPairs.java <bsim URL> <out.tsv> [similarity floor, default 0.5] [results per function, default 3]
// out.tsv, one line per candidate: our address, rank, similarity, significance, its executable, its address, its name
// (addresses hex, the other program's as BSim records it). Functions below BSim's own size floor are not asked.
//@category OpenBuilder

import java.io.PrintWriter;
import java.util.*;

import ghidra.app.script.GhidraScript;
import ghidra.features.bsim.query.description.FunctionDescription;
import ghidra.features.bsim.query.facade.*;
import ghidra.features.bsim.query.protocol.SimilarityNote;
import ghidra.features.bsim.query.protocol.SimilarityResult;
import ghidra.program.database.symbol.FunctionSymbol;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class BSimPairs extends GhidraScript {
	private static final int BATCH = 2000;

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length < 2) {
			printerr("usage: BSimPairs.java <bsim URL> <out.tsv> [similarity floor] [results per function]");
			return;
		}
		double floor = args.length > 2 ? Double.parseDouble(args[2]) : 0.5;
		int per = args.length > 3 ? Integer.parseInt(args[3]) : 3;
		String self = currentProgram.getExecutableMD5();

		List<FunctionSymbol> all = new ArrayList<>();
		FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
		while (it.hasNext()) {
			Function f = it.next();
			if (f.isThunk() || f.isExternal()) continue;
			all.add((FunctionSymbol) f.getSymbol());
		}
		int lines = 0, asked = 0;
		try (SimilarFunctionQueryService service = new SimilarFunctionQueryService(currentProgram);
				PrintWriter out = new PrintWriter(args[1])) {
			service.initializeDatabase(args[0]);
			for (int from = 0; from < all.size(); from += BATCH) {
				monitor.checkCancelled();
				Set<FunctionSymbol> batch = new HashSet<>(all.subList(from, Math.min(all.size(), from + BATCH)));
				SFQueryInfo info = new SFQueryInfo(batch);
				info.setMaximumResults(per + 1);  // one more: our own program may be in the database too
				info.setSimilarityThreshold(floor);
				info.setSignificanceThreshold(0.0);
				SFQueryResult result = service.querySimilarFunctions(info, null, monitor);
				for (SimilarityResult r : result.getSimilarityResults()) {
					++asked;
					int rank = 0;
					for (SimilarityNote n : r) {
						FunctionDescription d = n.getFunctionDescription();
						if (self.equals(d.getExecutableRecord().getMd5())) continue;
						if (++rank > per) break;
						out.printf("%x\t%d\t%.4f\t%.2f\t%s\t%x\t%s%n", r.getBase().getAddress(), rank,
							n.getSimilarity(), n.getSignificance(), d.getExecutableRecord().getNameExec(),
							d.getAddress(), d.getFunctionName());
						++lines;
					}
				}
				println(String.format("BSimPairs: %d of %d functions asked", Math.min(all.size(), from + BATCH), all.size()));
			}
		}
		println(String.format("BSimPairs: %d functions answered, %d candidate lines", asked, lines));
	}
}
