#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <list>
using namespace std;

struct vert
{
	int num, t;
	bool operator < (vert g)
	{
		return t>g.t;
	}
};

vector <vector <int> > v, vt;
vector <bool> col, colt;
vector <int> in, ans;
vector <vert> times;
int n, cnt, time;

void set0 (void)
{
	for (int i=0; i<col.size(); ++i)
	{
		col[i]=false;
	}
}

void dfs (int u)
{
	++time;
	col[u]=true;
	++cnt;
	for (int i=0; i<v[u].size(); ++i)
	{
		if (!col[v[u][i]])
		{
			dfs(v[u][i]);
		}
	}
	++time;
	times[u].t=time;
}

void dfst (int u)
{
	col[u]=true;
	for (int i=0; i<vt[u].size(); ++i)
	{
		if (!col[vt[u][i]])
		{
			dfst(vt[u][i]);
		}
	}
}

void dfst_ans (int u)
{
	colt[u]=true;
	ans.push_back(u+1);
	for (int i=0; i<vt[u].size(); ++i)
	{
		if (!colt[vt[u][i]])
		{
			dfst_ans(vt[u][i]);
		}
	}
}

void scc (void)
{
	for (int i=0; i<n; ++i)
	{
		if (!col[i])
			dfs(i);
	}
	sort (times.begin(), times.end());
	set0();
	for (int i=0; i<n; ++i)
	{
		int h=times[i].num;
		if (!colt[h])
		{
			dfst_ans (h);
			set0();
			cnt=0;
			dfs(h);
			if (cnt!=n)
				return;
			else
			{
				sort (ans.begin(), ans.end());
				for (int i=0; i<ans.size(); ++i)
				{
					printf ("%d ", ans[i]);
				}
				return;
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1198.in", "r", stdin);
	freopen ("T1198.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	vt.resize(n);
	in.resize(n);
	times.resize(n);
	col.resize(n);
	colt.resize(n);

	for (int i=0; i<n; ++i)
	{
		int t;
		times[i].num=i;
		scanf ("%d", &t);
		while (t!=0)
		{
			v[i].push_back(t-1);
			vt[t-1].push_back(i);
			in[t-1]++;
			scanf ("%d", &t);
		}
	}

	cnt=0;
	for (int i=0; i<n; ++i)
	{
		if (in[i]==0)
		{
			dfs(i);
			if (cnt==n)
			{
				printf ("%d 0", i+1);
				return 0;
			}
			else
			{
				printf ("0");
				return 0;
			}
		}
	}

	scc();

	printf ("0");
	return 0;
}