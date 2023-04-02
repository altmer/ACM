import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    int[] f = new int[104];

    public void init(){
        f[1]=5392;
        f[2]=1890;
        f[3]=84;
        f[4]=6520;
        f[5]=3149;
        f[6]=2416;
        f[7]=2835;
        f[8]=80;
        f[9]=8614;
        f[10]=742;
        f[11]=7696;
        f[12]=6823;
        f[13]=9492;
        f[14]=7710;
        f[15]=9444;
        f[16]=510;
        f[17]=118;
        f[18]=6522;
        f[19]=3213;
        f[20]=4499;
        f[21]=6178;
        f[22]=4565;
        f[23]=763;
        f[24]=1071;
        f[25]=8875;
        f[26]=2688;
        f[27]=9145;
        f[28]=1211;
        f[29]=9480;
        f[30]=4056;
        f[31]=1817;
        f[32]=8661;
        f[33]=5467;
        f[34]=3358;
        f[35]=2892;
        f[36]=2205;
        f[37]=8691;
        f[38]=1963;
        f[39]=2386;
        f[40]=8401;
        f[41]=1047;
        f[42]=3691;
        f[43]=6824;
        f[44]=825;
        f[45]=7728;
        f[46]=6797;
        f[47]=1720;
        f[48]=8194;
        f[49]=9901;
        f[50]=2823;
        f[51]=1952;
        f[52]=9344;
        f[53]=5022;
        f[54]=1421;
        f[55]=6116;
        f[56]=4511;
        f[57]=1289;
        f[58]=2133;
        f[59]=7494;
        f[60]=7298;
        f[61]=5012;
        f[62]=9638;
        f[63]=8753;
        f[64]=5968;
        f[65]=4029;
        f[66]=4804;
        f[67]=9556;
        f[68]=924;
        f[69]=1497;
        f[70]=5886;
        f[71]=6078;
        f[72]=2085;
        f[73]=3876;
        f[74]=268;
        f[75]=2910;
        f[76]=8962;
        f[77]=2970;
        f[78]=1015;
        f[79]=3931;
        f[80]=1103;
        f[81]=4872;
        f[82]=4054;
        f[83]=346;
        f[84]=1119;
        f[85]=931;
        f[86]=4454;
        f[87]=6530;
        f[88]=1722;
        f[89]=4266;
        f[90]=9888;
        f[91]=7961;
        f[92]=2891;
        f[93]=885;
        f[94]=4461;
        f[95]=7731;
        f[96]=3316;
        f[97]=2155;
        f[98]=93;
        f[99]=2871;
        f[100]=9710;
    }

    public long pow (long x, int step){
        long ret=x;
        for (int i=1; i<step; ++i){
            ret*=x;
            ret%=9973;
        }
        return ret;
    }

    public int g(long x, long y){
        x%=9973;
        return (int)(((((y-1)%9973)*pow(x,5))%9973 + (pow(x,3))%9973 - (x*y)%9973 + (3*x)%9973 +(7*y)%9973+9973)%9973L);
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
        if(System.getProperty("ONLINE_JUDGE") != null)
            init2();
        else
            init1();

        int cur=0;
/*
        for (int i=1; i<=100000000; ++i){
            cur=g(i,cur);
            if(i%1000000==0){
                out.println("f["+i/1000000+"]="+cur+";");
            }
        }
*/
        init();
        
        int n = Integer.parseInt(in.readLine().trim());

        cur = f[n/1000000];
        for (int i=1; i<=n%1000000; ++i){
            cur = g(n/1000000*1000000+i, cur);
        }

        out.println(cur);

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
