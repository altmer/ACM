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
    int plus(char[] a, int ind){
        boolean carry = true;
        while(carry && ind>=0){
            if(a[ind]=='1')
                a[ind]='0';
            else{
                a[ind]='1';
                carry=false;
            }
            ind--;
        }
        return carry ? -1 : ind+1;
    }
    void run() throws Exception{
        init2();

        int n = Integer.parseInt(in.readLine().trim());
        char[] a = in.readLine().trim().toCharArray();
        char[] b = in.readLine().trim().toCharArray();

        // try to change b
        int tmp;
        boolean change = false;
        boolean bad = false;
        for (int i=0; i<n; ++i){
            if(change)
                 b[i]='0';
            else if(a[i]==b[i] && a[i]=='1'){
                tmp = i;
                while(a[tmp]==b[tmp] && a[tmp]=='1'){
                    tmp = plus(b,tmp);
                    if(tmp==-1)
                        break;
                }
                if(tmp==-1){
                    bad=true;
                    change = true;
                    break;
                }
                i=tmp;
                change = true;
            }
        }

        if(!change){
            plus(b,n-1);
            change = true;
        }
        while(!bad && change){
            change=false;
            for (int i=0; i<n; ++i){
                if(change)
                     b[i]='0';
                else if(a[i]==b[i] && a[i]=='1'){
                    tmp = i;
                    while((a[tmp]==b[tmp] && a[tmp]=='1')){
                        tmp = plus(b,tmp);
                        if(tmp==-1)
                            break;
                    }
                    if(tmp==-1){
                        bad=true;
                        change = true;
                        break;
                    }
                    i=tmp;
                    change = true;
                }
            }
        }

        if(bad){
            plus(a,n-1);
            for (int i=0; i<n; ++i)
                b[i]='0';
        }

        out.println(a);
        out.println(b);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
