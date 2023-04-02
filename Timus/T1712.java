import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    boolean grid[][] = new boolean[4][4];
    boolean temp[][];
    char pass[][] = new char[4][];

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

        for (int i = 0; i < 4; ++i){
            String s = in.readLine();
            for (int j = 0; j < 4; ++j){
                grid[i][j] = s.charAt(j) == 'X';
            }
        }

        for (int i = 0; i < 4; ++i)
            pass[i] = in.readLine().toCharArray();

        StringBuilder ans = new StringBuilder(16);
        
        for (int k = 0; k < 4; ++k){
            for (int i = 0; i < 4; ++i){
                for (int j = 0; j < 4; ++j){
                    if(grid[i][j])
                        ans.append(pass[i][j]);
                }
            }

            turn();
        }

        out.println(ans.toString());

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Main().run();
    }

    private void turn() {
        temp = new boolean[4][4];
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j){
                temp[j][3 - i] = grid[i][j];
            }
        }
        grid = temp;
    }
}
