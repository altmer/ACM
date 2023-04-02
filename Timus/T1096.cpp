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
	int dest, bus;
};

vector <vector <edge> > A (2000);
vector <int> dist (2000, 0);
vector <edge> par (2000);
queue <int> q;
stack <int> ans;
int k;

void bfs (int u, int v){
	dist[u]=1;
	par[u].dest=-1;
	par[u].bus=-1;
	dist[v]=1;
	par[v].dest=-1;
	par[v].bus=-1;
	q.push(u);
	q.push(v);
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i){
			v=A[u][i].dest;
			if (dist[v]==0 || dist[v]>dist[u]+1){
				q.push(v);
				dist[v]=dist[u]+1;
				par[v].bus=A[u][i].bus;
				par[v].dest=u;
			}
		}
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1096.in", "r", stdin);
	freopen ("T1096.out", "w", stdout);
#endif

	scanf ("%d", &k);
	
	int u, v, end;
	edge t;

	for (int i=0; i<k; ++i){
		t.bus=i+1;
		scanf ("%d%d", &u, &v);
		t.dest=v-1;
		A[u-1].push_back(t);
/*		t.dest=u-1;
		A[v-1].push_back(t);*/
	}

	scanf ("%d%d%d", &end, &u, &v);
	end--;	u--;	v--;

	bfs (u, v);

	if (dist[end]==0){
		printf ("IMPOSSIBLE");
		return 0;
	}

	dist[end]--;
	printf ("%d\n", dist[end]);
	int p=par[end].dest;
	ans.push(par[end].bus);
	while (par[p].bus!=-1){
		ans.push(par[p].bus);
		p=par[p].dest;
	}

	while (!ans.empty()){
		printf ("%d\n", ans.top());
		ans.pop();
	}

	return 0;
}