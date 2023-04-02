import java.io.*;
import java.util.*;

public class Access{

	Map<Long,Boolean> T;
	Scanner in;
	BufferedReader inn;
	PrintWriter out;
	long parts[];

	long netw(long ip, long mask){
		return (mask<<33) + ((ip>>(32-mask))&((1L<<mask)-1));
	}

	Boolean get(long ip, long mask){
		for (long i=mask; i>=0; --i){
			if(T.get(netw(ip,i))!=null){
				return T.get(netw(ip,i));
			}
		}
		return null;
	}

	void run()throws IOException{
/*		in=new Scanner(new File("access.in"));*/
		inn = new BufferedReader (new FileReader (new File("access.in")));
		out = new PrintWriter ("access.out");
		T = new HashMap<Long, Boolean>();
		parts=new long[5];
		int end=0;
		long ip,mask;
		
		String tmp=inn.readLine();
		int n=0;
		for (int j=0;j<tmp.length(); ++j){
 			if(tmp.charAt(j)>='0' && tmp.charAt(j)<='9')
			n=n*10+tmp.charAt(j)-'0';
		}
		/*int n=in.nextInt(); in.nextLine();*/

		for (int i=0; i<n; ++i){
			parts[0]=parts[1]=parts[2]=parts[3]=parts[4]=end=0;

/*			String s=in.nextLine();*/
			String s=inn.readLine();

			Boolean allow=(s.charAt(0)=='a');

			s=s.substring(s.lastIndexOf(' ')+1);
			for (int j=0; j<s.length(); ++j){
				char ch=s.charAt(j);
				if(ch>='0' && ch<='9')
					parts[end]=parts[end]*10+(ch-'0');
				else
					end++;	
			}

			mask= ((end==4) ? parts[4] : 32);
			ip = ((parts[0]*256+parts[1])*256+parts[2])*256+parts[3];

			if(get(ip,mask)==null){
				T.put(netw(ip,mask),allow);
			}
		}
	/*	n=in.nextInt();
		in.nextLine();*/
		tmp=inn.readLine();
		n=0;
		for (int j=0;j<tmp.length(); ++j){
 			if(tmp.charAt(j)>='0' && tmp.charAt(j)<='9')
			n=n*10+tmp.charAt(j)-'0';
		}

		for (int i=0; i<n; ++i){
			/*String s=in.nextLine();*/
			String s=inn.readLine();

           		parts[0]=parts[1]=parts[2]=parts[3]=parts[4]=end=0;
		
			for (int j=0; j<s.length(); ++j){
				char ch=s.charAt(j);
				if(ch>='0' && ch<='9')
					parts[end]=parts[end]*10+(ch-'0');
				else
					end++;	
			}

	            ip = ((parts[0]*256+parts[1])*256+parts[2])*256+parts[3] ;
	            Boolean allow=get(ip,32);
		    out.print(allow==null || allow ? 'A' : 'D');
		}
		inn.close();
		out.close();
	}

	public static void main(String[] args)throws IOException{

		(new Access()).run();

	}
}