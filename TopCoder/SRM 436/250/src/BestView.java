
public class BestView {

    
    public int numberOfBuildings(int[] heights){
        int ans=0;
        for (int i=0; i<heights.length; ++i){
            int cnt=0;
            for (int j=0; j<heights.length; ++j){
                if(i==j) continue;
                if(canSee(i,j,heights)){
                    ++cnt;
                }
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] q = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
        new BestView().numberOfBuildings(q);
    }

    private boolean canSee(int fr, int to, int[] arr) {
        if(fr>to){            int tmp=to;           to=fr;            fr=tmp;        }
        
        for (int i=fr+1; i<to; ++i){
            double g = (double)arr[fr]+(double)(arr[to]-arr[fr])/((double)to-fr)*((double)i-fr);
            if(arr[i]>(double)arr[fr]+(double)(arr[to]-arr[fr])/((double)to-fr)*((double)i-fr) 
                    || arr[i]==(int)((double)arr[fr]+(double)(arr[to]-arr[fr])/((double)(to-fr))*((double)(i-fr)))){
                return false;
            }
        }
        return true;
    }
}
