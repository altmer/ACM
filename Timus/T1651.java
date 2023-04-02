import java.util.*;
import java.io.*;

public class Main2 {
    BufferedReader in;
    PrintWriter out;

    class Way implements Comparable<Way>{
        int dist, num;
        Way prev;
        Way(int d, int n, Way w){
            dist = d; prev =w; num=n;
        }
        public int compareTo(Way T){
            return dist-T.dist;
        }
    }

    List<Way> P[];
    Way[] best;
    Stack<Integer> s;

    public void run() throws Exception{
/*
        in = new BufferedReader (new FileReader(new File("input.txt")));
        out = new PrintWriter ("output.txt");
*/
        in = new BufferedReader (new InputStreamReader(System.in));
        out = new PrintWriter (System.out);

        
        s = new Stack<Integer> ();
        int n = Integer.parseInt(in.readLine());
        int cnt=0;
        int cur=-1;
        P = new List[10100];
        best = new Way[10100];

        int fin=-1;
        while(cnt<n){
            StringTokenizer str= new StringTokenizer (in.readLine());
            while(str.hasMoreTokens()){
               cnt++;
               int next = Integer.parseInt(str.nextToken());
               Way tmp;
               if(cur==-1){
                   P[next]=new LinkedList<Way>();
                   tmp = new Way(0,next, null);
                   P[next].add(tmp);
                   best[next] = tmp;
               }
               else{
                   if(P[next]==null)
                       P[next]= new LinkedList<Way>();
                   tmp = new Way(best[cur].dist+1, next, best[cur]);
                   P[next].add(tmp);
                   if(best[next]==null || tmp.compareTo(best[next])<0){
                       best[next]=tmp;
                   }
               }
               cur = next;
            }
        }
        fin = cur;
        for (Way c = best[fin]; c!=null; c=c.prev){
            s.push(c.num);
        }

        while(!s.empty()){
            out.print(s.pop()+" ");
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception {
        new Main2().run();
    }
}
