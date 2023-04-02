
import java.util.*;


public class TheSwap {
    String ans = "-1";
    int dep;

    void rec(int step, char[] num, int ind){
        if(step == dep + 1){
            String cur = new String(num);
            if(Integer.valueOf(ans)<Integer.valueOf(cur)){
                ans = cur;
            }
            return;
        }

        for (int i=ind; i<num.length; ++i){
            for (int j=i+1; j<num.length; ++j){
                if(i!=0 || num[j]!='0'){
                    char[] nw = new char[num.length];
                    for (int q=0; q<num.length; ++q){
                        nw[q] = num[q];
                    }
                    char tmp= nw[i];
                    nw[i]=nw[j];
                    nw[j]=tmp;
                    rec(step+1, nw, i+1);
                }
            }
        }        
    }

    public int findMax(int n, int k){
        String cur = String.valueOf(n);
        dep = k;
        rec(1, cur.toCharArray(), 0);
        return Integer.valueOf(ans);
    }
    public static void main(String[] args) {
        new TheSwap().findMax(432, 1);
    }

}
