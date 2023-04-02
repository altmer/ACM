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

        int[] circles = new int[4];
        for (int i = 0; i < 4; ++i){
        	circles[i] = Integer.parseInt(ss[i]);
        }
        
        int[] leaves = new int[3];
        for (int i = 0; i < 3; ++i){
        	leaves[i] = Integer.parseInt(ss[i + 4]);
        }
        
        int[] rLeaves = new int[3];
        
        rLeaves[0] = (circles[1] + circles[2] + circles[3]) % 2;
        rLeaves[1] = (circles[0] + circles[2] + circles[3]) % 2;
        rLeaves[2] = (circles[0] + circles[1] + circles[3]) % 2;
        
        if (
        		rLeaves[0] != leaves[0] &&
        		rLeaves[1] != leaves[1] &&
        		rLeaves[2] != leaves[2]
        	){
        	
        	circles[3] = 1 - circles[3];
        	
        } else if (
        		rLeaves[0] != leaves[0] &&
            	rLeaves[1] != leaves[1]
        	){
        	
        	circles[2] = 1 - circles[2];
        	
        } else if (
        		rLeaves[0] != leaves[0] &&
            	rLeaves[2] != leaves[2]
        	){
        	
        	circles[1] = 1 - circles[1];
        	
        } else if (
        		rLeaves[2] != leaves[2] &&
            	rLeaves[1] != leaves[1]
        	){
        	
        	circles[0] = 1 - circles[0];
        	
        }else if (rLeaves[0] != leaves[0]){
        	leaves[0] = rLeaves[0];
        }else if (rLeaves[1] != leaves[1]){
        	leaves[1] = rLeaves[1];
        }else if (rLeaves[2] != leaves[2]){
        	leaves[2] = rLeaves[2];
        }
        
        for (int i = 0; i < 4; ++i){
        	out.print(circles[i]);
        	out.print(" ");
        }
        for (int i = 0; i < 3; ++i){
        	out.print(leaves[i]);
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