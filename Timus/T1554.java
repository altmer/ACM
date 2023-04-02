import java.io.*;
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

    int extEuclid(int a, int b, int[] xy){
        if(a==0){
            xy[0]=0;
            xy[1]=1;
            return b;
        }
        int[] res = new int[2];
        int d = extEuclid(b%a, a, res);
        xy[0] = res[1] - (b/a)*res[0];
        xy[1] = res[0];
        return d;
    }
    
    void run() throws Exception{
        init2();

        int n = Integer.parseInt(in.readLine());
        String[] res = in.readLine().split("\\s");
        int[] F = new int[n];
        int[] G = new int[n];
        for (int i=0; i<n; ++i){
            F[i] = Integer.parseInt(res[i]);
        }

        for (int i=1; i<=n; ++i){
            int sum = 0;
            for (int j=2; j*j<=i; ++j){
                if(i%j==0){
                    sum = (sum + F[j-1]*G[i/j-1])%2007;
                    if(j*j!=i)
                        sum = (sum + F[i/j-1]*G[j-1])%2007;
                }
            }
            if(i!=1){
                sum= (sum + F[i-1]*G[0])%2007;
            }
            if(sum==0)
                sum=2007;
            int[] ans = new int[2];
            int gcd = extEuclid(F[0],2007,ans);
            G[i-1] = i==1 ? ans[0]/gcd : ans[0]*(2007-sum)/gcd;
        }

        for (int i=0; i<n; ++i){
            out.print(G[i]);
            out.print(" ");
        }
        out.println();

        in.close();
        out.close();
    }
    
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
