import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader in = new BufferedReader (new FileReader (new File("div396.in")));
        PrintWriter out = new PrintWriter ("div396.out");
        
        int n=Integer.parseInt(in.readLine());
        BigInteger ans = BigInteger.ZERO;
        int a=0;
        BigInteger n396 = BigInteger.valueOf(396);
        int pred=0, last=0;
        
        for (int i=0; i<n; ++i){
            BigInteger cur = new BigInteger (in.readLine());
            if(!cur.equals(BigInteger.ZERO) && cur.mod(n396).equals(BigInteger.ZERO)){
                int res=cur.compareTo(ans);
                if(res>0){
                    ans=cur;
                    pred=last=i+1;
                }
                else if(res==0){
                    ans = cur;
                    pred=last;
                    last=i+1;
                }
            }
        }
        out.println(pred);
        
        in.close();
        out.close();
    }
}
