import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;

    int[] primes;
    int ptr;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    boolean isPrime(int x){
        int lim = (int)Math.sqrt((double)x)+1;
        for (int j=0; j<ptr && primes[j]<lim; ++j){
            if(x%primes[j]==0){
                return false;
            }
        }
        return true;
    }

    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        int num=32000;
        boolean notprime[] = new boolean[num];
        primes = new int[num];
        ptr=0;

        notprime[1]=true;
        for (int i=2; i<num; ++i){
            if(!notprime[i]){
                primes[ptr++]=i;
                int k= i<<1;
                while(k<num){
                    notprime[k]=true;
                    k+=i;
                }
            }
        }

        int[] inp = new int[100];
        int cur=0;
        String[] res = in.readLine().trim().split("\\s");
        int n = Integer.parseInt(res[0]);
        for (int i=1; i<res.length; ++i){
            if(!res[i].isEmpty())
                inp[cur++] = Integer.parseInt(res[i]);
        }
        while(cur<n){
            res = in.readLine().trim().split("\\s");
            for (int i=0; i<res.length; ++i){
                if(!res[i].isEmpty())
                    inp[cur++] = Integer.parseInt(res[i]);
            }
        }

        for (int i=0; i<n; ++i){
            int x = inp[i];
            int lim = (int)Math.sqrt((double)x)+1;
            boolean good = false;
            for (int j=0; j<ptr && primes[j]<lim; ++j){
                if(x%primes[j]==0 && isPrime(x/primes[j])){
                    out.println("Yes");
                    good=true;
                    break;
                }
            }
            if(!good)
                out.println("No");
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
