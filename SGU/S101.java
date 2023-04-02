import java.io.*;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;

    class Edge{
        int fr, to;
        int num;
        boolean used;
        Edge next;
        Edge(){}
        Edge(int a, int b, int c) {fr=a;to=b;num=c;used=false;next=null;}
    }

    class Res{
        int num;
        boolean rev;
        Res(){}
        Res(int a, boolean r) {num=a; rev=r;}
    }

    List<Edge> A[];
    Edge[] E;
    int[] ans;
    int[] deg;

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

        A = new List[7];
        deg = new int[7];
        int[] s = new int[200];
        int ptr=0;

        for (int i=0; i<=6; ++i)
            A[i]=new LinkedList();

        int n = Integer.parseInt(in.readLine());
        E = new Edge[n+5];
        ans = new int[2*n+5];
        int u=-1;

        for (int i=0; i<n; ++i){
            String[] res = in.readLine().split("\\s");
            int fr = Integer.parseInt(res[0]);
            int to = Integer.parseInt(res[1]);

            if(u==-1)
                u=fr;
            
            E[i]= new Edge(fr, to, i+1);
            A[fr].add(E[i]);
            A[to].add(E[i]);
            deg[fr]++;
            deg[to]++;
        }

        int st=-1, f=-1;
        boolean bad=false;
        
        for (int i=0; i<7; ++i){
            if((deg[i]&1)==1){
                if(st==-1){
                    st=i;
                }else if(f==-1){
                    f=i;
                }else{
                    bad=true;
                }
            }
        }

        if(bad){
            out.println("No solution");
            out.close();
            return;
        }

        if(st!=-1){
            E[n]=new Edge(st,f,-1);
            A[st].add(E[n]);
            A[f].add(E[n]);
            n++;
        }

        s[ptr++]=u;
        int cur=0;

        while(ptr>0){
            u = s[ptr-1];
            boolean found=false;
            
            for (Edge e : A[u]){
                if(!e.used){
                    e.used=true;
                    found=true;
                    s[ptr++]=e.fr==u ? e.to : e.fr;
                    break;
                }
            }
            
            if(!found){
                ptr--;
                ans[cur++]=u;
            }
        }

        for (int i=0; i<n; ++i){
            if(!E[i].used){
                bad=true;
                break;
            }
            E[i].used=false;
        }

        if(bad){
            out.println("No solution");
            out.close();
            return;
        }

        if(st!=-1){
            for (int i=1; i<cur; ++i){
                if(ans[i-1]==st && ans[i]==f || ans[i-1]==f && ans[i]==st ){
                    int[] ans2 = new int[2*n+5];
                    int ind=0;
                    for (int j=i; j<cur; ++j){
                        ans2[ind++]=ans[j];
                    }
                    for (int j=1; j<i; ++j){
                        ans2[ind++]=ans[j];
                    }
                    ans=ans2;
                    cur=ind;
                    n--;
                    break;
                }
            }
        }

        for (int i=0; i<cur-1; ++i){
            for (int j=0; j<n; ++j){
                if(!E[j].used && E[j].fr==ans[i]&&E[j].to==ans[i+1]){
                    out.print(E[j].num);
                    E[j].used=true;
                    out.println(" +");
                    break;
                }
                if(!E[j].used && E[j].to==ans[i]&&E[j].fr==ans[i+1]){
                    out.print(E[j].num);
                    E[j].used=true;
                    out.println(" -");
                    break;
                }
            }            
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Solution().run();
    }
}
