import java.io.*;
import java.math.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
    void run() throws Exception{
        init2();
        BigInteger m = new BigInteger(in.readLine()), a = BigInteger.ONE, b = BigInteger.ZERO;
        BigInteger two = new BigInteger("2");

        if(m.equals(BigInteger.ZERO))
            out.println(0);
        else{
            m = m.multiply(two);
            for(;;){
                b = a.add(m.divide(a)).divide(two);
                if(a.equals(b))
                    break;
                a=b;
            }
            out.println(a.toString());
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
