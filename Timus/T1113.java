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
    void run() throws Exception{
        init2();

        long a=0;
        double o=0,w=0,d=0;

        String[] res = in.readLine().split("\\s");
        long n = Long.parseLong(res[0]);
        long m = Long.parseLong(res[1]);

        for(;;){
            a++;
            d = (double)m/(double)(a*2-1);
            if(w+(double)d>=n)
                break;
            w+=d;
            o+=m;
        }

        d = (double)(n)-w;
        o+=d*(a*2-1);
        out.println((int)(o+0.99999999));

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
