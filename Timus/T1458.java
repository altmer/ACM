import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    int[] wr, wc, br, bc;
    char[][] table;
    int[][] nw, nb;
    int answ=0, ansb=0;

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
        wr = new int[n];
        wc = new int[n];
        br = new int[n];
        bc = new int[n];
        nw = new int[n][n];
        nb = new int [n][n];
        table = new char[n][];

        for (int i=0; i<n; ++i){
            table[i]=in.readLine().toCharArray();
            for (int j=0; j<n; ++j){
                if(table[i][j]=='W'){
                    wr[i]++;
                    wc[j]++;
                }
                else{
                    br[i]++;
                    bc[j]++;
                }
            }
        }

        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                nw[i][j]=wr[i]+wc[j]-((table[i][j]=='W')? 1 : 0);
                if((nw[i][j]&1)==0)
                    answ++;
                nb[i][j]=br[i]+bc[j]-((table[i][j]=='B')? 1 : 0);
                if((nb[i][j]&1)==0)
                    ansb++;
            }
        }

        if(answ<ansb){
            out.println(answ);
            for (int i=0; i<n; ++i){
                for (int j=0; j<n; ++j){
                    if((nw[i][j]&1)==0){
                        out.print(i+1);
                        out.print(" ");
                        out.println(j+1);
                    }
                }
            }
        }
        else{
            out.println(ansb);
            for (int i=0; i<n; ++i){
                for (int j=0; j<n; ++j){
                    if((nb[i][j]&1)==0){
                        out.print(i+1);
                        out.print(" ");
                        out.println(j+1);
                    }
                }
            }
        }

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
