#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
vector <int> d, ans;
vector <vector <int> > A;
queue <int> q;

void read (void)
{
	scanf ("%d", &n);
	d.resize(n);
	A.resize(n);
	for (int i=0; i<n; ++i)
	{
		int t;
		scanf ("%d", &t);
		while (t)
		{
			A[i].push_back(t-1);
			scanf ("%d", &t);
		}
	}
}

void BFS (int u)
{
	d[u]=1;
	q.push(u);
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (int v=0; v<A[u].size(); ++v)
		{
			int k=A[u][v];
			if (!d[k])
			{
				d[k]=d[u]+1;
				q.push(k);
			}
		}
	}
}
void solve (void)
{
	for (int i=0; i<n; ++i)
	{
		if (!d[i])
			BFS(i);
	}
	for (int i=0; i<n; ++i)
	{
		if (d[i]%2==0)
		{
			ans.push_back(i+1);
		}
	}
	printf ("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
	{
		printf ("%d ", ans[i]);
	}
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1106.in", "r", stdin);
	freopen ("T1106.out", "w", stdout);
#endif

	read ();
	solve();

	return 0;
}