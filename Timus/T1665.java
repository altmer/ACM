import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    void run()throws Exception{
        /*
        in = new BufferedReader (new FileReader (new File("input.txt")));
        out = new PrintWriter (new File("output.txt"));
        */
        
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out);
        

        int n = Integer.parseInt(in.readLine());
        for (int i=0; i<n; ++i){
            out.println(f(Integer.parseInt(in.readLine()))? "YES" : "NO");
        }

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }

    private boolean f(int n) {
        int num=0;
        int nech=0;
        while(n%2==0){
            n/=2;
            num++;
        }
        int x=3;
        while(x<=Math.sqrt((double)n)){
            while(n%x==0){
                ++nech;
                n/=x;
            }
            x+=2;
        }
        if(n>1)
            nech++;
        return nech > 1 || (num+nech+1)%2==0;
    }
}
