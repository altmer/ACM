import java.util.*;
import java.math.*;
import java.io.*;

class Graph
{
    int[][] A;
    boolean[] col;
    int[] dist;
    int par[];
    public int maxdist;
    public boolean cyclic;
    public Graph (int n){
        maxdist=0;
        cyclic=false;
        A = new int [n][n];
        col = new boolean[n];
        dist = new int[n];
        par = new int[n];
    }
    public void addEdge (int a, int b, int len){
        if (a==b)
            cyclic=true;
        if (A[a][b]!=0)
            cyclic=true;
        A[a][b]=len;
        A[b][a]=len;

    }
    public void dfs (int u){
        col[u]=true;
        for (int i=0; i<A[u].length; ++i){
            if (A[u][i]!=0){
                if (!col[i]){
                    par[i]=u;
                    dist[i]=dist[u]+A[u][i];
                    maxdist = Math.max (maxdist, dist[i]);
                    dfs(i);
                }
                else if (!cyclic && par[u]!=i){
                    cyclic=true;
                }                
            }
        }
    }
    public void clear(){
        for (int i=0; i<col.length; ++i){
            col[i]=false;
            dist[i]=0;
            par[i]=0;
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        Scanner cin = new Scanner(new File("T1227.in"));
        //*/
        
        //*
        Scanner cin = new Scanner(System.in);
        //*/
        
        /*

         PrintWriter cout = new PrintWriter (new File ("T1227.out" ) );
        //*/

        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/       
         int n = cin.nextInt();
         Graph solve = new Graph(n);
         int m = cin.nextInt();
         int s = cin.nextInt();
         for (int i=0; i<m; ++i){
             int a, b, c;
             a = cin.nextInt();
             b = cin.nextInt();
             c = cin.nextInt();
             solve.addEdge(a-1, b-1, c);
         }
         
         for (int i=0; i<n; ++i){
             solve.clear();
             solve.dfs(i);
             if (solve.cyclic)
                 break;
         }
         if (solve.maxdist>=s || solve.cyclic){
             cout.println("YES");
         }
         else{
             cout.println("NO");
         }

         cout.close();
    }
}
