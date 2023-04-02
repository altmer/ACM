import java.io.*;
import java.util.*;

public class Main {
    
    static final double eps=1e-9;
    static final double INF = 1000*1000*1000;
    
    public Main() {
    }
    
    class Segm implements Comparable<Segm>{
        public double xb, xe, yb, ye, tan, shift;
        Segm(double x1, double y1, double x2, double y2){
            if(Math.abs(x1-x2)<eps){
                if(y1<y2){
                    xb=x1; yb=y1;
                    xe=x2; ye=y2;
                }else{
                    xb=x2; yb=y2;
                    xe=x1; ye=y1;
                }
            }else if(x1<x2){
                xb=x1; yb=y1;
                xe=x2; ye=y2;
            }else{
                xb=x2; yb=y2;
                xe=x1; ye=y1;
            }
            double A = ye - yb;
            double B = xb - xe;
            double C = -(xb*A + yb*B);
            if(Math.abs(B)<eps){
                tan = INF;
                shift = xb;
            }else{
                tan = -A/B;
                shift = -C/B;
            }
        }
        public int compareTo(Segm t){
            if(Math.abs(tan-t.tan)<eps){
                if(Math.abs(shift-t.shift)<eps){
                    if (Math.abs(xb-t.xb)<eps){
                        if (Math.abs(xe-t.xe)<eps){
                            if(Math.abs(yb-t.yb)<eps){
                                if(Math.abs(ye-t.ye)<eps){
                                    return 0;
                                }
                                return ye<t.ye ? -1 : 1;
                            }
                            return yb<t.yb ? -1 : 1;
                        }
                        return xe<t.xe ? -1 : 1; 
                    }
                    return xb<t.xb ? -1 : 1;
                }
                return shift<t.shift ? -1 : 1;
            }
            return tan < t.tan ? -1 : 1;
        }
        public boolean notOneLine(Segm t){
            return Math.abs(tan-t.tan)>eps || Math.abs(shift-t.shift)>eps;
        }
        public double length(){
            return Math.sqrt((xe-xb)*(xe-xb)+(ye-yb)*(ye-yb));
        }
    }
    
    void run() throws Exception{
        BufferedReader in = new BufferedReader (new FileReader("line.in"));
        PrintWriter out = new PrintWriter("line.out");
        int n = Integer.parseInt(in.readLine());
        Segm[] arr = new Segm[n];
        for (int i=0; i<n; ++i){
            String res[] = in.readLine().split("\\s");
            arr[i] = new Segm(Double.parseDouble(res[0]),Double.parseDouble(res[1]),Double.parseDouble(res[2]),Double.parseDouble(res[3]));
        }
        Arrays.sort(arr);
        double ans=0;
        Segm cur = new Segm(-100000,-100000,-100000,-100000);
        for (int i=0; i<n; ++i){
            if(i==0 || arr[i].notOneLine(cur)){
                ans = Math.max(ans,cur.length());
                cur = arr[i];
            }else{
                if(Math.abs(arr[i].tan-INF)>eps){
                    if(arr[i].xb<cur.xe || Math.abs(arr[i].xb-cur.xe)<eps){
                        if(arr[i].xe>cur.xe){
                            cur.xe=arr[i].xe;
                            cur.ye = arr[i].ye;                                    
                        }
                    }else{
                        ans = Math.max(ans,cur.length());
                        cur = arr[i];
                    }
                }else{
                    if(arr[i].yb<cur.ye || Math.abs(arr[i].yb-cur.ye)<eps){
                        if(arr[i].ye>cur.ye){
                            cur.ye=arr[i].ye;
                            cur.xe=arr[i].xe;
                        }
                    }else{
                        ans = Math.max(ans,cur.length());
                        cur = arr[i];
                    }
                }
            }
        }
        ans = Math.max(ans,cur.length());
        out.format(Locale.US,"%.2f\n", ans);
        in.close();
        out.close();
    }
    public static void main(String[] args)throws Exception {
        new Main().run();
    }
    
}
