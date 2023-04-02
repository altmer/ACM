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
vector <vector <int> > flow, cost;
vector <int> par, dist;
vector <bool> vis;

struct edge{
	int vert, cost;
	edge(int a, int b) : vert(a), cost(b) {}
	bool operator < (const edge& t) const{
		return cost>t.cost;
	}
};

bool find_path()
{
	par.assign(num, -1);
	dist.assign(num, INF);
	priority_queue <edge> q;
	q.push(edge(S, 0));
	dist[S]=0;
	while (!q.empty()){
		int u = q.top().vert;
		q.pop();
		for (int v = 0; v<num; ++v){
			if (flow[u][v] && dist[u]+cost[u][v]<dist[v] ){
				dist[v]=dist[u]+cost[u][v];
				par[v]=u;
				q.push(edge(v, dist[v]));
			}
		}
	}
	return dist[T]!=INF;
}

int max_flow_min_cosr()
{
	int ans=0;
	while (find_path()){
		int fl = 1;
		// finding flow not necessary
		for (int cur=T; par[cur]!=-1; cur=par[cur]){
			ans+=cost[par[cur]][cur]*fl;
			flow[par[cur]][cur]-=fl;
			flow[cur][par[cur]]+=fl;
		}
	}
	return ans;
}

int main()
{
	//freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);

	scanf ("%d", &ntest);

	for (int test=0; test<ntest; ++test){
		scanf ("%d%d%d", &chef, &equip, &m);

		num = chef + equip + 2;
		S = num - 2;
		T = num - 1;

		flow.assign(num, vector <int> (num, 0));
		cost.assign(num, vector <int> (num, 0));
	
		for (int i=0; i<m; ++i){
			int a, b, c;
			scanf ("%d%d%d", &a, &b, &c);
			b+=chef;
			flow[a][b]=1;
			cost[a][b]=c;
			cost[b][a]=-c;
		}

		for (int i=0; i<chef; ++i){
			flow[S][i]=1;
		}

		for (int i=chef; i<chef+equip; ++i){
			flow[i][T]=1;
		}

		printf ("%d\n", max_flow_min_cosr());
		if (test!=ntest-1)
			printf ("\n");

	}


	return 0;
}