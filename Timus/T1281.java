import java.io.*;
import java.util.*;


class Point implements Comparable{
    public double x=-1001, y=-1001;
    Point(){}
    Point(double _x, double _y) {x=_x;y=_y;}

    public int compareTo(Object o) {
        Point p=(Point)o;
        if(Math.abs(p.y-this.y)<1e-8){
            return this.x<p.x ? -1 : 1;
        }
        return this.y<p.y ? -1 : 1;
    }
    public boolean equals(Point p){
        return Math.abs(this.x-p.x)<1e-8 && Math.abs(this.y-p.y)<1e-8;
    }
}

public class Main {
    BufferedReader in;
    PrintWriter out;
    Point[][] rivers;
    int[] col;
    boolean used[];
    double ans;

    double square(Point[] arr){
        int start=0;
        if(arr.length<3)
            return 0;
        Point[] obol= new Point[arr.length+1];
        int end=0;
        for (int i=1; i<arr.length; ++i){
            if(arr[i].compareTo(arr[start])<0){
                start = i;
            }
        }
        int p=start;
        double dx=1.0;
        double dy=0;
        obol[end++]=arr[start];
        
        do{
            double coss = -2.0;
            double len = 0;
            int next=-1;
            for (int i=0; i<arr.length; ++i){
                double sp = dx*(arr[i].x-arr[p].x) + dy*(arr[i].y-arr[p].y);
                double leng = Math.sqrt((arr[i].x-arr[p].x)*(arr[i].x-arr[p].x)+(arr[i].y-arr[p].y)*(arr[i].y-arr[p].y));
                if(leng>1e-8){
                    double ccos=sp/leng;
                    if(ccos>coss){
                        next=i;
                        coss=ccos;
                        len=leng;
                    }
                }
            }
            if(next==-1)
                return 0;
            obol[end++]=arr[next];
            dx=(arr[next].x-arr[p].x)/len;
            dy=(arr[next].y-arr[p].y)/len;
            p=next;
        }while(p!=start);

        double ret=0;
        for (int i=0; i<end-1; ++i){
            ret+=obol[i].x*obol[i+1].y-obol[i].y*obol[i+1].x;
        }
        return Math.abs(ret)/2.0;
    }
    
    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter (new File("output.txt"));
    }
    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter (System.out);
    }
    void run()throws Exception{
        init2();
        int n = Integer.parseInt(in.readLine());
        rivers = new Point[n][];

        for (int i=0; i<n; ++i){
            int m = Integer.parseInt(in.readLine());
            rivers[i] = new Point[m];
            for (int j=0; j<m; ++j){
                StringTokenizer str = new StringTokenizer(in.readLine());
                rivers[i][j]= new Point(Double.parseDouble(str.nextToken()),Double.parseDouble(str.nextToken()));
            }
        }

        col = new int[rivers.length];
        for (int i=0; i<col.length; ++i){
            col[i]=i;
        }

        for (int i=0; i<rivers.length; ++i){
            lab:
            for (int j=0; j<rivers.length; ++j){
                if(i==j)
                    continue;
                for (Point p : rivers[j]){
                    if(rivers[i][rivers[i].length-1].equals(p)){
                        col[i]=j;
                        break lab;
                    }
                }
            }
        }
        boolean fin=false;
        while(!fin){
            fin=true;
            for (int i=0; i<rivers.length; ++i){
                 if(col[col[i]]!=col[i]){
                     fin=false;
                     col[i]=col[col[i]];
                 }
            }
        }

        for (int i=0; i<rivers.length; ++i){
            if(col[i]==i){
                int len=0;
                for (int j=0; j<rivers.length; ++j){
                    if(col[j]==i){
                        len+=rivers[j].length;
                    }
                }
                Point[] pol = new Point[len];
                int uk=0;
                for (int j=0; j<rivers.length; ++j){
                    if(col[j]==i){
                        for (int k=0; k<rivers[j].length; ++k){
                            pol[uk++]=rivers[j][k];
                        }
                    }
                }
                ans = Math.max(ans, square(pol));
            }
        }
        out.format("%.2f\n", ans);

        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
