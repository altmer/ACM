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
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        String[] res = in.readLine().split("\\s");
        long n = Long.parseLong(res[0]);
        n*=3;
        int m = Integer.parseInt(res[1]);
        long cur=0;
        int ans=-1;
        for (int i=0; i<m; ++i){
            cur+=Integer.parseInt(in.readLine());
            if(cur>n && ans==-1){
                ans=i+1;
            }
        }

        if(ans!=-1)
            out.println("Free after "+ans+" times.");
        else
            out.println("Team.GOV!");

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
