import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class SortingWithPermutation{
    public int[] getPermutation(int[] a){
        int[] b = new int [1100];
        int[] ret = new int[a.length];
        for (int i=0; i<a.length; ++i){
            b[a[i]]++;
        }
        for (int i=1; i<b.length; ++i){
            b[i]+=b[i-1];
        }
        for (int i=a.length-1; i>=0; --i){
            ret[i]=(b[a[i]]--) - 1;
        }
        return ret;
    }
}

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }

}
