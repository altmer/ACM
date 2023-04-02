import java.io.*;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;
    int n, m, k;

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

        StringTokenizer str = new StringTokenizer(in.readLine());

        n = Integer.parseInt(str.nextToken());
        m = Integer.parseInt(str.nextToken());
        k = Integer.parseInt(str.nextToken());


        str = new StringTokenizer(in.readLine());
        int ans = 0;
        int cnt = 0;

        while(cnt<n){
            ++cnt;
            if(!str.hasMoreTokens()) str = new StringTokenizer(in.readLine());
            int num = Integer.parseInt(str.nextToken());
            if(pow(num)==0){
                ++ans;
            }
        }

        out.println(ans);

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Solution().run();
    }

    private int pow(int num) {
        int step = m;
        int ret = 1;
        while(step>0){
            if((step&1)==1){
                step--;
                ret*=num;
                ret%=k;
            }else{
                step/=2;
                num*=num;
                num%=k;
            }
        }
        return ret;
    }
}
