import java.io.*;
import java.math.BigInteger;
import java.util.*;

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

        arr = new BigInteger[2010];

        int i1 = Integer.parseInt(res[0])+1000;
        int F1 = Integer.parseInt(res[1]);
        int i2 = Integer.parseInt(res[2])+1000;
        int F2 = Integer.parseInt(res[3]);
        int n = Integer.parseInt(res[4])+1000;

        if(i2<i1){
            int tmp = i2;
            i2 = i1;
            i1 = tmp;
            tmp = F2;
            F2 = F1;
            F1 = tmp;
        }

        arr[i1] = BigInteger.valueOf(F1);
        arr[i2] = BigInteger.valueOf(F2);

        if(i2==i1+1){
            if(n<i1){
                for (int i=i1-1; i>=n; --i){
                    arr[i] = arr[i+2].subtract(arr[i+1]);
                }
                out.println(arr[n]);
                out.close();
                return;
            }else{
                for (int i=i2+1; i<=n; ++i){
                    arr[i] = arr[i-2].add(arr[i-1]);
                }
                out.println(arr[n]);
                out.close();
                return;                
            }
        }

        long R = 2000000000;
        long L = -2000000000;

        while(L<=R){
            long mid = (L+R)/2;
            arr[i1+1] = BigInteger.valueOf(mid);
            for (int i=i1+2; i<i2; ++i){
                arr[i] = arr[i-1].add(arr[i-2]);
            }
            BigInteger cand = arr[i2-1].add(arr[i2-2]);
            int q = arr[i2].compareTo(cand);
            if(q==0){
                if(n<i1){
                    for (int i=i1-1; i>=n; --i){
                        arr[i] = arr[i+2].subtract(arr[i+1]);
                    }
                    out.println(arr[n]);
                    out.close();
                    return;
                }else{
                    for (int i=i2+1; i<=n; ++i){
                        arr[i] = arr[i-2].add(arr[i-1]);
                    }
                    out.println(arr[n]);
                    out.close();
                    return;
                }
            }else if (q>0){
                L = mid+1;
            }else{
                R = mid-1;
            }
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
