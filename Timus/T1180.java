/*
package mypkg;
//*/

import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        Scanner cin = new Scanner(new File("T1180.in"));
        //*/
        //*
        Scanner cin = new Scanner(System.in);
        //*/
        
        /*

         PrintWriter cout = new PrintWriter (new File ("T1180.out" ) );
        //*/

        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/ 
         
         String s = cin.nextLine();
         BigInteger num=new BigInteger (s);
         BigInteger rem = num.remainder(new BigInteger ("3") );
         if ( rem.compareTo (new BigInteger("0")) == 0){
               cout.println("2");
         }
         else{
             cout.println("1");
             cout.println(rem);
         }

         cout.close();
    }
}
