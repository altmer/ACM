import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class SquareFreeNumbers {

    int getCount(long min, long max){
        int ans=0;
        // primes
        int lim = (int)sqrt(max) + 1;
        
        boolean p[] = new boolean [lim+2];
        int[] primes = new int[lim+2];
        int sz=0;
        
        for (int j=2; j<=lim; ++j){
            if(!p[j]){
                primes[sz++]=j;
                int num=2*j;
                while(num<=lim){
                    p[num]=true;
                    num+=j;
                }
            }
        }
        
        for(long a=min; a<=max; ++a){
            long cur=a;
            boolean good=true;
            for (int k=0; k<sz; ++k){
                int cnt=0;
                while(cur%primes[k]==0){
                    cur/=primes[k];
                    ++cnt;
                }
                if(cnt>1){
                    good=false;
                    break;
                }
            }
            if(good)
                ++ans;
        }
        return ans;
    }

    public static void main(String[] args) {
        // TODO code application logic here
    }

}
