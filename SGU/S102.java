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

    int phi(int n){
        int res=n;
        for (int i=2; i*i<=n; ++i){
            if(n%i==0){
                while(n%i==0)
                    n/=i;
                res-=res/i;
            }
        }
        if(n>1) res-=res/n;
        return res;
    }

    void run() throws Exception{
        init2();

        int n = Integer.parseInt(in.readLine());
        out.println(phi(n));

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
