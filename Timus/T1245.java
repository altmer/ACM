import java.io.*;
import java.util.*;

class Circle{
    int r, x, y;
}

public class Main {
    BufferedReader in;
    PrintWriter out;
    Circle[] arr;
    int[] xc, yc, col;
    int best = Integer.MAX_VALUE;

    void run()throws Exception{
        /*
        in = new BufferedReader (new FileReader (new File("input.txt")));
        out = new PrintWriter (new File("output.txt"));
        */

        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out);


        int n = Integer.parseInt(in.readLine());
        int N = 2*n;
        xc = new int [N];
        yc = new int[N];
        col = new int[n];
        arr = new Circle[n];
        for (int i=0; i<n; ++i){
            StringTokenizer str = new StringTokenizer(in.readLine());
            arr[i] = new Circle();
            arr[i].r=Integer.parseInt(str.nextToken());
            arr[i].x=Integer.parseInt(str.nextToken());
            arr[i].y=Integer.parseInt(str.nextToken());
            xc[2*i]=arr[i].x-arr[i].r;
            xc[2*i+1]=arr[i].x+arr[i].r;
            yc[2*i]=arr[i].y-arr[i].r;
            yc[2*i+1]=arr[i].y+arr[i].r;
        }
        for (int i=0; i<N; ++i){
            boolean good=true;
            int cnt1=0, cnt2=0;
            for (int j=0; j<n; ++j){
                if (arr[j].x-arr[j].r<=xc[i] && arr[j].x+arr[j].r<=xc[i]){
                    col[j]=1;
                    ++cnt1;
                }
                else if (arr[j].x-arr[j].r>=xc[i] && arr[j].x+arr[j].r>=xc[i]){
                    col[j]=2;
                    ++cnt2;
                }
                else{
                    good=false;
                    break;
                }
            }
            if(good){
                int L1=Integer.MAX_VALUE, L2 = Integer.MAX_VALUE, R1=Integer.MIN_VALUE, R2=Integer.MIN_VALUE,
                        H1=Integer.MIN_VALUE, H2 = Integer.MIN_VALUE, B1=Integer.MAX_VALUE, B2 = Integer.MAX_VALUE;
                for (int j=0; j<n; ++j){
                    if(col[j]==1){
                        L1=Math.min(L1, arr[j].x-arr[j].r);
                        R1=Math.max(R1, arr[j].x+arr[j].r);
                        B1=Math.min(B1, arr[j].y-arr[j].r);
                        H1=Math.max(H1, arr[j].y+arr[j].r);
                    }
                    else{
                        L2=Math.min(L2, arr[j].x-arr[j].r);
                        R2=Math.max(R2, arr[j].x+arr[j].r);
                        B2=Math.min(B2, arr[j].y-arr[j].r);
                        H2=Math.max(H2, arr[j].y+arr[j].r);
                    }
                }
                int W1=R1-L1;
                int HE1=H1-B1;
                int W2=R2-L2;
                int HE2=H2-B2;
                W1=Math.max(100, W1);
                HE1=Math.max(100, HE1);
                W2=Math.max(100, W2);
                HE2=Math.max(100, HE2);
                if(cnt1==0)
                    W1=HE1=0;
                if(cnt2==0)
                    W2=HE2=0;
                best=Math.min(best, W1*HE1+W2*HE2);
            }
        }

        for (int i=0; i<N; ++i){
            boolean good=true;
            int cnt1=0, cnt2=0;
            for (int j=0; j<n; ++j){
                if (arr[j].y-arr[j].r<=yc[i] && arr[j].y+arr[j].r<=yc[i]){
                    col[j]=1;
                    ++cnt1;                }
                else if (arr[j].y-arr[j].r>=yc[i] && arr[j].y+arr[j].r>=yc[i]){
                    col[j]=2;
                    ++cnt2;
                }
                else{
                    good=false;
                    break;
                }
            }
            if(good){
                int L1=Integer.MAX_VALUE, L2 = Integer.MAX_VALUE, R1=Integer.MIN_VALUE, R2=Integer.MIN_VALUE,
                        H1=Integer.MIN_VALUE, H2 = Integer.MIN_VALUE, B1=Integer.MAX_VALUE, B2 = Integer.MAX_VALUE;
                for (int j=0; j<n; ++j){
                    if(col[j]==1){
                        L1=Math.min(L1, arr[j].x-arr[j].r);
                        R1=Math.max(R1, arr[j].x+arr[j].r);
                        B1=Math.min(B1, arr[j].y-arr[j].r);
                        H1=Math.max(H1, arr[j].y+arr[j].r);
                    }
                    else{
                        L2=Math.min(L2, arr[j].x-arr[j].r);
                        R2=Math.max(R2, arr[j].x+arr[j].r);
                        B2=Math.min(B2, arr[j].y-arr[j].r);
                        H2=Math.max(H2, arr[j].y+arr[j].r);
                    }
                }
                int W1=R1-L1;
                int HE1=H1-B1;
                int W2=R2-L2;
                int HE2=H2-B2;
                W1=Math.max(100, W1);
                HE1=Math.max(100, HE1);
                W2=Math.max(100, W2);
                HE2=Math.max(100, HE2);
                if(cnt1==0)
                    W1=HE1=0;
                if(cnt2==0)
                    W2=HE2=0;
                best=Math.min(best, W1*HE1+W2*HE2);
            }
        }

        out.println(best);

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception {
        new Main().run();
    }
}
