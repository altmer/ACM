import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    int C[][];
    BigInteger mod = BigInteger.valueOf(2007L*2007L*2007L*2007L);
    BigInteger ppow[];

    void bin_coef(){
            C[0][0]=1;
            for (int i=1; i<20; ++i){
                    C[i][0]=1;
                    C[i][i]=1;
                    for (int j=1; j<i; ++j){
                            C[i][j]=C[i-1][j]+C[i-1][j-1];
                    }
            }
    }

    BigInteger pow(BigInteger a, BigInteger k){
            BigInteger ret=BigInteger.valueOf(1);
            while(k.compareTo(BigInteger.ZERO)>0){
                    if(k.getLowestSetBit()==0){
                            k = k.subtract(BigInteger.valueOf(1));
                            ret = ret.multiply(a).remainder(mod);
                    }else{
                            k = k.divide(BigInteger.valueOf(2));
                            a = a.multiply(a).remainder(mod);
                    }
            }
            return ret;
    }

    
    void run()throws Exception{
        in = new BufferedReader(new FileReader ("set.in"));
        out = new PrintWriter(new File("set.out"));
        
        ppow = new BigInteger[20];
        C = new int[100][100];
        mod = mod.multiply(mod).multiply(mod).multiply(mod).multiply(mod).multiply(BigInteger.valueOf(36288000L));
	bin_coef();

        int n,k;
        String[] res = in.readLine().split("\\s");
	n = Integer.parseInt(res[0]);
        k = Integer.parseInt(res[1]);
	for (int i=1; i<=10; ++i){
		ppow[i]=pow(BigInteger.valueOf(i),BigInteger.valueOf(n-1));
                //out.println(ppow[i]);
	}

	switch(k){
		case 1: out.println(1);
			break;
		default:
			int sign=1;
			int curind=0;
			BigInteger ans=BigInteger.ZERO;
			int fac=1;
			for(int i = 2;i<k-1;i++){
				fac*=i;
			}
			for (int j=k-1; j>=1; --j){
                            ans = mod.add(ans.add(BigInteger.valueOf(C[k-2][curind]).multiply(mod.add(ppow[k]).subtract(ppow[j]).remainder(mod)).multiply(BigInteger.valueOf(sign)).divide(BigInteger.valueOf((curind+1))))).remainder(mod);
                            ans = ans.remainder(mod);
                            curind++;
                            sign*=-1;
			}
                        ans = ans.divide(BigInteger.valueOf(fac)).remainder(BigInteger.valueOf(2007));
                        out.println(ans);

	}        
    

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }    
    
}
