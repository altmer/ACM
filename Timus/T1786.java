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
    
	private static final String PATTERN = "Sandro"; 
	
    int numberOfChanges(String s){
    	
    	int res = 0;
    	
    	if (Character.isLowerCase(s.charAt(0))){
    		res += 5;
    	}
    	
    	if (s.charAt(0) != 's' && s.charAt(0) != 'S')
    		res += 5;
    	
    	for (int i = 1; i < s.length(); ++i){
    		if (Character.isUpperCase( s.charAt(i) ) )
    			res += 5;
    		
    		if (Character.toLowerCase(s.charAt(i)) != PATTERN.charAt(i))
    			res += 5;
    	}
    	
    	return res;
    }
    
    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
        	init1();

        String s = in.readLine().trim();
        
        int ans = Integer.MAX_VALUE;
        
        for (int i = 0; i <= s.length() - 6; ++i){
        	String cur = s.substring(i, i + 6);
        	
        	ans = Math.min(ans, numberOfChanges(cur));
        }
        
        out.println(ans);
        
        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}