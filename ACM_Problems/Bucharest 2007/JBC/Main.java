import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        //*
        Scanner cin = new Scanner(new File("JBC.in"));
        //*/
        /*
        Scanner cin = new Scanner(System.in);
        //*/
        //*
        PrintWriter cout = new PrintWriter (new File ("JBC.out" ) );
        //*/
        /*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
        
        while (cin.hasNextLine()){
            String s = cin.nextLine();
            if (s.length()==0)
                continue;
            
            int lim = s.length();
            int mas[] = new int [255];
            
            for (int i=0; i<lim; ++i){
                mas[s.charAt(i)]=i;
            }
            
            String num = "0";
            while (cin.hasNextLine()){
                num = cin.nextLine();
                num = num.trim();
                if (num.length()==0)
                    break;
                int maxx=0;
                BigInteger ans = BigInteger.ZERO; 
                for (int i=0; i<num.length(); ++i){
                    maxx = Math.max(mas[num.charAt(i)]+1, maxx);
                }
                for (int i=maxx; i<=lim; ++i){
                    BigInteger w = BigInteger.ONE;
                    BigInteger cur = BigInteger.ZERO;
                    for (int j=num.length()-1; j>=0; --j){
                        cur = cur.add (w.multiply(BigInteger.valueOf(mas[num.charAt(j)])) );
                        w = w.multiply(BigInteger.valueOf(i));
                    }
                    ans = ans.add(cur);
                }
                cout.println(ans);
            }
            if (cin.hasNextLine())
                cout.println();
        }

        cout.close();
    }
}
