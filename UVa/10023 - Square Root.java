import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader in = new BufferedReader(new FileInputStream(new File("input.txt")));
		StringBuilder out = new StringBuilder("");
		int n = Integer.parseInt(in.readLine());
		
		for(int k = 0; k < n; k++) {
			if(k > 0) out.append('\n');
			in.readLine();
			String original = in.readLine();
			BigInteger number = new BigInteger(original);
			BigInteger high = (new BigInteger("10")).pow(original.length()/2+1);
			BigInteger low = (new BigInteger("10")).pow(Math.max(0, original.length()/2-1));
			
			while(low.compareTo(high) <= 0) {
				BigInteger mid = high.add(low).divide(new BigInteger("2"));
				if(mid.multiply(mid).compareTo(number) <= 0)
					low = mid.add(BigInteger.ONE);
				else 
					high = mid.subtract(BigInteger.ONE);
			}
			out.append(high.toString() + "\n");
		}
		System.out.print(out);
	}
}
