package mypkg;

import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException{
       /* Scanner cin = new Scanner(new File("T1248.in"));
        PrintWriter cout = new PrintWriter ("T1248.out");*/

        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter (System.out);

        int n=cin.nextInt();
        cin.nextLine();

        BigDecimal ans = new BigDecimal(0);
        for (int i=0; i<n; ++i){
            String s=cin.nextLine();
            ans = ans.add(new BigDecimal(s));
        }

        ans=ans.round(new MathContext(19, RoundingMode.HALF_UP));
        String s= (ans.unscaledValue()).toString();

        cout.print(s.charAt(0));
        cout.print(".");

        if (s.length()>1)
            cout.print(s.substring(1));

        if (s.length()<19){
            for (int i=s.length()+1; i<=19; ++i)
                cout.print("0");
        }

        cout.print("e");
        cout.print((int)s.length() - ans.scale()-1);

        cout.close();
    }
}
