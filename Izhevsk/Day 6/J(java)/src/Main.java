import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    int C[][];
    BigInteger mod = BigInteger.valueOf(2007L*2007L*2007L*2007L);
    BigInteger ppow[];

    void bin_coef(){
            C[0][0]=1;
            for (int i=1; i<20; ++i){
                    C[i][0]=1;
                    C[i][i]=1;
                    for (int j=1; j<i; ++j){
                            C[i][j]=C[i-1][j]+C[i-1][j-1];
                    }
            }
    }

    BigInteger pow(BigInteger a, BigInteger k){
            BigInteger ret=BigInteger.valueOf(1);
            while(k.compareTo(BigInteger.ZERO)>0){
                    if(k.getLowestSetBit()==0){
                            k = k.subtract(BigInteger.valueOf(1));
                            ret = ret.multiply(a).remainder(mod);
                    }else{
                            k = k.divide(BigInteger.valueOf(2));
                            a = a.multiply(a).remainder(mod);
                    }
            }
            return ret;
    }

    
    void run()throws Exception{
        in = new BufferedReader(new FileReader ("square5.in"));
        out = new PrintWriter(new File("square5.out"));
        
        BigInteger one = new BigInteger("376");
        BigInteger two = new BigInteger("625");
        
    int ans = 2000;
    boolean fin=false;
        while(!fin&& (one.toString().length()<ans || two.toString().length()<ans)){
            String on = one.toString();
            fin = true;
            if(on.length()<ans){
                // припишем одну цифру
                for (int i=1; i<=9999999; ++i){
                    String cur = Integer.toString(i) + on;
                    BigInteger num = new BigInteger(cur);
                    BigInteger num2 = num.multiply(num);
                    int mod=cur.length();
                    StringBuilder s =  new StringBuilder("10");
                    for (int j=2; j<=mod; ++j){
                        s.append('0');
                    }
                    BigInteger m = new BigInteger(s.toString());
                    if(num2.remainder(m).equals(num)){
                        one = num;
                        fin=false;
                        break;
                    }
                }               
            }
            String tw = two.toString();
            if(tw.length()<ans){
                // припишем одну цифру
                for (int i=1; i<=9999999; ++i){
                    String cur = Integer.toString(i) + tw;
                    BigInteger num = new BigInteger(cur);
                    BigInteger num2 = num.multiply(num);
                    int mod=cur.length();
                    StringBuilder s =  new StringBuilder("10");
                    for (int j=2; j<=mod; ++j){
                        s.append('0');
                    }
                    BigInteger m = new BigInteger(s.toString());
                    if(num2.remainder(m).equals(num)){
                        two = num;
                        fin=false;
                        break;
                    }
                }               
            }
            out.println(one);
            out.println(two);
        }

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }    
    
}
