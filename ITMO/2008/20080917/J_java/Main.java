import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        StreamTokenizer cin = new StreamTokenizer (new BufferedReader ( new FileReader(new File("sequence.in"))));
        PrintWriter cout = new PrintWriter (new File ("sequence.out" ) );
       
        BigInteger ans = new BigInteger("2");
        BigInteger two = new BigInteger("2");
        
        cin.nextToken();
        int n=(int)cin.nval;
        for (int i=0; i<n; ++i){
            BigInteger tmp = ans.subtract(two);
            ans = ans.add(tmp.multiply(two).add(two));
        }
        
        cout.println(ans);
        cout.close();

    }
}
