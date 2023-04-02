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
int k, n, m, s, f;
vector <vector <int> > flow;
vector <bool> vis;
vector <int> par;

bool find_path(){
	vis.assign(flow.size(), false);
	par.assign(flow.size(), -1);
	queue <int> q;
	q.push(s);
	vis[s]=true;
	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (int v=0; v<flow.size(); ++v){
			if (flow[u][v] && !vis[v]){
				vis[v]=true;
				par[v]=u;
				if (v==f)
					return true;
				q.push(v);
			}
		}
	}
	return false;
}

int max_flow ()
{
	int ans=0;
	while (find_path()){
		int cur = f;
		int max_fl = INF;
		while (par[cur]!=-1){
			max_fl = min(max_fl, flow[par[cur]][cur]);
			cur=par[cur];
		}
		ans+=max_fl;
		cur=f;
		while (par[cur]!=-1){
			flow[par[cur]][cur]-=max_fl;
			flow[cur][par[cur]]+=max_fl;
			cur=par[cur];
		}
	}
	return ans;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1277.in", "r", stdin);
	freopen ("T1277.out", "w", stdout);
#endif

	scanf ("%d%d%d%d%d", &k, &n, &m, &s, &f);
	if (s==f){
		printf ("NO");
		return 0;
	}

	s=(s-1)*2;
	f=(f-1)*2;

	flow.assign(2*n, vector <int> (2*n, 0));
	vis.assign(2*n, false);
	par.assign(2*n, -1);

	for (int i=0; i<n; ++i){
		int pol;
		scanf ("%d", &pol);
		int p=i<<1;
		if (p==s || p==f)
			flow[p][p+1]=INF;
		else
			flow[p][p+1]=pol;
	}

	for (int i=0; i<m; ++i){
		int a, b;
		scanf ("%d%d", &a, &b);
		int q = (a-1)*2+1;
		int w = (b-1)*2;
		flow[q][w]=INF;
		q--;
		w++;
		flow[w][q]=INF;
	}

	if (max_flow()<=k)
		printf ("YES\n");
	else
		printf("NO\n");

	return 0;
}