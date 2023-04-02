import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    char[] arr, ans;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    void rec (int l, int r, int ind){
        if(l>r) return;
        int mid = (r+l)/2;
        ans[mid]=arr[ind];
        rec(l, mid-1, ind+1);
        rec(mid+1, r, ind+mid-l+1);
    }

    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        arr = in.readLine().toCharArray();
        ans = new char[arr.length];

        rec(0, arr.length-1, 0);
        out.println(ans);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
