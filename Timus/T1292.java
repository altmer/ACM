import java.util.*;
import java.math.*;
import java.io.*;

abstract class Solve{
    static int F (int n){
        int ans=0;
        while (n>0){
            int dig = n%10;
            n/=10;
            ans+=dig*dig*dig;
        }
        return ans;
    }
    static int run (int n, int prev, int L){
        int cur=0;
        for (int i=1; i<n; ++i){
            cur = F(prev);
            if (cur==prev){
                return cur - L;
            }
            prev=cur;
        }
        return cur - L;
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        Scanner cin = new Scanner(new File("T1292.in"));
        //*/
        //*
        Scanner cin = new Scanner(System.in);
        //*/
        /*
        PrintWriter cout = new PrintWriter (new File ("T1292.out" ) );
        //*/
        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
        
        int T = cin.nextInt();
        
        for (int i=0; i<T; ++i){
            int N = cin.nextInt(), K = cin.nextInt(), L = cin.nextInt();
            cout.println(Solve.run(N, K, L));
        }

        cout.close();
    }
}
