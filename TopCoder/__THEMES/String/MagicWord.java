class MagicWords{
    int k;
    int ans=0;
    String[] cur;
    String[] s;
    boolean used[];

    int kmp(String p, String text){
        int ret=0;
        // failure function
        int F[] = new int[p.length()+1];
        F[0]=F[1]=0;
        for (int i=2; i<=p.length(); ++i){
            int j=F[i-1];
            for(;;){
                if(p.charAt(j)==p.charAt(i-1)){
                    F[i]=j+1;
                    break;
                }else if(j>0){
                    j=F[j];
                }else{
                    F[i]=0;
                    break;
                }            
            }
        }

        int i=0, j=0;
        for(;;){
            if(j==text.length()) return ret;
            if(p.charAt(i)==text.charAt(j)){
                i++;
                j++;
                if(i==p.length()){
                    i=F[i];
                    ++ret;
                }
            }else if(i>0){
                i=F[i];
            }else{
                j++;
            }
        }
    }

    void perm(int step){
        if(step==s.length){
            StringBuilder str = new StringBuilder();
            for (String c : cur){
                str.append(c);
            }
            if(kmp(str.toString(), str.toString()+str.toString())==k+1){
                ans++;
            }
            return;
        }
        for (int i=0; i<s.length; ++i){
            if(step==0 || !used[i]){
                cur[step]=s[i];
                used[i]=true;
                perm(step+1);
                used[i]=false;
            }
        }
    }

    int count(String[] S, int K){
        cur = new String[S.length];
        used = new boolean[S.length];
        s = S;
        k=K;
        perm(0);
        return ans;
    }
}


public class Main {
    public static void main(String[] args) {
    }
}
