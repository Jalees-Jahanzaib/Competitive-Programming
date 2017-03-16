import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated constructor stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		
		int t = Integer.parseInt(in.readLine());
		while(t-- > 0) {
			String[] data = in.readLine().split(" ");
			BigInteger a = new BigInteger(data[0]);
			BigInteger res = new BigInteger(data[1]);
			BigInteger pot = BigInteger.ONE;
			for(int i = 0;; i++) {
				if(pot.equals(res)) {
					out.append(i+"\n");
					break;
				}
				pot = pot.multiply(a);
			}
		}
		System.out.print(out);
	}
}
