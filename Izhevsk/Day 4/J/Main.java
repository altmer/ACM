import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    
    String[][] sent;
    int[] lens;
    int ans = 0;
    int cnt=0;
    int cursent;
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    void preprocess(int ind){
        for (int i=0; i<lens[ind]; ++i){
            if(sent[ind][i].equalsIgnoreCase("can") || sent[ind][i].equalsIgnoreCase("may") || sent[ind][i].equalsIgnoreCase("must") || sent[ind][i].equalsIgnoreCase("should")){
                ++ans;
            }else if(sent[ind][i].equalsIgnoreCase("is") || sent[ind][i].equalsIgnoreCase("are")){
                ++ans;
            }
        }
    }
    void process(int ind){
        for (int i=0; i<lens[ind]; ++i){
            if(sent[ind][i].equalsIgnoreCase("can") || sent[ind][i].equalsIgnoreCase("may") || sent[ind][i].equalsIgnoreCase("must") || sent[ind][i].equalsIgnoreCase("should")){
                ++cnt;
                for (int j=0; j<=i; ++j){
                    out.print(sent[ind][j]);
                    out.print(" ");
                }
                out.print("not");
                for (int j=i+1; j<lens[ind]; ++j){
                    out.print(" ");
                    out.print(sent[ind][j]);
                }
                out.print('.');
                /*
                if(ind!=cursent-1)
                    out.print(' ');
                 */
                out.println();
            }else if(sent[ind][i].equalsIgnoreCase("is") || sent[ind][i].equalsIgnoreCase("are")){
                ++cnt;
                for (int j=0; j<=i; ++j){
                    out.print(sent[ind][j]);
                    out.print(" ");
                }
                out.print("no");
                int j=-1;
                if(i+1<lens[ind] && (sent[ind][i+1].equalsIgnoreCase("a") || sent[ind][i+1].equalsIgnoreCase("the"))){
                    j=i+2;
                }else j=i+1;
                for ( ; j<lens[ind]; ++j){
                    out.print(" ");
                    out.print(sent[ind][j]);
                }
                out.print('.');
                /*
                if(ind!=cursent-1)
                    out.print(' ');
                 */
                out.println();
            }
        }
    }
    void run()throws Exception{
        in = new BufferedReader(new FileReader ("xyzx2009.in"));
        out = new PrintWriter(new File("xyzx2009.out"));
        
        sent = new String[1200][1200];
        lens = new int[1200];
        
        cursent=0;
        boolean fin=false;
        do{
            String s = in.readLine();
            String[] res = s.split("\\s");
            for (int i=0; i<res.length; ++i){
                if(res[i].charAt(res[i].length()-1)=='.'){
                    sent[cursent][lens[cursent++]++]=res[i].substring(0,res[i].length()-1);
                    preprocess(cursent-1);
                    if(i+1==res.length){
                        fin = s.charAt(s.length()-1)!=' ';
                    }
                }else{
                    sent[cursent][lens[cursent]++]=res[i];
                }
            }
        }while(!fin);
        
        out.println(ans);
        for (int i=0;cnt <ans && i<cursent; ++i){
            process(i);
        }
        
        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }    
    
}
