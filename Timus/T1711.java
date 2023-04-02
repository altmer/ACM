import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    String[][] names;
    int[] orders;
    String[] ans;

    boolean fits(String s, int pos){
        if (ans[pos] != null && ans[pos].compareTo(s) < 0)
            return false;

        for (int i = 0; i < pos; ++i){
            if (ans[i].compareTo(s) > 0)
                return false;
        }

        return true;
    }

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

        int n = Integer.parseInt(in.readLine().trim());

        names = new String[n][];
        orders = new int[n];
        ans = new String[n];
        
        for (int i = 0; i < n; ++i){
            names[i] = in.readLine().split("\\s");
        }

        String[] res = in.readLine().split("\\s");

        for (int i = 0; i < n; ++i)
            orders[i] = Integer.parseInt(res[i]);

        for (int i = 0; i < n; ++i){
            int j = orders[i] - 1;
            for (int k = 0; k < names[j].length; ++k){
                 if(fits(names[j][k], i))
                     ans[i] = names[j][k];
                 }

                 if(ans[i] == null){
                     out.println("IMPOSSIBLE");
                     out.close();
                     return;
                 }
        }
        for (int i = 0; i<n; ++i)
            out.println(ans[i]);

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
