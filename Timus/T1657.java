import java.io.*;

public class Main {
    static final int dx[] = {1, -1, 0, 0, 0, 0};
    static final int dy[] = {0, 0, 1, -1, 0, 0};
    static final int dz[] = {0, 0, 0, 0, 1, -1};
    static final char let[] = {'F', 'B', 'R', 'L', 'U', 'D'};
    int index[];
    boolean vis[][][];
    String path;
    char[] ans;

    boolean rec (int step, int x, int y, int z){
        if (step==0){
            for (int i=0; i<6; ++i){
                if(!vis[x+dx[i]][y+dy[i]][z+dz[i]]){
                    vis[x+dx[i]][y+dy[i]][z+dz[i]]=true;
                    ans[step]=let[i];
                    if(rec(step+1, x+dx[i],y+dy[i],z+dz[i])){
                        return true;
                    }
                    vis[x+dx[i]][y+dy[i]][z+dz[i]]=false;
                }
            }
        }
        else if (step==26){
            return true;
        }
        else{
            if (path.charAt(step)=='T'){
                for (int i=0; i<6; ++i){
                    if(!vis[x+dx[i]][y+dy[i]][z+dz[i]] && i!=index[ans[step-1]]){
                        vis[x+dx[i]][y+dy[i]][z+dz[i]]=true;
                        ans[step]=let[i];
                        if(rec(step+1, x+dx[i],y+dy[i],z+dz[i])){
                            return true;
                        }
                        vis[x+dx[i]][y+dy[i]][z+dz[i]]=false;
                    }
                }
            }
            else{
                if (!vis[x+dx[index[ans[step-1]]]][y+dy[index[ans[step-1]]]][z+dz[index[ans[step-1]]]]){
                    vis[x+dx[index[ans[step-1]]]][y+dy[index[ans[step-1]]]][z+dz[index[ans[step-1]]]]=true;
                    ans[step]=ans[step-1];
                    if (rec(step+1, x+dx[index[ans[step]]],y+dy[index[ans[step]]],z+dz[index[ans[step]]])){
                        return true;
                    }
                    vis[x+dx[index[ans[step-1]]]][y+dy[index[ans[step-1]]]][z+dz[index[ans[step-1]]]]=false;
                }
                else
                    return false;
            }
        }
        return false;
    }

    void run() throws IOException{
        vis = new boolean[5][5][5];
        index = new int[70000];
        index['F']=0;
        index['B']=1;
        index['R']=2;
        index['L']=3;
        index['U']=4;
        index['D']=5;
        ans = new char[26];
        for (int i=0; i<5; ++i){
            for (int j=0; j<5; ++j){
                vis[i][j][0]=true;
                vis[i][j][4]=true;
                vis[0][i][j]=true;
                vis[4][i][j]=true;
                vis[i][0][j]=true;
                vis[i][4][j]=true;
            }
        }
      /*
        BufferedReader in = new BufferedReader (new FileReader ("input.txt"));
        PrintWriter out = new PrintWriter (new File("output.txt"));
      */
        BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter (System.out);
        path = in.readLine();

        for (int i=1; i<=3; ++i){
            for (int j=i; j<=3; ++j){
                for (int k=j; k<=3; ++k){
                    vis[i][j][k]=true;
                    if(rec(0,i,j,k)){
                          out.println(ans);
                          out.close();
                          return;
                    }
                    vis[i][j][k]=false;
                }
            }
        }
        
        out.println("IMPOSSIBLE");
        out.close();
    }

        
    public static void main(String[] args) throws  IOException{
        new Main().run();
    }
}
