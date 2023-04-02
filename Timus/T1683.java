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

        int n = Integer.parseInt(in.readLine());
        int[] ans = new int[400];
        int ptr=0;
        while(n>1){
            ans[ptr++]=n/2;
            n-=n/2;
        }
        out.println(ptr);
        for (int i=0; i<ptr; ++i){
            out.print(ans[i]);
            out.print(" ");
        }
        out.println();

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
