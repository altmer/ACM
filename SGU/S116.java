import java.io.*;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;
    boolean[] sieve = new boolean[10005];
    int[] prime = new int[2000];
    int p=0;
    int[] sprime = new int[300];
    int sp=0;
    int[] ans;
    int cans = 0;
    boolean can[] = new boolean[10004];
    int [] par = new int[10004];
    int[] dist = new int[10004];

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

        sieve[0]=sieve[1]=true;
        for (int i=2; i<=10000; ++i){
            if(!sieve[i]){
                int k=2*i;
                while(k<=10000){
                    sieve[k]=true;
                    k+=i;
                }
            }
        }

        for (int i=2; i<=10000; ++i){
            if(!sieve[i]){
                prime[p++]=i;
            }
        }

        for (int i=0; i<p; ++i){
            if(!sieve[i+1]){
                sprime[sp++]=prime[i];
            }
        }

        int n = Integer.parseInt(in.readLine().trim());

        can[0]=true;
        dist[0]=0;
        par[0]=-1;

        for (int i=0; i<n; ++i){
            if(can[i]){
                for (int j=0; j<sp; ++j){
                    if(i+sprime[j]<=n && (!can[i+sprime[j]] || dist[i]+1<dist[i+sprime[j]])){
                        dist[i+sprime[j]]=dist[i]+1;
                        par[i+sprime[j]]=i;
                        can[i+sprime[j]]=true;
                    }
                }
            }
        }

        if(!can[n]) out.println(0);
        else{
            int ind=n;
            ans = new int[dist[n]];
            while(par[ind]!=-1){
                ans[cans++]=ind-par[ind];
                ind=par[ind];
            }
            Arrays.sort(ans);
            out.println(cans);
            if(cans>0){
                for (int i=cans-1; i>=0; --i){
                    out.print(ans[i]);
                    out.print(" ");
                }
                out.println();
            }
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
