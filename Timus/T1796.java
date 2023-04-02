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
        
        long[] nom = {10, 50, 100, 500, 1000, 5000};
        long[] num = new long[nom.length];
        
        long sum = 0;
        long min_nom = -1;
        
        for (int i = 0; i < nom.length; ++i){
        	
        	num[i] = Long.parseLong(ss[i]);
        	
        	sum += num[i] * nom[i];
        	
        	if (min_nom == -1 && num[i] != 0)
        		min_nom = nom[i];
        	
        }
        
        s = in.readLine().trim();
        long tick = Long.parseLong(s);
        
        long min_sum = sum - min_nom;
        
        long min_ans = min_sum / tick + 1;
        long max_ans = sum/tick;        
        
        out.println(max_ans - min_ans + 1);
        for (long i = min_ans; i <= max_ans; ++i){
        	out.print (i);
        	out.print(" ");
        }
        
        out.println();
        
        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}