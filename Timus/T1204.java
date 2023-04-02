import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    int[] simp = new int[5000];

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

        simp[0]=2;
        simp[1]=3;
        simp[2]=5;

        int cnt=3;
        for (int i=7; i<=40000; ++i){
            boolean good=true;
            int lim = (int)(Math.sqrt(i))+1;
            for (int j=0; j<cnt; ++j){
                if(simp[j]>=lim)
                    break;
                if(i%simp[j]==0){
                    good=false;
                    break;
                }
            }
            if(good)
                simp[cnt++]=i;
        }

        int n = Integer.parseInt(in.readLine());
        int[] v = new int[n];
        for (int i=0; i<n; ++i){
            v[i]=Integer.parseInt(in.readLine());
        }

        for (int i=0; i<n; ++i){
            int p=-1, q=-1;
            for (int j=0; j<cnt; ++j){
                if(v[i]%simp[j]==0){
                    p=simp[j];
                    q=v[i]/p;
                    break;
                }
            }
            out.print("0 1 ");
            if(p!=q){
                int[] pair = extEuclid(p,q);
                if(pair[0]<=q/2){
                    out.print(p*pair[0] + " " + (p*q-p*pair[0]+1));
                }
                else{
                    out.print((p*q-p*pair[0]+1) + " " + p*pair[0]);
                }
            }
            out.println();
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }

    private int[] extEuclid(int p, int q) {
        int[] res = new int[2];
        if (p==1){
            res[0]=1;
            res[1]=0;
            return res;
        }
        if (q==1){
            res[0]=1;
            res[1]=p-1;
            return res;
        }

        if (p>q){
            int[] tmp = extEuclid(p%q,q);
            res[0]=tmp[0];
            res[1]=(tmp[1]+tmp[0]*(p/q));
            return res;
        }
        if (q>p){
            int[] tmp=extEuclid(p,q%p);
            res[1]=tmp[1];
            res[0]=(tmp[0]+tmp[1]*(q/p));
            return res;
        }
        return res;
    }
}
