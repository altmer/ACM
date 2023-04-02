#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

string num, word;
int n;
map <char, char> al;
vector <int> par;
vector <int> d;
vector <string> dict;
vector <vector <int> > A;
queue <int> q;
stack <int> r;

void init_alph (void)
{
	al['a']='2';
	al['b']='2';
	al['c']='2';
	al['d']='3';
	al['e']='3';
	al['f']='3';
	al['g']='4';
	al['h']='4';
	al['k']='5';
	al['l']='5';
	al['m']='6';
	al['n']='6';
	al['p']='7';
	al['r']='7';
	al['s']='7';
	al['t']='8';
	al['u']='8';
	al['v']='8';
	al['w']='9';
	al['x']='9';
	al['y']='9';
	al['o']='0';
	al['q']='0';
	al['z']='0';
	al['i']='1';
	al['j']='1';
}

void init (void)
{
	dict.clear();
	dict.resize(n);
	par.clear();
	par.resize(num.size()+1);
	d.clear();
	d.resize(num.size()+1);
	A.clear();
	A.resize (num.size()+1);
	for (int i=0; i<A.size(); ++i)
	{
		A[i].resize(num.size()+1);
	}
}
void test (int k, int n)
{
	for (int i=k; i<k+dict[n].size(); ++i)
	{
		if (num[i]!=al[dict[n][i-k]])
			return;
	}
	A[k][k+dict[n].size()]=n+1;
}
void BFS (int u)
{
	d[u]=1;
	q.push(u);
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (int v=0;v<=num.size(); ++v)
		{
			if (!d[v] && A[u][v])
			{
				q.push(v);
				d[v]=d[u]+1;
				par[v]=u;
			}
		}
	}
}
void print (void)
{
	int u=num.size();
	if (d[u]!=0)
	{
		while (u!=0)
		{
			r.push(u);
			u=par[u];
		}
		while (u!=num.size())
		{
			int v=r.top();
			r.pop();
			cout << dict[A[u][v]-1] << ' ';
			u=v;
		}
		printf ("\n");
	}
	else 
		printf ("No solution.\n");
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1002.in", "r", stdin);
	freopen ("T1002.out", "w", stdout);
#endif

	init_alph();
	while (getline (cin, num) && num!="-1")
	{
		scanf ("%d\n", &n);
		init();
		for (int i=1; i<=n; ++i)
		{
			getline (cin, word);
			dict[i-1]=word;
			for (int j=0; j<num.size(); ++j)
			{
				if (num[j]==al[word[0]] && j+word.size()-1<num.size())
					test (j, i-1);
			}
		}
		BFS (0);
		print();
	}

	return 0;
}