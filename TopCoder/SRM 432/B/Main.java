import java.util.*;
import static java.lang.Math.*;

class GroupedWord{
    boolean[][] A;
    boolean[] col;
    int[] ent;
    int n;
    StringBuffer ans = new StringBuffer();
    String[] p;

    boolean dfs(int u){
        ans.append(p[u]);
        col[u]=true;
        for (int i=0; i<n; ++i){
            if(A[u][i]){
                if (!col[i]){
                    if(!dfs(i))
                        return false;
                }
                else{
                    StringBuffer tmp = new StringBuffer();
                    tmp.append(p[u]);
                    tmp.append(p[i]);
                    for (int j=1; j<tmp.length(); ++j){
                        if(tmp.charAt(j)!=tmp.charAt(j-1)){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    String restore(String[] parts){
        p=parts;
        n=parts.length;
        A = new boolean[n][n];
        ent = new int[n];
        col = new boolean[n];
        for (int i=0; i<n; ++i){
            boolean[] vis = new boolean[30];
            for (int j=0; j<parts[i].length(); ++j){
                if(vis[parts[i].charAt(j)-'a'] && parts[i].charAt(j-1)!=parts[i].charAt(j)){
                    return "IMPOSSIBLE";
                }
                vis[parts[i].charAt(j)-'a']=true;
            }
            for (int j=0; j<n; ++j){
                if(j==i)
                    continue;
                if (parts[i].charAt(parts[i].length()-1)==parts[j].charAt(0)){
                    A[i][j]=true;
                    ent[j]++;
                }
            }
        }
        int minn=Integer.MAX_VALUE;
        int wh=-1;
        for (int i=0; i<n; ++i){
            if(ent[i]<minn){
                minn=ent[i];
                wh=i;
            }
        }

        if(!dfs(wh))
            return "IMPOSSIBLE";

        for (int i=0; i<n; ++i){
            if(!col[i])
                return "MANY";
        }
        
        return ans.toString();
    }
}

public class Main {

    public static void main(String[] args) {
        String[] ar = {"te", "st"};
        System.out.println(new GroupedWord().restore(ar));
    }
}
