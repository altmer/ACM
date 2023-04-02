#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2000;
int n, m;
vector <vector <int> > A;
vector <bool> color;
vector <int> dist;
vector <int> ans;
queue <int> q;

void BFS (int u, int cash, bool tick)
{
	for (int i=0; i<n; ++i)
	{
		color[i]=false;
		dist[i]=0;
	}

	color[u]=true;
	dist[u]=0;

	int edge;

	if (tick)
		edge=0;
	else
		edge=4;

	q.push(u);
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i)
		{
			if (!color[A[u][i]])
			{
				color[A[u][i]]=true;
				dist[A[u][i]]=dist[u]+edge;
				if (dist[A[u][i]]>cash)
					dist[A[u][i]]=INF;
				q.push(A[u][i]);
			}
		}
	}

	for (int i=0; i<n; ++i)
	{
		if (!color[i])
			dist[i]=INF;
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1085.in", "r", stdin);
	freopen ("T1085.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	A.resize(n);
	color.resize(n);
	dist.resize(n);
	ans.resize(n);

	for (int i=0; i<m; ++i)
	{
		int l;
		vector <int> buf;
		scanf ("%d", &l);
		for (int j=0; j<l; ++j)
		{
			int u;
			scanf ("%d", &u);
			buf.push_back(u);
			for (int k=0; k<j; ++k)
			{
				A[u-1].push_back(buf[k]-1);
				A[buf[k]-1].push_back(u-1);
			}
		}
	}

	int k;

	scanf ("%d", &k);

	for (int l=0; l<k; ++l)
	{
		int cash, start, tick;
		scanf ("%d%d%d", &cash, &start, &tick);
		BFS (start-1, cash, tick);
		for (int j=0; j<n; ++j)
			ans[j]+=dist[j];
	}

	int m=INF;
	int pos=-1;
	for (int i=0; i<n; ++i)
	{
		if (ans[i]<m)
		{
			m=ans[i];
			pos=i+1;
		}
	}

	if (pos==-1)
		printf ("0");
	else
		printf ("%d %d", pos, m);

	return 0;
}