import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	public static BigInteger sqrt(BigInteger num) {
		if(num.equals(BigInteger.ONE)) return BigInteger.ONE;
		BigInteger low = BigInteger.ONE, high = num;
		while(low.compareTo(high) <= 0) {
			BigInteger mid = low.add(high).divide(new BigInteger("2"));
			if(mid.multiply(mid).compareTo(num) < 0) {
				low = mid.add(BigInteger.ONE);
			}
			else {
				high = mid.subtract(BigInteger.ONE);
			}

		}
		if(!low.multiply(low).equals(num))
			low = low.subtract(BigInteger.ONE);

		return low.multiply(low);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder("");
		String all;
		while((all = bf.readLine()) != null && !all.equals("0")) {
			BigInteger num = new BigInteger(all);
			BigInteger ans = sqrt(num);
			out.append(ans.toString());
			out.append('\n');
		}
		System.out.print(out);
	}
}
