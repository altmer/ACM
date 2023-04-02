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
int S, T;
int num, ntest;
int chef, equip;
int m;
vector <vector <int> > flow, cost, init;
vector <int> phi, col, dist, par, r;
vector <bool> vis;

int increase ()
{
	int ret=0;
	int i=T;
	while (i!=S){
		flow[par[i]][i]-=r[T];
		flow[i][par[i]]+=r[T];
//		ret+=cost[par[i]][i]*r[T];
		i=par[i];
	}
	return ret;
}

int getw (int i, int j)
{
	return (phi[i] + cost[i][j] - phi[j]);
}

void reduce(int u)
{
	vis[u]=true;
	for (int v=0; v<num; ++v){
		if (flow[u][v] && !vis[v]){
			cost[u][v]+=phi[u]-phi[v];
			cost[v][u]=0;
			reduce(v);
		}
	}
}

bool dijkstra()
{
	col.assign(num, 0);
	dist.assign(num, INF);
	par.assign(num, -1);
	r.assign(num, 0);
	col[S]=1;
	dist[S]=0;
	r[S]=INF;
	while (true){
		int i=-1;
		for (int j=0; j<num; ++j){
			if (col[j]==1){
				if (i==-1 || dist[j]<dist[i]){
					i=j;
				}
			}
		}
		if (i==-1)
			break;
		col[i]=2;
		for (int j=0; j<num; ++j){
			if (flow[i][j]>0 && dist[i]+cost[i][j] < dist[j]){
				dist[j] = dist[i] + cost[i][j];
				par[j] = i;
				r[j] = min(r[i], flow[i][j]);
				col[j]=1;
			}
		}
	}
	return col[T]==2;
}

int path(int u){
	int ret =0;
	vis[u]=true;
	for (int v=0; v<num; ++v){
		if (flow[u][v] && !vis[v]){
			ret+=init[v][u]*flow[u][v];
			ret+=path(v);
		}
	}
	return ret;
}

int max_flow_min_cost()
{
	int ans = 0;
	while (dijkstra()){
		vis.assign(num, false);
		reduce(S);
		//ans+=
		increase();
		for (int i=0; i<num; ++i)
			phi[i]=dist[i];
	}
	vis.assign(num, false);
	ans = path(T);
	return ans;
}

int main ()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	scanf ("%d", &ntest);

	for (int test=0; test<ntest; ++test){
		scanf ("%d%d%d", &chef, &equip, &m);

		num = chef + equip + 2;
		S = num - 2;
		T = num - 1;

		flow.assign(num, vector <int> (num, 0));
		cost.assign(num, vector <int> (num, 0));
		init.assign(num, vector <int> (num, 0));

		par.assign(num, 0);
		r.assign(num, 0);
		dist.assign(num, 0);
		col.assign(num, 0);
		phi.assign(num, 0);
	
		for (int i=0; i<m; ++i){
			int a, b, c;
			scanf ("%d%d%d", &a, &b, &c);
			b+=chef;
			flow[a][b]=1;
			cost[a][b]=c;
		}

		for (int i=0; i<chef; ++i){
			flow[S][i]=1;
		}

		for (int i=chef; i<chef+equip; ++i){
			flow[i][T]=1;
		}

		init=cost;
		printf ("%d\n", max_flow_min_cost());
		if (test!=ntest-1)
			printf ("\n");

	}


	return 0;
}