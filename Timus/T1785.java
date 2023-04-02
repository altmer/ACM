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
        int l =  Integer.parseInt(s);
        
        if (l < 5)
        	out.println("few");
        else if (l < 10)
        	out.println("several");
        else if (l < 20)
        	out.println("pack");
        else if (l < 50)
        	out.println("lots");
        else if (l < 100)
        	out.println("horde");
        else if (l < 250)
        	out.println("throng");
        else if (l < 500)
        	out.println("swarm");
        else if (l < 1000)
        	out.println("zounds");
        else
        	out.println("legion");

        in.close();
        out.close();
    }
	
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}