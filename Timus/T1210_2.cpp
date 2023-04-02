#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int list[1000][1000];
int n, ans=2000000000;
queue <int> q;
int dist [1000];

void BFS (int u)
{
	q.push(u);
	dist[u]=0;
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (int v=0; v<n; ++v)
		{
			if (list[u][v] && (!dist[v] || dist[u]+list[u][v]<dist[v]))
			{
				dist[v]=dist[u]+list[u][v];
				q.push(v);
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1210.in", "r", stdin);
	freopen ("T1210.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	int prev=1, v=2;
	for (int i=0; i<n; ++i)
	{
		char ch;
		int k;
		scanf ("%d\n", &k);
		for (int j=1; j<=k; ++j)
		{
			int u=1, len;
			while (u)
			{
				scanf ("%d", &u);
				if (u)
				{
					u+=v-j-prev;
					scanf ("%d", &len);
					list[u-1][v-1]=len;
					u=1;
				}				
			}
			++v;
			scanf ("\n");
		}
		scanf ("%c\n", &ch);
		prev=k;
	}

	n=v-1;

	BFS (0);

	for (int i=1; i<=prev; ++i)
		if (dist[n-i]<ans)
			ans=dist[n-i];

	cout << ans;

	return 0;
}