import java.io.*;
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

    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        String res[] = in.readLine().trim().split("\\s");
        int n = Integer.parseInt(res[0]);
        int m = Integer.parseInt(res[1]);
        int ind = 0;

        if(n%m==0) ind=m-1;
        else ind = n%m-1;

        String s = "";
        for (int i=0; i<=ind; ++i){
            s = in.readLine().trim();
        }
        
        out.println(s);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
