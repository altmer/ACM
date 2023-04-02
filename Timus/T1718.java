import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    class Pair{
        boolean min, max;

        Pair(boolean min, boolean max){
            this.min = min;
            this.max = max;
        }
    }

    Map<String, Pair> map = new HashMap<String, Pair> ();

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

        int n = Integer.parseInt(in.readLine().trim());

        for (int i = 0; i < n; ++i){
            String res[] = in.readLine().split("\\s");
            Pair p = map.get(res[0]);
            if (p==null) p = new Pair(false, false);

            if (res[1].equals("AC")){
                p.max = true;
                map.put(res[0], p);
            }else if (res.length > 2){
                int test = Integer.parseInt(res[2]);
                if (test == 6)
                    p.max = true;
                if(test == 7){
                    p.min = true;
                    p.max = true;
                }
                map.put(res[0], p);
            }
        }

        int min = 0, max = 0;
        for (Map.Entry<String, Pair> e : map.entrySet()){
            min += e.getValue().min ? 1 : 0;
            max += e.getValue().max ? 1 : 0;
        }

        out.print(min);
        out.print(" ");
        out.print(max);

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
