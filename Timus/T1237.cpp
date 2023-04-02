#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

const int INF = 1000000000;

class dot{
public:
	int x, y, lim;
	int dist (const dot& t){
		return abs(x-t.x)+abs(y-t.y)+1;
	}
};

int num, n, m;
int res=0;;
int S, T;
vector <vector <int> > flow, cost;
vector <dot> B, C;
vector <int> infl;
vector <int> vis, dist, par;
vector <bool> aug;

int bfs(){
	dist.assign(num, 0);
	aug.assign(num, false);
	vis.assign(num, 0);
	par.assign(num, -1);
	queue <int> q;
	q.push(S);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v = 0; v<num; ++v){
			if (flow[u][v] && (vis[v]==0 || dist[u]+cost[u][v]<dist[v])){
				++vis[v];
				dist[v]=dist[u]+cost[u][v];
				par[v]=u;
				if (vis[v]>num)
					return v;
				q.push(v);
			}
		}
	}
	return -1;
}


int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1237.in", "r", stdin);
	freopen ("T1237.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);

	num = n + m + 2;
	S = num - 2;
	T = num - 1;

	B.resize(n);
	C.resize(m);

	flow.assign(num, vector <int> (num, 0));
	cost.assign(num, vector <int> (num, 0));
	infl.assign(num, 0);

	for (int i=0; i<n; ++i){
		scanf ("%d%d%d", &B[i].x, &B[i].y, &B[i].lim);
	}
	for (int i=0; i<m; ++i){
		scanf ("%d%d%d", &C[i].x, &C[i].y, &C[i].lim);
	}

	// costs!
	for (int i=0; i<n; ++i){
		flow[S][i]=B[i].lim;
		for (int j=0; j<m; ++j){
			flow[i][n+j]=B[i].lim; // ????????????????????????????????????????????????????????????????????????
			int tmp = B[i].dist(C[j]);
			cost[i][n+j]=tmp;
			cost[n+j][i]=-tmp;
		}
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			scanf ("%d", &flow[n+j][i]);
			flow[i][n+j] = B[i].lim - flow[n+j][i];
			infl[j]+=flow[n+j][i];
		}
	}

	for (int j=0; j<m; ++j){
		flow[n+j][T] = C[j].lim - infl[j];
		flow[T][n+j] = INF;
	}

	if((res=bfs())!=-1){
		printf ("SUBOPTIMAL\n");
		int cur=res; 
		do{
			aug[cur]=true;
			cur=par[cur];
		}while (!aug[cur]);

		res = cur;
		do{
			flow[par[res]][res]-=1;
			flow[res][par[res]]+=1;
			res=par[res];
		}while (res!=cur);

		for (int i=0; i<n; ++i){
			for (int j=n; j<n+m; ++j){
				printf ("%d ", flow[j][i]);
			}
			printf ("\n");
		}
	}
	else{
		printf ("OPTIMAL\n");
	}

	return 0;
}