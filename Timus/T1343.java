import java.util.*;
import java.math.*;
import java.io.*;

abstract class TestPrime{
    protected static int[] v;
    protected static int num;
    protected static void init(){
        v = new int[251000];
        v[0]=2;
        num=1;
        for (int i=3; i<=1000000; i+=2){
            if (prime(i))
                v[num++]=i;
        }
    }
    protected static boolean prime (long x){
        double lim = Math.sqrt((double)x);
        for (int i=0; i<num; ++i){
            if (x%v[i]==0)
                return false;
            if (v[i]>lim)
                break;
        }
        return true;
    }
    public static boolean isPrime(long x){
        if (v==null){
            init();
        }
        if(x==1)
            return false;

	return prime(x);
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        Scanner cin = new Scanner(new File("T1343.in"));
        //*/
        //*
        Scanner cin = new Scanner(System.in);
        //*/
        /*
        PrintWriter cout = new PrintWriter (new File ("T1343.out" ) );
        //*/
        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
    
        int know = cin.nextInt();
        long first = 0;
        if (know!=0)
            first = cin.nextLong();
        if (know==12){
            cout.format("%012d", first);
            cout.close();
            System.exit(0);
        }
        long tmp = 1;
        
        for (int i=0; i<12-know; ++i)
            tmp*=10;
        
        first*=tmp;
        Random rand = new Random();
        while (true){
            long t = rand.nextLong();
            t%=tmp;
            t = Math.abs(t);
            if (t%2==0)
                ++t;
            long toProve = first + t;
            if (TestPrime.isPrime(toProve)){
                cout.format("%012d", toProve);
                break;
            }
        }
        
        cout.close();
    }
}
