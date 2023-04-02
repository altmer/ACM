/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author User
 */
public class SequenceSums {

    public int[] sequence(int N, int L){
        int[] ret=new int[0];

        for (int l=L; l<=100; ++l){
            int a1 = 2*N+l-l*l;
            if(a1>=0 && (a1%(2*l))==0){
                a1/=2*l;
                ret = new int[l];
                for (int i=a1; i<a1+l; ++i){
                    ret[i-a1]=i;
                }
                return ret;
            }
        }
        
        return ret;
    }
    public static void main(String[] args) {
        int[] ans = sequence(18,2);
    }

}
