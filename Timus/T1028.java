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

        int n = Integer.parseInt(in.readLine());
        int[] f = new int[32010];
        int ans[] = new int[n];

        for (int i=0; i<n; ++i){
            int x = Integer.parseInt(in.readLine().split("\\s")[0]);
            int k = x;
            int lev=0;
            while(k>=0){
                lev+=f[k];
                k=(k&(k+1))-1;
            }
            ans[lev]++;
            k = x;
            while(k<f.length){
                f[k]++;
                k=k|(k+1);
            }
        }
        for (int i=0; i<n; ++i){
            out.println(ans[i]);
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
