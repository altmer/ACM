import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class PrimePairs {
    List<Integer> ans = new LinkedList();
    int[] nums;
    boolean got[];
    int num=0;
    
    boolean rec(boolean z){
        if(z){
            for (int i=1; i<nums.length; ++i){
                
            }
        }else{
            
        }
    }

    int[] matches(int[] numbers){
        nums=numbers;
        got = new boolean[numbers.length];
        rec(true);
        int[] ret = new int[ans.size()];
        int k=0;
        for (Integer i : ans){
            ret[k++]=i;
        }
        return ret;
    }

    public static void main(String[] args) {
    }
}
