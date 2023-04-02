import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader in = new BufferedReader (new FileReader (new File("conv.in")));
        PrintWriter out = new PrintWriter ("conv.out");
        StringTokenizer tok = new StringTokenizer(in.readLine());
        
        int A = Integer.valueOf(tok.nextToken());
        int B = Integer.valueOf(tok.nextToken());
        BigInteger bA = BigInteger.valueOf(A);
        BigInteger bB = BigInteger.valueOf(B);
        BigInteger cA = BigInteger.ONE;
        BigInteger cB=BigInteger.ONE;
   
        char[] s = in.readLine().toCharArray();
        BigInteger a = BigInteger.ZERO;
        for (int i=s.length-1; i>=0; --i){
            int dig = s[i]>='0' && s[i]<='9' ? s[i]-'0' : 10+s[i]-'A';
            a = a.add(BigInteger.valueOf(dig).multiply(cA));
            cA = cA.multiply(bA);
        }

        if(a.compareTo(BigInteger.ZERO)==0){
            out.println(0);
            in.close();
            out.close();
            return;
        }
        
        if(a.compareTo(BigInteger.ZERO)<0){
            int j=0;
            j/=j;
        }
        //char[] num = a.toString().toCharArray();
        StringBuffer ans = new StringBuffer();
        
        
        if(B>0){
            while(!a.equals(BigInteger.ZERO)){
                long dig=a.mod(bB).longValue();
                char ch = dig>9 ? (char)('A'+dig-10) : (char)(dig+'0');
                ans.append(ch);
                a = a.divide(bB);
            }
            out.println(ans.reverse());
        }
        else{
            
            long[] nums = new long[B*B];
            char[][] digs = new char[B*B][2];
            for (int i=0; i<Math.abs(B); ++i){
                for (int j=0; j<Math.abs(B); ++j){
                    nums[i*Math.abs(B)+j] = Math.abs(B)*i - j;
                    digs[i*Math.abs(B)+j][1]=i>9 ? (char)('A'+i-10) : (char)(i+'0');
                    digs[i*Math.abs(B)+j][0]=j>9 ? (char)('A'+j-10) : (char)(j+'0');
                }
            }
            
            /* some bullshit
            while(cB.multiply(BigInteger.valueOf(Math.abs(B)-1)).compareTo(a)<0){
                cB = cB.multiply(bB);
            }
            while(!cB.equals(BigInteger.ZERO)){
                long dig=a.abs().divide(cB.abs()).longValue();
                if(!a.abs().mod(cB.abs()).equals(BigInteger.ZERO)){
                    dig++;
                }
                dig = Math.min(dig, Math.abs(B)-1);
                BigInteger tmp = a.subtract(cB.multiply(BigInteger.valueOf(dig)));
                if(a.compareTo(BigInteger.ZERO)<0 && tmp.compareTo(a)<0 || 
                       a.compareTo(BigInteger.ZERO)>0 && tmp.compareTo(a)>0 ){
                    ans.append('0');
                }
                else{
                    char ch = dig>9 ? (char)('A'+dig-10) : (char)(dig+'0');
                    ans.append(ch);
                    a=tmp;
                }
                    
                cB = cB.divide(bB);
            }
            out.println(ans);
             */
            long dig=a.mod(bB.abs()).longValue();
            char ch = dig>9 ? (char)('A'+dig-10) : (char)(dig+'0');
            ans.append(ch);
            a = a.divide(bB.abs());
            while(!a.equals(BigInteger.ZERO)){
                // CAUTION!
                long tmp = a.mod(bB.abs()).longValue();
                
                for (int i=0; i<nums.length; ++i){
                    if(nums[i]==tmp){
                        ans.append(digs[i]);
                        break;
                    }
                }
                // ACHTUNG!
                a = a.divide(bB.multiply(bB));
            }
            out.println(ans.reverse());
        }
        
        // out.println(a);
                
        in.close();
        out.close();
    }
}
