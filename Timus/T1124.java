import java.io.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    boolean[][] A;
    boolean[] col;
    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
    int dfs (int u){
        int ret=0;
        col[u]=true;
        for (int i=0; i<A[u].length; ++i){
            if(!col[i] && A[u][i]){
                ret+=dfs(i);
            }
        }
        return ret+1;
    }
    void run() throws Exception{
        init2();
        String res[] = in.readLine().split("\\s");
        int m = Integer.parseInt(res[0]);
        int n = Integer.parseInt(res[1]);
        A = new boolean[m][m];
        col = new boolean[m];
        int cnt=0;
        for (int i=0; i<m; ++i){
            res = in.readLine().split("\\s");
            for (int j=0; j<n; ++j){
                int t = Integer.parseInt(res[j])-1;
                if(t!=i){
                    cnt++;
                    A[i][t]=true;
                }
            }
        }
        for (int i=0; i<m; ++i){
            if(!col[i] && dfs(i)>1){
                cnt++;
            }
        }
        out.println(cnt==0 ? cnt : cnt-1);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
