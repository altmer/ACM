import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        Scanner cin = new Scanner(new File("T1036.in"));
        //*/
        //*
        Scanner cin = new Scanner(System.in);
        //*/
        /*
        PrintWriter cout = new PrintWriter (new File ("T1036.out" ) );
        //*/
        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
        BigInteger[] v1, v2;
        
        int n = cin.nextInt();
        int s = cin.nextInt();
        if (s%2 != 0){
            cout.println("0");
            cout.close();
            System.exit(0);
        }
        s/=2;
        
        v1 = new BigInteger[s+1];
        
        for (int i=0; i<= Math.min (s, 9); ++i){
            v1[i]= BigInteger.ONE;
        }
        for (int i=10; i<=s; ++i){
            v1[i]= BigInteger.ZERO;
        }
        
        for (int i=1; i<n; ++i){
            v2 = new BigInteger[s+1];
            for (int j=0; j<=s; ++j){
                BigInteger cur = BigInteger.ZERO;
                for (int k=0; k<=Math.min(9, j); ++k){
                    cur = cur.add(v1[j-k]);
                }
                v2[j]= cur;
            }
            v1 = v2;
            v2 = null;
        }
        
        cout.println(v1[s].multiply(v1[s]));
        

        cout.close();
    }
}
