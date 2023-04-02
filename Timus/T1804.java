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
        
        String s = in.readLine();
        int t = Integer.parseInt(s);
        
        for (int i = 0; i < t; ++i){
        	
        	s = in.readLine();
        	String[] ss = s.trim().split("\\s+");
        	
        	int scored = Integer.parseInt(ss[6]);
        	int conceded = Integer.parseInt(ss[10]);
        	
        	boolean homeScored = "home".equals( ss[3] ) ;
        	
        	// minimum needed
        	int ans = 0;
        	
        	if (scored > conceded){
        		ans = 0;
        	}else if (scored == conceded){
        		ans = homeScored && conceded != 0 ? 1 : 0;
        	}else{
        		ans = conceded - scored;
        		
        		int awayGoals = homeScored ? ans : scored;
        		int awayGoalsOpp = homeScored ? conceded : 0;

        		if (awayGoals < awayGoalsOpp)
        			ans++;
        		
        		if (ans > 30)
        			ans = 30;
        		if (ans < 0)
        			ans = 0;
        	}
        	
        	out.print(ans);
        	out.print(" ");
        	
        	ans = conceded + 30 - scored;
        	
        	int awayGoals = homeScored ? ans : scored;
    		int awayGoalsOpp = homeScored ? conceded : 30;
    		
    		if (awayGoals > awayGoalsOpp)
    			ans--;
    		
    		if (ans > 30)
    			ans = 30;
    		if (ans < 0)
    			ans = 0;
    		
        	out.println(ans);    		
        	
        }

        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}