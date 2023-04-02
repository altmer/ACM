import java.util.*;
import java.math.*;
import java.io.*;

class Graph
{
    //*
    Scanner cin = new Scanner(new File("domestic.in"));
    //*/
    /*
    Scanner cin = new Scanner(System.in);
    //*/
    class Edge implements Comparable<Edge>{
        public int st, end, len, num;
        Edge(){
            st=-1; end=-1; len=-1; num=-1;
        }
        Edge (int a, int b, int c, int d){
            st=a; end=b; len=c; num=d;
        }
        public int compareTo(Edge t){
            return this.len-t.len;
        }
    }
    int n, m;
    int p5, q5, p6, q6;
    public Edge[] listEdge;
    int[] col;
    public boolean[] use;
    Graph()throws IOException{
        n = cin.nextInt();
        m = cin.nextInt();
        col = new int [n];
        listEdge = new Edge[m];
        use = new boolean[m];
    }
    public void readEdges()throws IOException{
        for (int i=0; i<m; ++i){
            listEdge[i] = new Edge(cin.nextInt()-1, cin.nextInt()-1,cin.nextInt(), i+1);
        }
        p5 = cin.nextInt();
        q5 = cin.nextInt();
        p6 = cin.nextInt();
        q6 = cin.nextInt();
    }
    public boolean Kruskal (){
        Arrays.sort(listEdge);
        int color=1;
        for (int i=0; i<listEdge.length; ++i){
           if (listEdge[i].st==listEdge[i].end){
                continue;
           }
            if (col[listEdge[i].st]==0 && col[listEdge[i].end]==0){
                col[listEdge[i].st]=color;
                col[listEdge[i].end]=color++;
                use[i]=true;
            }
            else if (col[listEdge[i].st]==0){
                col[listEdge[i].st]=col[listEdge[i].end];
                use[i]=true;
            }
            else if(col[listEdge[i].end]==0){
                col[listEdge[i].end]=col[listEdge[i].st];
                use[i]=true;
            }
            else if(col[listEdge[i].st]!=col[listEdge[i].end]){
                int tocolor=col[listEdge[i].st];
                for (int j=0; j<n; ++j){
                    if (col[j]==tocolor){
                        col[j]=col[listEdge[i].end];
                    }
                }
                use[i]=true;
            }
        }
        for (int i=1; i<n; ++i){
            if (col[i]!=col[i-1]){
                return false;
            }
        }
        return true;
    }
}

class Knapsack
{
    public class Good implements Comparable <Good>{
        int num, weight, ans;
        Good(){
            num=-1; weight=-1; ans=-1;
        }
        public Good(int a, int b){
            num = a; weight = b; ans=-1;
        }
        public int compareTo (Good t){
            return this.num-t.num;
        }
    }
    int p5, p6, q5, q6, n5, n6, l5, l6;
    int price;
    List <Good> A;
    Knapsack( Graph G ){
        l5=l6=price=0;
        p5=G.p5; q5=G.q5; n5=5;
        p6=G.p6; q6=G.q6; n6=6;
        if (p5>p6){
            int t=p5; p5=p6; p6=t;
            t=q5; q5=q6; q6=t;
            n5=6; n6=5;
        }
        A = new ArrayList <Good>();
        for (int i=0; i<G.listEdge.length; ++i){
            if (G.use[i])
               A.add(new Good(G.listEdge[i].num, G.listEdge[i].len));            
        }
    }
    public boolean solve()
    { 
        boolean f[] = new boolean[q5+1];
        f[0]=true;
        Good[] p = new Good[q5+1];
        for (Good g : A){
            for (int i=q5; i>=g.weight; --i){
                if (!f[i] && f[i-g.weight]){
                    f[i]=true;
                    p[i]=g;
                }
            }
        }
        int j=q5;
        while(!f[j])
            --j;
        while(j>0){
            p[j].ans=n5;
            j-=p[j].weight;
        }
        for (Good g : A){
            if(g.ans==n5){
                l5+=g.weight;
                price+=g.weight*p5;
            }
            else{
                g.ans=n6;
                l6+=g.weight;
                price+=g.weight*p6;
            }
        }
        Collections.sort(A);
        return l5<=q5 && l6<=q6;
    }
}


public class Main {
    public static void main(String[] args) throws IOException{
        //*
        PrintWriter cout = new PrintWriter (new File ("domestic.out" ) );
        //*/
        /*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
        
        Graph G = new Graph();
        G.readEdges();
        if (G.Kruskal()){
            Knapsack sack = new Knapsack(G);
            if(sack.solve()){
                cout.println(sack.price);
                for (Knapsack.Good g : sack.A){
                    cout.print(g.num);
                    cout.print(" ");
                    cout.println(g.ans);
                }
            }
            else{
                cout.println("Impossible");
            }
        }
        else{
            cout.println("Impossible");
        }
        
        cout.close();
    }
}
