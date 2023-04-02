import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    BigInteger arr[];

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }

    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        String[] res = in.readLine().trim().split("\\s");
        
        int n = Integer.parseInt(res[0]);
        int k = Integer.parseInt(res[1]);

        if(k==0){
            out.println(1);
            out.close();
            return;
        }

        arr = new BigInteger[n+3];
        
        arr[0] = BigInteger.ZERO;
        arr[1] = BigInteger.ONE;
        arr[2] = BigInteger.ONE;
        BigInteger two = BigInteger.valueOf(2);

        for (int i=3; i<k+2; ++i){
            arr[i] = arr[i-1].multiply(two);
        }

        for (int i=k+2; i<=n+2; ++i){
            arr[i] = arr[i-1].multiply(two).subtract(arr[i-2-k]);
        }

        out.println(arr[n+2]);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
