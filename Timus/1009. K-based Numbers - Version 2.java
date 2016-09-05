import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

	static BigInteger[][] dp = new BigInteger[1800][2];
	static int k;

	static BigInteger go(int n, int zero) {
		BigInteger r = dp[n][zero];
	    if(!r.equals(new BigInteger("-1"))) return r;
	    if(n == 0) return dp[n][zero] = BigInteger.ONE;
	    r = BigInteger.ZERO;
	    for(int i = 1-zero; i < k; i++) {
	        if(i == 0) r = r.add(go(n-1, 0));
	        else r = r.add(go(n-1, 1));
	    }
	    return dp[n][zero] = r;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder cout = new StringBuilder("");

		for(int i = 0; i < 1800; i++) {
			dp[i][0] = new BigInteger("-1");
			dp[i][1] = new BigInteger("-1");
		}

		int n = Integer.parseInt(cin.readLine());
		k = Integer.parseInt(cin.readLine());
		cout.append(go(n, 0).toString());
		System.out.print(cout);


	}
}

