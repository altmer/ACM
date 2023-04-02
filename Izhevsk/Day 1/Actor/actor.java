import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    int ptr;
    int pos;
    String[] trag;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("actor.in")));
        out = new PrintWriter("actor.out");
    }

    int rec (boolean seq){
        int ret=0;
        for (int i=pos+1; i<trag.length; ++i){
            if(trag[i].equals("$")){
                if(seq){
                    ret = Math.max(ret, 1);
                }else{
                    ret++;
                }
            }else if(trag[i].equals("SEQL")){
                pos = i+1;
                if(seq){
                    ret = Math.max(ret, rec(true));
                }else{
                    ret+=rec(true);
                }
                i=pos;
            }else if(trag[i].equals("PAR")){
                pos = i+1;
                if(seq){
                    ret = Math.max(ret, rec(false));
                }else{
                    ret+=rec(false);
                }
                i=pos;
            }else if(trag[i].equals("}")){
                pos=i;
                break;
            }
        }
        return ret;
    }
    
    void run() throws Exception{
        init1();

        StringBuilder text = new StringBuilder();
        String s;
        while(in.ready()){
            s = in.readLine();
            text.append(s);
        }

        Matcher mt = Pattern.compile("PAR|\\x7b|\\x7d|SEQL|\\x24").matcher(text);

        trag = new String[11000];
        ptr=0;
        trag[ptr++]="SEQL";
        trag[ptr++]="{";

        boolean nextCl=false;
        while(mt.find()){
            String cur = text.substring(mt.start(), mt.end());
            if(cur.equals("{") && !trag[ptr-1].equals("PAR") && !trag[ptr-1].equals("SEQL")){
                nextCl=true;
                continue;
            }
            if(cur.equals("}") && nextCl){
                nextCl=false;
                continue;
            }
            trag[ptr++] = cur;
        }

        trag[ptr++]="}";

        pos=1;
        out.println(rec(true));

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
