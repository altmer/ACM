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

        char[] str1 = in.readLine().toCharArray(), str2 = in.readLine().toCharArray();
        int n = str1.length;
        int m = str2.length;

        char[] str = new char[str1.length+str2.length+1];
        int[] pref = new int[str.length+1];
        
        for (int i=0; i<n; ++i)
            str[i]=str1[i];

        str[n]='$';
        
        for (int j=0; j<m; ++j){
            str[n+1+j]=str2[j];
        }

        int len = n+m+1;
        pref[0]=pref[1]=0;
        for (int i=2; i<=len; ++i){
            int j=pref[i-1];
            for(;;){
                if(str[i-1]==str[j]){
                    pref[i]=j+1;
                    break;
                }else if(j>0){
                    j=pref[j];
                }else{
                    pref[i]=0;
                    break;
                }
            }
        }

        int[] par = new int[m+1];
        Arrays.fill(par, -1);

        boolean[] dost = new boolean [m+1];
        dost[0]=true;

        int[] dist = new int[m+1];
        Arrays.fill(dist, Integer.MAX_VALUE);


        for (int i=n+2; i<=len; ++i){
            int ind=i-n-1;
            if(dost[ind-pref[i]] && dist[ind-pref[i]]+1<dist[ind]){
                dost[ind]=true;
                dist[ind]=dist[ind-pref[i]]+1;
                par[ind]=ind-pref[i];                
            }
        }

        if(dost[m]){
            out.println("No");
            Deque<Integer> ans = new LinkedList();
            int k=m;
            while(k!=-1){
                ans.addLast(k);
                k=par[k];
            }
            int st = ans.pollLast();
            int st2 = ans.pollLast();
            for (int j=st; j<st2; ++j){
                out.print(str2[j]);
            }
            out.print(" ");
            while(!ans.isEmpty()){
                st=st2;
                st2=ans.pollLast();
                for (int j=st; j<st2; ++j){
                    out.print(str2[j]);
                }
                out.print(" ");
            }
            out.println();
        }else out.println("Yes");

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
