import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.Math.*;

class Sheet{
    StringBuffer[] sh;
    GregorianCalendar solve;
    int sel;
    public Sheet(int year, int month, int date)
    {
        sel = date;
        
        sh = new StringBuffer[7];
        for (int i=0; i<sh.length; ++i)
            sh[i]=new StringBuffer();
        
        sh[0].append("mon");
        sh[1].append("tue");
        sh[2].append("wed");
        sh[3].append("thu");
        sh[4].append("fri");
        sh[5].append("sat");
        sh[6].append("sun");
        
        solve = new GregorianCalendar(year, month-1, 1); 
    }
    public void run()
    {
        for (int i=1; i<=solve.getActualMaximum(GregorianCalendar.DATE); ++i)
        {
            solve.set(GregorianCalendar.DATE, i);
            
            int cur=solve.get(GregorianCalendar.DAY_OF_WEEK);
            
            cur=(cur+5)%7;
            
            if (i==1){
                for (int j=0; j<cur; ++j){
                    sh[j].append("     ");
                }
            }
                sh[cur].append(" ");
            if (i==sel){
                sh[cur].append("[");
                if (i<10)
                    sh[cur].append(" ");
                sh[cur].append(i);
                sh[cur].append("]");
            }
            else{
                sh[cur].append(" ");
                if (i<10)
                    sh[cur].append(" ");
                sh[cur].append(i);
                sh[cur].append(" ");
            }
        }
    }
    public void print () throws IOException
    {
        /*
        PrintWriter cout = new PrintWriter ("T1201.out");
        //*/

        //*
        PrintWriter cout = new PrintWriter (System.out);
         //*/
         for (int i=0; i<sh.length; ++i){
            cout.println(sh[i]);
         }
        cout.close();
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        Scanner cin = new Scanner(new File("T1201.in"));
        //*/
        //*
        Scanner cin = new Scanner(System.in);
        //*/
        int a, b, c;
        a=cin.nextInt();
        b=cin.nextInt();
        c=cin.nextInt();
        Sheet newSheet = new Sheet (c, b, a);
        newSheet.run();
        newSheet.print();
    }
}
