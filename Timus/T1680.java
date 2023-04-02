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

        Set<String> mp  = new HashSet();
        String[] res = in.readLine().split("\\s");
        int n = Integer.parseInt(res[1]);
        int q = Integer.parseInt(res[2]);

        int cnt=0;
        for (int i=0; i<n; ++i){
            String s = in.readLine().trim();
            String vuz;
            int ind;
            if((ind=s.indexOf('#'))!=-1){
                vuz = s.substring(0, ind).trim();
            }else{
                vuz=s;
            }
            if(!mp.contains(vuz)){
                mp.add(vuz);
                cnt++;
            }
            if(cnt==q+1){
                out.println(s);
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
