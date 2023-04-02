import java.io.*;
import java.util.*;

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
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
        	init1();
        
        String s = in.readLine().trim();
        String[] ss = s.trim().split("\\s+");
        
        int k = Integer.parseInt(ss[0]);
        int n = Integer.parseInt(ss[1]);
        
        s = in.readLine().trim();
        ss = s.trim().split("\\s+");
        
        if (ss.length != n)
        	throw new Exception("Not n minutes!");
        
        int cur = 0;
        
        for (int i = 0; i < n; ++i){
        	int a = Integer.parseInt(ss[i]);
        	
        	cur += a;
        	
        	cur = Math.max(0, cur - k);
        }

        out.println(cur);
        
        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}