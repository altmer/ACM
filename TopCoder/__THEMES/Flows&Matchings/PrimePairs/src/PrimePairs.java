import java.util.*;

public class PrimePairs {
    boolean prime[] = new boolean[2002];
    int[] nums, mt;
    boolean A[][];
    boolean col[];
    boolean used[];

    boolean kuhn(int u){
        if(used[u]) return false;
        used[u]=true;
        for (int v=0; v<nums.length; ++v){
            if(!col[v] && A[u][v]){
                if(mt[v]==-1 || kuhn(mt[v])){
                    mt[v]=u;
                    return true;
                }
            }
        }
        return false;
    }

    int[] matches(int[] numbers){
        nums=numbers;
        // Eratosphene
        Arrays.fill(prime, true);
        prime[1]=false;
        for (int i=2; i<=2000; ++i){
            if(prime[i]){
                int k=2*i;
                while(k<=2000){
                    prime[k]=false;
                    k+=i;
                }
            }
        }
        
        LinkedList<Integer> L = new LinkedList();

        A = new boolean[nums.length][nums.length];
        col = new boolean[nums.length];
        used = new boolean[nums.length];
        mt = new int[nums.length];
        for (int i=0; i<nums.length; ++i){
            for (int j=i+1; j<nums.length; ++j){
                if(prime[nums[i]+nums[j]]){
                    A[i][j]=A[j][i]=true;
                }
            }
        }

        col[0]=true;
        for (int i=1; i<nums.length; ++i){
            if(A[0][i]){
                col[i]=true;
                Arrays.fill(mt,-1);
                for (int j=1; j<nums.length; ++j){
                    if(!col[j]){
                        Arrays.fill(used, false);
                        kuhn(j);
                    }
                }
                int cnt=0;
                for (int j=1; j<nums.length; ++j){
                    if(mt[j]!=-1){
                        ++cnt;
                    }
                }
                if(cnt==(nums.length-2)){
                    L.add(nums[i]);
                }
                col[i]=false;
            }
        }

        int ret[] = new int[L.size()];
        int cur=0;
        for (Integer i : L){
            ret[cur++]=i;
        }
        Arrays.sort(ret);
        return ret;
    }

    public static void main(String[] args) {
        int[] arg = { 1, 4, 7, 10, 11, 12 };
        new PrimePairs().matches(arg);
    }
}
