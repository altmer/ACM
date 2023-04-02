import java.io.*;
import java.util.*;

public class Main {
    BufferedReader in;
    PrintWriter out;

    class Node{
        int item;
        Node next;
        Node() { item=-1; next=null;}
        Node(int a) {item=a; next=null; }
    }

    Node A[], E[];
    boolean col[];
    int ans[];
    int cnt = 0;

    void init1()throws Exception{
        in = new BufferedReader(new FileReader(new File("input.txt")));
        out = new PrintWriter("output.txt");
    }

    void init2()throws Exception{
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    int dfs(int u){
        col[u]=true;
        int ret=0;
        int c=0;
        for (Node i = A[u].next; i!=null; i=i.next){
            int v = i.item;
            if(!col[v]) c++;
        }
        int arr[] = new int[c];

        int cur=0;
        for (Node i = A[u].next; i!=null; i=i.next){
            int v = i.item;
            if(!col[v]) arr[cur++]=dfs(v);
        }
        Arrays.sort(arr);
        for (int i=c-1; i>=0; --i){
            ret = Math.max(ret,arr[i]+c-i);
        }
        return ans[u]=ret;
    }

    void run() throws Exception{
        init2();

        int n = Integer.parseInt(in.readLine());
        A = new Node[n];
        for (int i=0; i<n; ++i){
            A[i] = new Node(-1);
        }
        E = new Node[2*n+3];
        col = new boolean[n];
        ans = new int[n];

        for (int i=0; i<n; ++i){
            String[] res = in.readLine().split(("\\s"));
            for (int j=0; j<res.length-1; ++j){
                int u = Integer.parseInt(res[j])-1;
                E[cnt]= new Node(u);
                E[cnt].next = A[i].next;
                A[i].next=E[cnt++];

                E[cnt]= new Node(i);
                E[cnt].next = A[u].next;
                A[u].next=E[cnt++];
            }
        }

        int r = Integer.parseInt(in.readLine())-1;
        dfs(r);

        out.println(ans[r]);

        in.close();
        out.close();
    }

    public static void main(String[] args)throws Exception{
        new Main().run();
    }
}
