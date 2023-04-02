import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    private class Fraction{
        private long num, denum;

        public Fraction(){
            num = 0;
            denum = 0;
        }

        public Fraction (String s){
            String[] ss = s.split("\\s");
            long integ = 0;
            long n = 0;
            long den=0;
            long ind=0;
            if (ss.length==1){
                if(ss[0].indexOf('/')!=-1){
                    String[] sss = ss[0].split("/");
                    n = Long.parseLong(sss[0]);
                    den = Long.parseLong(sss[1]);
                }else{
                    integ = Long.parseLong(ss[0]);
                }
            }else{
                integ = Long.parseLong(ss[0]);
                String[] sss = ss[1].split("/");
                n = Long.parseLong(sss[0]);
                den = Long.parseLong(sss[1]);
            }

            if(den==0) den=1;
            if(integ<0) n=-n;
            n = n + integ*den;
            num=n;
            denum=den;            
        }

        public long gcd (long a, long b){
            while(b>0){
                long tmp = a%b;
                a = b;
                b = tmp;
            }
            return a;
        }

        public void reduce(){
            long k = gcd(Math.abs(num), Math.abs(denum));
            num/=k;
            denum/=k;
            if(denum<0){
                num*=-1;
                denum*=-1;
            }
        }

        public Fraction add (Fraction f){
            Fraction ret = new Fraction();
            long nden = this.denum * f.denum / gcd(this.denum, f.denum);
            long nnum = (nden/this.denum)*this.num + (nden/f.denum)*f.num;
            ret.num = nnum;
            ret.denum = nden;
            ret.reduce();
            return ret;
        }

        public Fraction substract(Fraction f){
            Fraction ret = new Fraction();
            long nden = this.denum * f.denum / gcd(this.denum, f.denum);
            long nnum = (nden/this.denum)*this.num - (nden/f.denum)*f.num;
            ret.num = nnum;
            ret.denum = nden;
            ret.reduce();
            return ret;
        }

        public Fraction multiply(Fraction f){
            Fraction ret = new Fraction();
            ret.num = this.num*f.num;
            ret.denum = this.denum*f.denum;
            ret.reduce();
            return ret;
        }

        public Fraction divide(Fraction f){
            Fraction ret = new Fraction();
            ret.num = this.num*f.denum;
            ret.denum = this.denum*f.num;
            ret.reduce();
            return ret;
        }

        public void println(){
            boolean wasint = false;
            if(num==0){ out.println(0); return;}
            if(num/denum!=0){
                out.print(num/denum);
                if(num<0) num=-num;
                wasint = true;
            }
            if(num%denum!=0){
                if(wasint) out.print(" ");
                if(num<0) out.print("-");
                out.print(Math.abs(num)%denum);
                out.print("/");
                out.print(denum);
            }
            out.println();
        }
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

        Fraction first = new Fraction(in.readLine().trim());
        char oper = in.readLine().trim().charAt(0);
        Fraction second = new Fraction(in.readLine().trim());

        switch(oper){
            case '+': first = first.add(second);
            break;
            case '-': first = first.substract(second);
            break;
            case '*': first = first.multiply(second);
            break;
            case '/': first = first.divide(second);
            break;
        }

        first.println();

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
