#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


vector <vector <int> > S;
vector <vector <int> > P;
vector <bool> c;
char C[20];
string line;
int n, a;

void dfs_s (int u)
{
	c[u]=true;
	for (int v=0; v<S[u].size(); ++v)
		dfs_s (S[u][v]);
}

void dfs_p (int u)
{
	c[u]=true;
	for (int v=0; v<P[u].size(); ++v)
		dfs_p (P[u][v]);
}

void set0 (void)
{
	for (int i=0; i<20; ++i)
		C[i]='a';
}


int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1242.in", "r", stdin);
	freopen ("T1242.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	S.resize (n);
	P.resize (n);
	c.resize (n);

	while (getline (cin, line))
	{
		set0();
		bool res=false;
		for (int i=0; i<line.size(); ++i)
		{
			if (isalpha(line[i]))
			{
				res=true;
				break;
			}
		}
		if (res)
			break;
		int v, u;
		int st=0, end=0;
		while (isdigit(line[end]))
			++end;
		line.copy(C,end-st, st);
		v=atoi(C);
		st=end+1;
		end=st;
		while (end<line.size()&&isdigit(line[end]))
			++end;
		set0();
		line.copy(C,end-st, st);
		u=atoi(C);
		S[u-1].push_back(v-1);
		P[v-1].push_back(u-1);
	}

	int cur;
	while (cin >> cur)
	{
		dfs_s(cur-1);
		dfs_p(cur-1);
	}
	bool res=false;
	for (int i=0; i<c.size(); ++i)
	{
		if (!c[i])
		{
			printf ("%d ", i+1);
			res=true;
		}
	}

	if (!res)
		cout << "0";

	return 0;
}