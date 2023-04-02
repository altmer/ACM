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
        double ss = Double.parseDouble(in.readLine());
        double ll = Double.parseDouble(in.readLine());
        int s = (int)(ss*10000+1e-8);
        int l = (int)(ll*10000+1e-8);

        int ans = (s/l)*n;
        int q = s - (s/l)*l;
        int i=0;
        int res=0;
        while(i<n && q>0){
            ++i;
            if(res<q){
                ++ans;
                res=l;
            }
            res-=q;
        }
        out.println(ans);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
