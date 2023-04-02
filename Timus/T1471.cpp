#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

struct NodeGraph{
	int next, vert, len;
};

struct NodeQuery{
	int next, num, to;
};

int fg[60000];
NodeGraph E[120000];
int cnt=0;
int fq[60000];
NodeQuery Q[200000];
int cq=0;
int dist[60000];
bool col[60000];
int ans[80000];
int n, qq;
int ances[100000], dsu[100000];
bool col2[100000];

void dfs_len(int u){
	col[u]=true;
	for (int ind=fg[u]; ind!=-1; ind=E[ind].next){
		int v = E[ind].vert;
		if(!col[v]){
			dist[v]=dist[u]+E[ind].len;
			dfs_len(v);
		}
	}
}

int dsu_get(int u){
	return dsu[u]==u ? u : dsu[u]=dsu_get(dsu[u]);
}

void dsu_unite(int a, int b, int new_anc){
	a = dsu_get(a);
	b = dsu_get(b);
	if(rand()&1) swap(a, b);
	dsu[a]=b;
	ances[b]=new_anc;
}

void dfs(int u){
	col2[u] = true;
	dsu[u]=u;
	ances[u]=u;
	for (int ind=fg[u]; ind!=-1; ind=E[ind].next){
		int v = E[ind].vert;
		if(!col2[v]){
			dfs(v);
			dsu_unite(u,v,u);
		}
	}

	for (int ind=fq[u]; ind!=-1; ind=Q[ind].next){
		int v = Q[ind].to;
		int wher = Q[ind].num;
		if(col2[v] && ans[wher]==-1){
			int lca = ances[ dsu_get(v) ];
			ans[wher] = dist[u]-dist[lca]+dist[v]-dist[lca];
		}
	}
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	for (int i=0; i<60000; ++i){
		fg[i]=fq[i]=-1;
	}
	for (int j=0; j<80000; ++j)
		ans[j]=-1;

	scanf("%d", &n);
	for (int i=0; i<n-1; ++i){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E[cnt].vert=b;
		E[cnt].len=c;
		E[cnt].next=fg[a];
		fg[a]=cnt++;
		E[cnt].vert=a;
		E[cnt].len=c;
		E[cnt].next=fg[b];
		fg[b]=cnt++;
	}

	scanf("%d", &qq);
	for (int i=0; i<qq; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		Q[cq].num=i;
		Q[cq].to=b;
		Q[cq].next=fq[a];
		fq[a]=cq++;
		Q[cq].num=i;
		Q[cq].to=a;
		Q[cq].next=fq[b];
		fq[b]=cq++;
	}

	dfs_len(0);
	dfs(0);

	for (int i=0; i<qq; ++i){
		printf("%d\n", ans[i]);
	}

    return 0;
}