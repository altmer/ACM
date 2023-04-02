import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;


    class Day implements Comparable<Day>{
        int num, off;
        Day(){}
        Day(int a, int b) {num=a; off=b;}

        public int compareTo(Day o) {
            return num-o.num;
        }
    }

    Day[] days;
    int[] docs[], numdocs;
    boolean[] have, want;
    int[] ans;
    int cnt, curday;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }

    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
    boolean finish() {
        for (int i=0; i<want.length; ++i){
            if(want[i] && !have[i])
                return false;
        }
        return true;
    }

    void printans(){
        out.println(curday);
        for (int i=0; i<cnt; ++i){
            out.print(ans[i]);
            out.print(" ");
        }
        out.println();
    }
    
    void run() throws Exception{
        init2();

        String[] res = in.readLine().split("\\s");
        int n = Integer.parseInt(res[0]);
        int L = Integer.parseInt(res[1]);

        days = new Day[n];
        docs = new int[n][n];
        numdocs = new int[n];
        ans = new int[2*n];
        have = new boolean[n];
        want = new boolean[n];

        res = in.readLine().split("\\s");
        for (int i=0; i<n; ++i){
            days[i] = new Day(Integer.parseInt(res[i]), i);
        }

        Arrays.sort(days);

        for (int i=0; i<n; ++i){
            res = in.readLine().split("\\s");
            for (int j=0; j<res.length-1; ++j){
                docs[i][numdocs[i]++]=Integer.parseInt(res[j])-1;
            }
        }

        int k = Integer.parseInt(in.readLine());

        res = in.readLine().split("\\s");
        for (int i=0; i<res.length-1; ++i){
            have[Integer.parseInt(res[i])-1]=true;
        }
        res = in.readLine().split("\\s");
        for (int i=0; i<res.length-1; ++i){
            want[Integer.parseInt(res[i])-1]=true;
        }

        if(finish()){
            out.println(0);
            out.close();
            return;
        }

        // first week
        for (int i=0; i<n; ++i){
            if(days[i].num>=k){
                for (int j=i; j<n; ++j){
                    if(have[days[j].off]) continue;
                    boolean can=true;
                    for (int q=0; q<numdocs[days[j].off]; ++q){
                        if(!have[docs[days[j].off][q]]){
                            can=false;
                        }
                    }
                    if(can){
                        have[days[j].off]=true;
                        ans[cnt++]=days[j].off+1;
                        if(finish()){
                            curday=days[j].num-k;
                            printans();
                            out.close();
                            return;
                        }
                    }
                }
                break;
            }
        }

        curday = L-k;

        boolean fin=false;
        while(!fin){
            fin=true;
            for (int i=0; i<n; ++i){
                if(have[days[i].off]) continue;
                boolean can=true;
                for (int q=0; q<numdocs[days[i].off]; ++q){
                    if(!have[docs[days[i].off][q]]){
                        can=false;
                    }
                }
                if(can){
                    fin=false;
                    have[days[i].off]=true;
                    ans[cnt++]=days[i].off+1;
                    if(finish()){
                        curday+=days[i].num;
                        printans();
                        out.close();
                        return;
                    }
                }
            }
            curday+=L;
        }

        out.println("No Solution");

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
