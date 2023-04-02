import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    
    class Node{
        int next, item;
        Node(){
            next=item=-1;
        }
    }
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    void run()throws Exception{
        in = new BufferedReader(new FileReader ("laertes.in"));
        out = new PrintWriter(new File("laertes.out"));
        
        int n = Integer.parseInt(in.readLine());
        Node[] A = new Node[n];
        for (int i=0; i<n; ++i){
            A[i] = new Node();
        }
        
        Node[] E = new Node[2*n];
        for (int i=0; i<2*n; ++i){
            E[i] = new Node();
        }
        
        int cnt=0;
        int[] par = new int[n];
        par[0]=-1;
        
        int resp[] = new int[2*n];
        int resc[] = new int[2*n];
        
        boolean col[] = new boolean [n];
        col[0]=true;
        boolean used[] = new boolean[n];
        
        for (int i=0; i<n-1; ++i){
            String[] inp = in.readLine().split("\\s");
            int fr = Integer.parseInt(inp[0])-1;
            int to = Integer.parseInt(inp[1])-1;
            E[cnt].item=to;
            E[cnt].next =A[fr].next;
            A[fr].next=cnt++;            
        }
        
        int Q[] = new int[2*n];
        int ans[] = new int[2*n];
        int st = 0;
        ans[st++] = 0;
        int qh=0;
        int qt=0;
        
        Q[qt++]=0;
        while(qh!=qt){
            int u = Q[qh++];
            for (int i=A[u].next; i!=-1; i = E[i].next){
                int v = E[i].item;
                if(!col[v]){
                    par[v]=u;
                    ans[st++]=v;
                    col[v]=true;
                    Q[qt++]=v;
                }
            }
        }
        int c = 0;
        for (int i=st-1; i>=0; --i){
            if(par[ans[i]]!=-1 && !used[ans[i]] && !used[par[ans[i]]]){
                used[ans[i]]=true;
                used[par[ans[i]]]=true;
                resp[c]=par[ans[i]]+1;
                resc[c++]=ans[i]+1;
            }
        }
        out.println(c);
        for (int i=0; i<c; ++i){
            out.print(resp[i]);
            out.print(" ");
            out.println(resc[i]);
        }
        
        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }    
    
}
