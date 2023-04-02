import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    
    long[][] points;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }
	
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
    
    long findUnion(long a, long b, long c, long d){
    	long tmp1 = a;
    	long tmp2 = b;
    	a = Math.min(tmp1, tmp2);
    	b = Math.max(tmp1, tmp2);
    	tmp1 = c;
    	tmp2 = d;
    	c = Math.min(tmp1, tmp2);
    	d = Math.max(tmp1, tmp2);
    	
    	if (c > b || a > d)
    		return -1;
    	
    	if (c <= a && d >= b)
    		return Math.abs(a - b);
    	
    	if (a <= c && b >= d)
    		return Math.abs(c - d);
    	
    	if (a <= c)
    		return Math.abs(c - b);
    	
    	return Math.abs(a - d);
    }
	
    void run() throws Exception{
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();
        
        points = new long[4][2];
        
        for (int i = 0; i < 4; ++i){
        	String[] nums = in.readLine().trim().split("\\s");
        	points[i][0] = Long.parseLong(nums[0]);
        	points[i][1] = Long.parseLong(nums[1]);
        }


        long unX = findUnion(points[0][0], points[1][0], points[2][0], points[3][0]);
        long unY = findUnion(points[0][1], points[1][1], points[2][1], points[3][1]);
        
        if (unX == -1 || unY == -1){
        	out.println(0);
        	out.close();
        	return;
        }        	
        
        long difX1 = points[1][0] - points[0][0];
        long difY1 = points[1][1] - points[0][1];
        long difX2 = points[3][0] - points[2][0];
        long difY2 = points[3][1] - points[2][1];
        
        
        
        if ( (difX1 * difX2 >= 0 && difY1 * difY2 >= 0) || (difX1 * difX2 <= 0 && difY1 * difY2 <= 0) ){
        	// same route
        	out.println(unX + unY);
        }else{
        	// orthogonal routes
        	out.println(Math.max(unX, unY) );
        }
 
        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
