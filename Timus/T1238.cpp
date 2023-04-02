#include <iostream>
#include <string>
#include <vector>
using namespace std;

string proc (string s)
{
	int len=s.size();
	int E [105], B [105], L [105];
	memset(E, 0, sizeof(E));
	memset(B, -1, sizeof(B));
	memset(L, 0, sizeof(L));
	for (int i=0; i<len; ++i)
	{
		for (int j=1; j<=(i+1)/2; ++j)
		{
			int cnt=1;
			while (i-j*cnt+1>=0 && s.substr(i-j*cnt+1,j)==s.substr(i-j+1,j))
			{
				int econ=j*cnt-(j+3+bool(cnt/10)+bool(cnt/100));
				int tmp=0;
				if (i-j*cnt>=0)
					tmp=E[i-j*cnt];
				if (econ>=0 && tmp+econ>=E[i])
				{
					E[i]=tmp+econ;
					B[i]=i-j*cnt+1;
					L[i]=j;
				}
				else if (econ<0 && tmp>=E[i])
					E[i]=tmp;
				++cnt;
			}
		}
	}

	int maxx=0;
	int ind=0;
	for (int i=0; i<len; ++i)
	{
		if (E[i]>maxx && B[i]!=-1)
		{
			maxx=E[i];
			ind=i;
		}
	}

	while (E[ind]>0 && ind>=0)
	{
		char str[3];
		string line;
		sprintf (str, "%d", (ind-B[ind]+1)/L[ind]);
		
		for (int i=0; i<strlen(str); ++i)
			line+=str[i];
		string res=s.substr(B[ind], L[ind]);
		line+='('+res+')';

		s.replace(B[ind], ind-B[ind]+1, line);
		if(ind==B[ind]){
			int sr=0;
			ind=ind/sr;
		}
		ind=B[ind];
		while (ind-1>=0 && E[ind-1]==E[ind])
			--ind;
		
	}

	return s;
}

int main (void)
{
	freopen ("T1238.in", "r", stdin);
	freopen ("T1238.out", "w", stdout);
	string s,line;
	getline (cin, s);
	line=proc(s);
	while (line!=s)
	{
		s=line;
		line=proc(line);
	}

	cout << line;

	return 0;
}