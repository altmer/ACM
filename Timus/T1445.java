import java.io.*;

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
        init2();

        int n = Integer.parseInt(in.readLine());
        String[] inp = in.readLine().split("\\s");
        int sum = 0;
        int max=0;
        for (String s : inp){
            int cur = Integer.parseInt(s);
            max=Math.max(max, cur);
            sum+=cur;
        }

        out.print(2*max-sum <= 0 ? 1 : 2*max-sum);
        out.println(" " + max);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
