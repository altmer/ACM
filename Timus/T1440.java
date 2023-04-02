import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    Map <String, Integer> month = new HashMap<String,Integer>();
    Map <String, Integer> day = new HashMap<String,Integer>();
    String[] nMonth = {"September", "October", "November", "December"};
    int[] numdays = {30,31,30,31};
    String[] nDay = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int[] num = new int[7];
    boolean[] used = new boolean[7];
    int nused=0;
    int sum=0;

    int A, B;

    boolean rec(int ind){
        if(sum>=A && sum<=B)
            return true;
        if(sum>B)
            return false;
        if(ind==7)
            return false;

        sum+=num[ind];
        nused++;
        used[ind]=true;
        if(rec(ind+1))
            return true;
        sum-=num[ind];
        nused--;
        used[ind]=false;
        return rec(ind+1);
    }

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
        for (int i=0; i<nMonth.length; ++i ){
            month.put(nMonth[i], i);
        }
        for (int i=0; i<nDay.length; ++i ){
            day.put(nDay[i], i);
        }

        int fd = (day.get(in.readLine())+1)%7;
        int fday=1;
        int fmonth = 0;

        String[] res = in.readLine().split("\\s");
        int tmonth = month.get(res[0]);
        int tday = Integer.parseInt(res[1])-1;

        res = in.readLine().split("\\s");
        A = Integer.parseInt(res[0]);
        B = Integer.parseInt(res[1]);

        while(fday!=tday || fmonth!=tmonth){
            num[fd]++;
            fday++;
            if(fday==numdays[fmonth]){
                fday=0;
                fmonth++;
            }
            fd++;
            fd%=7;
        }

        if(rec(0)){
            out.println(nused);
            for (int i=0;i<7; ++i){
                if(used[i])
                    out.println(nDay[i]);
            }
        }
        else
            out.println("Impossible");

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
