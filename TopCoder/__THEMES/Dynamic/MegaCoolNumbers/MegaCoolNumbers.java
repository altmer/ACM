class MegaCoolNumbers{
    static final int MOD = 1000000007;
    int count(int N, int A){
        if(A>9)
            return 0;

        int[][][][] F = new int[N+1][10][10][10];

        for (int d=1; d<=9; ++d){
            F[1][1][9][d]=1;
        }

        for (int i=1; i<N; ++i){
            for (int pow=1; pow<=9; ++pow){
                for (int last=1; last<=9; ++last){
                    for (int d=last; d<=9; ++d){
                        F[i+1][pow][d-last][d]+=F[i][pow][9][last];
                        F[i+1][pow][d-last][d]%=MOD;
                    }
                    for (int diff=0; diff<=8; ++diff){
                        for (int d=last; d<=9; ++d){
                            if(d-last==diff){
                                F[i+1][pow][diff][d]+=F[i][pow][diff][last];
                                F[i+1][pow][diff][d]%=MOD;
                            }else{
                                F[i+1][pow+1][9][d] += F[i][pow][diff][last];
                                F[i+1][pow+1][9][d] %= MOD;
                            }
                        }
                    }
                }
            }
        }
        
        int ret=0;
        for (int last=1; last<=9; ++last){
            for (int diff=1; diff<=9; ++diff){
                ret= (ret + F[N][A][diff][last])%MOD;
            }
        }
        return ret;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
