import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    
    String digits;
    boolean[] found;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
	
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
	
    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();
        
        digits = in.readLine().trim();
        found = new boolean[10000001];
        
        for (int numDigits = 1; numDigits <= 6; ++numDigits){
        	for (int i = 0; i + numDigits - 1 < digits.length(); ++i){
        		int res = Integer.parseInt( digits.substring(i, i + numDigits) );
        		found[res] = true;        		
        	}
        }
        
        for (int i = 1; i <= 9999999; ++i){
        	if (!found[i]){
        		out.println(i);
        		break;
        	}
        }

        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
