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
        init2();

        String s = in.readLine();
        int n = s.length();

        int res = n*(n+1)/2;
        int F[] = new int[n+1];
        
        for (int i=0; i<n-1; ++i){
            F[0]=F[1]=0;
            int ans=0;
            for (int j=2; j<=s.length(); ++j){
                int k = F[j-1];
                for(;;){
                    if(s.charAt(k)==s.charAt(j-1)){
                        F[j]=k+1;
                        ans = Math.max(ans, F[j]);
                        break;
                    }else if (k>0){
                        k = F[k];
                    }else{
                        F[j]=0;
                        break;
                    }
                }
            }
            res-=ans;
            s = s.substring(1);
        }

        out.println(res);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
