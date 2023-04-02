import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    class Segm implements Comparable<Segm>{
        int l, r;
        Segm(){l=r=-1;}
        Segm(int a, int b) {l=a; r=b;}

        public int compareTo(Segm o) {
            return this.l-o.l;
        }
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
        init2();

        int n = Integer.parseInt(in.readLine());
        Segm[] v = new Segm[n];

        for (int i=0; i<n; ++i){
            String[] res = in.readLine().split("\\s");
            v[i] = new Segm(Integer.parseInt(res[0]),Integer.parseInt(res[1]));
        }

        Arrays.sort(v);
        Segm cur = new Segm();
        int ans=0;
        for (Segm next : v){
            if(next.l>cur.r){
                ++ans;
                cur=next;
            }
            else if(next.r<cur.r){
                cur=next;
            }
        }

        out.println(ans);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
