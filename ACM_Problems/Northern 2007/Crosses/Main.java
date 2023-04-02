import java.util.*;
import java.math.*;
import java.io.*;

class Game{
    protected int[] ans;
    protected int[] grun;
    public int run (int n)
    {
        ans = new int [n+1];
        ans[0]=0;
        ans[1]=1;
        ans[2]=1;
        for (int i=3; i<=n; ++i){
            grun = new int[1000];
            // trying to set cross in every field
            for (int j=1; j<=i; ++j){
                int left = Math.max(0, j-3);
                int right = Math.max(0, i-j-2);
                int res = ans[left]^ans[right];
                grun[res]=1;
            }
            for (int j=0; j<100; ++j){
                if (grun[j]==0){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans[n]==0 ? 2 : 1;
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        //*
        Scanner cin = new Scanner(new File("crosses.in"));
        //*/
        /*
        Scanner cin = new Scanner(System.in);
        //*/
        //*
        PrintWriter cout = new PrintWriter (new File ("crosses.out" ) );
        //*/
        /*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
         
        Game g = new Game();
        
        cout.println(g.run(cin.nextInt()));
        
        cout.close();
    }
}
