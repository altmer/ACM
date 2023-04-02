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
    long gcd (long a, long b){
        while(a>0){
            long tmp=b%a;
            b=a;
            a=tmp;
        }
        return b;
    }
    void run() throws Exception{
        init2();

        String[] res = in.readLine().split("\\s");
        long p = Long.parseLong(res[0]);
        long q = Long.parseLong(res[1]);
        long d = gcd(p,q);
        res = in.readLine().split("\\s");
        long x1 = Long.parseLong(res[0]);
        long y1 = Long.parseLong(res[1]);
        res = in.readLine().split("\\s");
        long x2 = Long.parseLong(res[0]);
        long y2 = Long.parseLong(res[1]);
        long m = Math.abs(x2-x1);
        long n = Math.abs(y2-y1);
        if(m%d>0 || n%d>0){
            out.println("NO");
        }
        else{
            m/=d;
            n/=d;
            p/=d;
            q/=d;
            if((p%2)+(q%2)==1){
                out.println("YES");
            }
            else if((m+n)%2==0){
                out.println("YES");
            }
            else{
                out.println("NO");
            }
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
