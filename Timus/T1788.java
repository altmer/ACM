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

        String s =  in.readLine();
        String[] ss = s.trim().split("\\s+");

        int n = Integer.parseInt(ss[0]);
        int m = Integer.parseInt(ss[1]);
        
        int[] g = new int[n];
        int[] b = new int[m];
        
        s =  in.readLine();
        ss = s.trim().split("\\s+");
        
        for (int i = 0; i < n; ++i){
        	g[i] = Integer.parseInt(ss[i]);
        }
        
        s =  in.readLine();
        ss = s.trim().split("\\s+");
        
        for (int i = 0; i < m; ++i){
        	b[i] = Integer.parseInt(ss[i]);
        }
        
        Arrays.sort(g);
        Arrays.sort(b);
        
        int ans = Integer.MAX_VALUE;
        
        for (int k = 0; k <= Math.min(n, m); ++k){
        	int cur = 0;
        	
        	for (int i = 0; i < n - k; ++i)
        		cur += g[i];
        	
        	for (int i = 0; i < m - k; ++i)
        		cur += b[i] * k;
        	
        	ans = Math.min(ans, cur);
        }
        
        out.println(ans);
        
        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}