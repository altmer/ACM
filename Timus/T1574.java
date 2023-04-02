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
        
        int op=0;
        int clos=0;
        int ans=0;
        char d[] = new char[200100];
        int dh=100020;
        int dt=100020;

        int bal=0;
        for (int i=0; i<n; ++i){
            if(s.charAt(i)=='('){
                bal++;
            }
            else
                bal--;
        }
        if(bal!=0){
            out.println(0);
            out.close();
            return;
        }

        for (int i=0; i<n; ++i){
            if(s.charAt(i)=='('){
                d[dt++]='(';
                op++;
            }else{
                if(op>0){
                    op--;
                    d[dt++]=')';
                }
                else{
                    clos++;
                    d[dt++]=')';
                    while(clos>0){
                        if(s.charAt(n-1)=='('){
                            clos--;
                            d[--dh]='(';
                        }else{
                            d[dt++]=')';
                            clos++;
                        }
                        n--;
                    }
                }
            }
        }

            bal=0;
            for (int i = dh; i<dt; ++i){
                if(d[i]=='('){
                    bal++;
                }
                else{
                    bal--;
                    if(bal==0)
                        ans++;
                }
            }

        out.println(ans);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
