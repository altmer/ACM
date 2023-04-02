import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
    void run() throws Exception{
        init2();

        BigInteger four = new BigInteger("4");
        BigInteger two = new BigInteger("2");
        BigInteger cur = new BigInteger("1");
        int n = Integer.parseInt(in.readLine());
        
        for (int i=1; i<2*n; ++i){
            out.println(cur);
            cur = cur.multiply(BigInteger.valueOf(i).multiply(four).add(two)).divide(BigInteger.valueOf(i).add(two));
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
