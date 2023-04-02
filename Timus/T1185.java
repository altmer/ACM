import java.io.*;
import static java.lang.Math.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;
    static final double eps = 1e-8;

    class Point implements Comparable <Point>{
        double x, y;
        Point(){}
        Point(double _x, double _y) {x=_x;y=_y;}
        public int compareTo(Point o) {
            return (abs(y-o.y)<eps ? (abs(x-o.x)<eps ? (0) : (x<o.x ? -1 : 1)) : (y<o.y ? -1 : 1));
        }        
    }

    double lenHull(Point[] arr){
        double ret=0;
        int start=0;
        for (int i=0; i<arr.length; ++i){
            if(arr[start].compareTo(arr[i])>0)
                start=i;
        }
        int p=start;
        
        double dx=1.0;
        double dy=0.0;
        do{
            double coss=-2.0;
            double len=0.0;
            int next=-1;
            for (int i=0; i<arr.length; ++i){
                double sp = dx*(arr[i].x-arr[p].x) + dy*(arr[i].y-arr[p].y);
                double leng = sqrt((arr[i].x-arr[p].x)*(arr[i].x-arr[p].x)+(arr[i].y-arr[p].y)*(arr[i].y-arr[p].y));
                if(leng>eps){
                    double ccos=sp/leng;
                    if(ccos>coss || (abs(ccos-coss)<eps && leng>len)){
                        len=leng;
                        coss=ccos;
                        next=i;
                    }
                }
            }
            ret+=len;
            dx = (arr[next].x-arr[p].x)/len;
            dy = (arr[next].y-arr[p].y)/len;
            p=next;
        }while(p!=start);
        return ret;
    }

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

        String[] res = in.readLine().split("\\s");
        int n = Integer.parseInt(res[0]);
        int r = Integer.parseInt(res[1]);

        Point arr[] = new Point[n];
        for (int i=0; i<n; ++i){
            res = in.readLine().split("\\s");
            arr[i] = new Point(Integer.parseInt(res[0]), Integer.parseInt(res[1]));
        }

        double ans = lenHull(arr);
        ans+=(double)r*2.0*PI;
        
        out.println((int)(ans+0.5));

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
