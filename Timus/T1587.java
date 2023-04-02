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
        Scanner cin = new Scanner(new File("T1587.in"));
        //*/
        /*
        Scanner cin = new Scanner(System.in);
        //*/
        /*
        PrintWriter cout = new PrintWriter (new File ("T1587.out" ) );
        //*/
        StreamTokenizer cin = new StreamTokenizer (new BufferedReader ( new InputStreamReader(System.in)));
        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
        BigInteger ans, cur, I2, I3;
        ans = BigInteger.ZERO;
        //cur = BigInteger.ONE;
        I2 = new BigInteger ("2");
        I3 = new BigInteger ("3");
        
        int[] score;
        int[] num2,num3,minus;
        
        cin.nextToken();
        int n = (int)cin.nval;
        
        score = new int[n+1];
        num2 = new int[n+1];
        num3 = new int[n+1];
        minus = new int[n+1];
        
        int st=0;
        int end=0;
        if (n==1){
            n=0;
            cin.nextToken();
            ans=BigInteger.valueOf((int)cin.nval);
        }
        else{
            cin.nextToken();
            score[0]=(int)cin.nval;
            if (Math.abs(score[0])==2)
                num2[0]=1;
            if (Math.abs(score[0])==3)
                num3[0]=1;
            if (score[0]<0)
                minus[0]=1;
            if(score[0]==0)
                st++;
        }
        for (int i=1; i<=n; ++i){
            if (i!=n){
                cin.nextToken();
                score[i]=(int)cin.nval;
            }
            if (score[i]!=0){
                num2[i]=num2[i-1];
                num3[i]=num3[i-1];
                minus[i]=minus[i-1];
                if (Math.abs(score[i])==2)
                    num2[i]++;
                if (Math.abs(score[i])==3)
                    num3[i]++;
                if (score[i]<0)
                    minus[i]++;
            }
            else{
                end=i-1;
                if (end>=st && minus[end]%2 == 0){
                    cur=I2.pow(num2[end]).multiply(I3.pow(num3[end]));
                    if (ans.compareTo(cur)<0){
                        ans = cur;
                        cur = null;
                    }
                }
                else if (end>st){
                    int k=st;
                    while (k<n && minus[k]==0)
                        ++k;
                    if (k<n)
                        cur=I2.pow(num2[end]-num2[k]).multiply(I3.pow(num3[end]-num3[k]));
                    else
                        cur=BigInteger.ZERO;
                    if (ans.compareTo(cur)<0){
                        ans = cur;
                        cur = null;
                    }
                    k=end;
                    while (k>=0 && minus[k]==minus[end])
                        --k;
                    if (k>=0)
                        cur=I2.pow(num2[k]).multiply(I3.pow(num3[k]));
                    else
                        cur = BigInteger.ZERO;
                    if (ans.compareTo(cur)<0){
                        ans = cur;
                        cur = null;
                    }
                }
                st = i+1;
            }
        }
        
        cout.println(ans);
        cout.close();
    }
}
