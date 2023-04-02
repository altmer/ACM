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

        String[] res = in.readLine().trim().split("\\s");

        int n = Integer.parseInt(res[0]);
        int m = Integer.parseInt(res[1]);

        GregorianCalendar cal = new GregorianCalendar();
        cal.set(2001, m-1, 1);
        if(m>12 || n>cal.getActualMaximum(cal.DAY_OF_MONTH)){
            out.println("Impossible");
        }else{
            cal.set(cal.DAY_OF_MONTH, n);
            if(cal.get(cal.DAY_OF_WEEK)==1){
                out.println(7);
            }else{
                out.println(cal.get(cal.DAY_OF_WEEK)-1);
            }
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
