#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct edge{
	int d, l;
};

struct vert{
	int num, time;
	bool operator < (vert t){
		return time>t.time;
	}
};

vector <vector <edge> > A;
vector <int> dist;
vector <vert> w;
vector <bool> col;
int n, m;
int cnt;
int beg, end;

void dfs (int u){
	cnt++;
	col[u]=true;
	for (int i=0; i<A[u].size(); ++i){
		int v=A[u][i].d;
		if (!col[v])
			dfs(v);
	}
	cnt++;
	w[u].time=cnt;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1450.in", "r", stdin);
	freopen ("T1450.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	A.resize(n);
	dist.resize(n);
	w.resize(n);
	for (int i=1; i<n; ++i){
		w[i].num=i;
	}

	col.resize(n);

	for (int i=0; i<m; ++i){
		int u;
		edge t;
		scanf ("%d%d%d", &u, &t.d, &t.l);
		t.d--;
		A[u-1].push_back(t);
	}

	scanf ("%d%d", &beg, &end);

	beg--;
	end--;

	dfs (beg);

	sort (w.begin(), w.end());

	for (int i=0; i<w.size(); ++i){
		int u=w[i].num;
		if (w[i].time==0)
			break;
		for (int j=0; j<A[u].size(); ++j){
			int v=A[u][j].d;
			int k=dist[u]+A[u][j].l;
			if (dist[v]<k)
				dist[v]=k;
		}
		if (u==end)
			break;
	}

	if (!dist[end]){
		printf ("No solution");
		return 0;
	}

	printf ("%d", dist[end]);

	return 0;
}