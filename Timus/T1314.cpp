#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, m = 0;
map <int, vector <int> > list;
map <int, bool> color;
map <int, bool> ::iterator IT;
map <int, int> dist, res;
map <int, int> :: iterator It;
map <int, vector <int> > :: iterator it;
vector <int> pel;
queue <int> q;

void BFS (int u)
{
	q.push(u);
	dist[u]=0;
	while (!q.empty())
	{
		int v=q.front();
		q.pop();
		color[v]=true;
		for (int i=0; i<list[v].size(); ++i)
		{
			if (!color[list[v][i]])
			{
				dist[list[v][i]]=dist[v]+1;
				q.push(list[v][i]);
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1314.in", "r", stdin);
	freopen ("T1314.out", "w", stdout);
#endif

	scanf ("%d", &n);

	for (int i=0; i<n; ++i)
	{
		int k, prev, cur;
		scanf ("%d%d", &k, &prev);		
		color[prev]=false;
		dist[prev]=0;
		res[prev]=0;
		for (int j=2; j<=k; ++j)
		{
			scanf ("%d", &cur);
			list[prev].push_back(cur);
			list[cur].push_back(prev);
			color[cur]=false;
			dist[cur]=0;
			res[cur]=0;
			prev=cur;
		}
	}

	scanf ("%d", &m);
	for (int i=0; i<m; ++i)
	{
		int temp;
		scanf ("%d", &temp);
		pel.push_back(temp);
	}
	
	BFS (pel.front());
	dist.swap(res);
	for (IT=color.begin(); IT!=color.end(); ++IT)
		IT->second=0;
	BFS (pel.back());
	for (It=res.begin(); It!=res.end(); ++It)
	{
		It->second-=dist[It->first];
		if (It->second>=m-1)
			printf ("%d\n", It->first);
	}
		
	return 0;
}