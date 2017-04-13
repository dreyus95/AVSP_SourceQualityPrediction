import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class aEasy {
	
	private static final long MAX = (int)Math.pow(2, 40);

	public static void main(String[] args) throws IOException {

		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamR1B/src/A-large (1).in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamR1B/src/test.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		System.setOut(new PrintStream(fileOut));

		String line;
		int testCase = 1;

		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue;
			}
			String[] temp = input[0].split("/");
			calculate(Long.valueOf(temp[0]).longValue(), Long.valueOf(temp[1]).longValue(), testCase);
			testCase++;
		}

	}

	private static void calculate(long p, long q, int testCase) {
		if (!check(p, q)) {
			System.out.println("Case #" + testCase + ": impossible");
			return;
		}
		for (int i = 1; i < 41; i++) {
			if (p * Math.pow(2, i) >= q) {
				System.out.println("Case #" + testCase + ": " + i);
				return;
			}
		}
	}

	private static boolean check(long p, long q) {
		for (int i = 0; i < 41; i++) {
			if (p * Math.pow(2, i) % q == 0) {
				return true;
			}
		}
		return false;
	}


}
