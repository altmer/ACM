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
        init2();

        String s;
        while((s=in.readLine()).isEmpty());
        int n = Integer.parseInt(s.trim());
        out.println((n/3)*2 + ((n%3==0 ||n%3==1) ? 0 : 1));
 
        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
