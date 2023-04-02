import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
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

    BigInteger pow(BigInteger x, int p){
        BigInteger ret = BigInteger.ONE;
        while(p>0){
            if((p&1)==1){
                ret = ret.multiply(x);
                p--;
            }else{
                x = x.multiply(x);
                p/=2;
            }
        }
        return ret;
    }

    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        String inp[] = in.readLine().trim().split("\\s");

        BigInteger a = new BigInteger(inp[0]);
        BigInteger b = new BigInteger(inp[1]);

        int s1=a.intValue();
        int s2=b.intValue();
        a = pow(a, s2);
        b = pow(b,s1);
        

        out.println(a.subtract(b));

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
