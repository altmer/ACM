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
	int dest, w, len;
};

vector <vector <edge> > A;
vector <int> dist;
queue <int> q;
const int lim=1441;
const int car=3e+6;
int n, m, ans;
bool res;
int R=1e+9+1;
int L=0;

void bfs (int u, int W){
	dist.assign(n, 0);
	dist[u]=1;
	q.push(u);
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i){
			int v=A[u][i].dest;
			if (A[u][i].w>=W && (dist[v]==0 || dist[v]>dist[u]+A[u][i].len)){
				dist[v]=dist[u]+A[u][i].len;
				q.push(v);
			}
		}
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1379.in", "r", stdin);
	freopen ("T1379.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	A.resize(n);
	dist.resize(n);

	for (int i=0; i<m; ++i){
		int u, v;
		edge t;
		scanf ("%d%d%d%d", &u, &v, &t.len, &t.w);
		t.dest=u-1;
		A[v-1].push_back(t);
		t.dest=v-1;
		A[u-1].push_back(t);
	}

	while (L<=R){
		res=false;
		int mid=(L+R)/2;
		bfs (0, car+mid);
		if (dist[n-1]!=0 && dist[n-1]<=lim)
			res=true;
		if (res){
			ans=mid;
			L=mid+1;
		}
		else{
			R=mid-1;
		}
	}

	printf ("%d", ans/100);
	
	return 0;
}