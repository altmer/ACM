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

        char[] str = in.readLine().toCharArray();
        int n = str.length;
        int[] p = new int[n], pn = new int[n], cnt = new int[10000], c = new int[n], cn = new int[n];

        for (int i=0; i<n; ++i){
            cnt[str[i]-'a']++;
        }
        for (int i='b'; i<='z'; ++i){
            cnt[i-'a']+=cnt[i-'a'-1];
        }
        for (int i=0; i<n; ++i){
            p[--cnt[str[i]-'a']]=i;
        }
        c[p[0]]=0;
        int classes=1;
        for (int i=1; i<n; ++i){
            if(str[p[i]]!=str[p[i-1]]) ++classes;
            c[p[i]]=classes-1;
        }
        
        for (int k=0; (1<<k)<n; ++k){
            for (int i=0; i<n; ++i){
                pn[i] = p[i]-(1<<k);
                if(pn[i]<0) pn[i]+=n;
            }

            Arrays.fill(cnt, 0);
            for (int i=0; i<n; ++i){
                ++cnt[c[pn[i]]];
            }
            for (int i=1; i<classes; ++i){
                cnt[i]+=cnt[i-1];
            }
            for (int i=n-1; i>=0; --i){
                p[--cnt[c[pn[i]]]]=pn[i];
            }
            cn[p[0]]=0;
            classes=1;
            for (int i=1; i<n; ++i){
                int pos1 = p[i]+(1<<k), pos2=p[i-1]+(1<<k);
                if(pos1>=n) pos1-=n;
                if(pos2>=n) pos2-=n;
                if(c[p[i]]!=c[p[i-1]] || c[pos1]!=c[pos2]) ++classes;
                cn[p[i]]=classes-1;
            }
            c=cn;
        }

        for (int i=p[0]; i<p[0]+n; ++i){
            out.print(str[i%n]);
        }
        out.println();

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
