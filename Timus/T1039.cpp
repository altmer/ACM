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

struct vert{
	int num, l;
	bool operator <(vert t){
		return l>t.l;
	}
};

int n;
vector <vector <int> > A;
vector <int> par, con, incl, nincl;
vector <vert> lev;

void bfs (int u){
	queue <int> q;
	lev[u].num=u;
	lev[u].l=1;
	q.push(u);
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i){
			int v=A[u][i];
			q.push(v);
			lev[v].num=v;
			lev[v].l=lev[u].l+1;
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1039.in", "r", stdin);
	freopen ("T1039.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize(n);
	par.assign(n, -1);
	con.resize(n);
	incl.resize(n);
	nincl.resize(n);
	lev.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%d", &con[i]);
	}

	int u, v;
	scanf ("%d%d", &u, &v);
	while (u!=0 && v!=0){
		u--; v--;
		par[u]=v;
		A[v].push_back(u);
		scanf ("%d%d", &u, &v);
	}

	int root=-1;
	for (int i=0; i<n; ++i){
		if (par[i]==-1){
			root=i;
			break;
		}
	}

	bfs(root);

	sort(lev.begin(), lev.end());

	for (int i=0; i<lev.size(); ++i){
		int u=lev[i].num;
		incl[u]=con[u];
		for (int i=0; i<A[u].size(); ++i){
			int v=A[u][i];
			incl[u]+=nincl[v];
			nincl[u]+=max(incl[v],nincl[v]);
		}
	}

	printf ("%d", max(incl[root],nincl[root]));

	return 0;
}