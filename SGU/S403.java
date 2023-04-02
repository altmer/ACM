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
/*
        for (int x=1; x<=10; ++x){
            boolean fin = false;
            int num=0;
            while(!fin){
                num++;
                int sum=0;
                for (int i=1; i<num; ++i) sum+=i;
                if(sum>0 && sum%num==0 && sum/num==x) fin=true;
            }
            out.println(num);
        }
*/
        
        int x = Integer.parseInt(in.readLine().trim());

        out.println((x-1)*2+3);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
