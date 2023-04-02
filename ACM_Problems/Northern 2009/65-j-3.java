import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;


public class Main {
	BufferedReader in;
	PrintWriter out;
	
	public void run()throws Exception{
		in = new BufferedReader(new FileReader(new File("jealous.in")));
		out = new PrintWriter(new File("jealous.out"));
		
		BigInteger a, b, p, q;
		
		String[] res = in.readLine().split("\\s");
		
		a = new BigInteger(res[0]);
		b = new BigInteger(res[1]);
		p = new BigInteger(res[2]);
		q = new BigInteger(res[3]);
		
		BigInteger PQ = p;
		BigInteger ans = new BigInteger("0");
		BigInteger big = new BigInteger("1000000000000000000");
	
		for (int k = 0; PQ.compareTo(big) <= 0; k++, PQ = p.pow(k+1).multiply(q.pow(k))){
		
			BigInteger minC = a.divide(PQ);
			if(a.mod(PQ).compareTo(BigInteger.ZERO) > 0)
				minC = minC.add(BigInteger.ONE);
			
			BigInteger maxC = b.divide(PQ); 
			
			BigInteger dif = maxC.subtract(minC).add(BigInteger.ONE);
			BigInteger n = maxC.divide(q).subtract(minC.subtract(BigInteger.ONE).divide(q));
			
			if(dif.compareTo(BigInteger.ZERO) > 0){
				ans = ans.add(dif);
				if(n.compareTo(BigInteger.ZERO) > 0){
					ans = ans.subtract(n);
				}
			}
		}
		
		out.println(ans);
		
		in.close();
		out.close();
	}
	public static void main(String[] args)throws Exception{
		new Main().run();
	}
}
