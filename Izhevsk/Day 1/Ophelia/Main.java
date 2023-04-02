import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    void run()throws Exception{
        in = new BufferedReader(new FileReader ("ophelia.in"));
        out = new PrintWriter(new File("ophelia.out"));
        
        int dist[] = new int [200000];
        Arrays.fill(dist, 1000*1000*1000);
                      
        String[] inp = in.readLine().split(":");
        int h1 = Integer.parseInt(inp[0]);
        int m1 = Integer.parseInt(inp[1]);
        int st1 = h1*1000 + m1*10 + 1;
        int st2 = h1*1000 + m1*10;
        inp = in.readLine().split(":");
        int hh2 = Integer.parseInt(inp[0]);
        int mm2 = Integer.parseInt(inp[1]);
        int end1 = hh2*1000 + mm2*10 + 1;
        int end2 = hh2*1000 + mm2*10;
        
        if(st2==end2){
            out.println(0);
            out.close();
            return;
        }
        dist[st1]=1;
        dist[st2]=1;
               
        int q[] = new int [200000];
        int qh=0, qt=0;
        q[qt++]=st1;
        q[qt++]=st2;
        
        while(qh!=qt){
            int u = q[qh++];
            int dig = u&1;
            int h = u/1000;
            int m = (u%1000)/10;
            // forward hours
            int h2 = h==23 ? 0 : h+1;
            int v = h2*1000 + m*10 + 1;
            int len = dig==0 ? 2 : 1;
            if(dist[v]>dist[u]+len){
                dist[v]=dist[u]+len;
                q[qt++]=v;
            }
            // backward hours
            h2 = h==0 ? 23 : h-1;
            v = h2*1000 + m*10 + 0;
            len = dig==0 ? 1 : 2;
            if(dist[v]>dist[u]+len){
                dist[v]=dist[u]+len;
                q[qt++]=v;
            }
            // forward minutes
            int m2 = m==59 ? 0 : m+1;
            if(m2==0)
                h2 = h==23 ? 0 : h+1;
            else
                h2=h;
            v = h2*1000 + m2*10 + 1;
            len = dig==0 ? 2 : 1;
            if(dist[v]>dist[u]+len){
                dist[v]=dist[u]+len;
                q[qt++]=v;
            }
            // backward minutes
            m2 = m==0 ? 59 : m-1;
            if(m2==59)
                h2 = h==0 ? 23 : h-1;
            else
                h2=h;
            v = h2*1000 + m2*10 + 0;
            len = dig==0 ? 1 : 2;
            if(dist[v]>dist[u]+len){
                dist[v]=dist[u]+len;
                q[qt++]=v;
            }
            
        }
        
        out.println(Math.min(dist[end1],dist[end2]));
        
        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }    
    
}
