import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        /*
        BufferedReader in = new BufferedReader(new FileReader(new File ("input.txt")));
        PrintWriter out = new PrintWriter (new File("output.txt"));
         */

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter (System.out);
        

        int n = Integer.parseInt(in.readLine());
        int[][] A = new int[n][n];
        boolean[] used = new boolean[n*n+1];
        int lim = n*n + n/2 + 1;
        int max=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; ++j){
                for (int k=n*n; k>=1; --k){
                    if(!used[k] && (i==0 || A[i-1][j]+k<=lim) && (j==0 || A[i][j-1]+k<=lim)){
                        A[i][j]=k;
                        if(i>0)
                            max = Math.max(max, A[i-1][j]+k);
                        if(j>0)
                            max = Math.max(max, A[i][j-1]+k);
                        used[k]=true;
                        break;
                    }
                }
            }
        }
        out.println(max);
        for (int[] a : A){
            for (int val : a){
                out.print(val + " ");
            }
            out.println();
        }
        in.close();
        out.close();
    }
}
