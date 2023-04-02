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
	int num, lev;
	bool operator < (vert t){
		return lev>t.lev;
	}
};

int n, k, ans=1e+6;
vector <vector <int> > A;
vector <int> pl, win;
vector <vert> lev;

void dfs (int u){
	bool isleaf=true;
	for (int i=0; i<A[u].size(); ++i){
		int v=A[u][i];
		if (lev[v].lev==0){
			isleaf=false;
			lev[v].lev=lev[u].lev+1;
			pl[v]=3-pl[u];
			dfs(v);
		}
	}
	if (isleaf)
		win[u]=3-pl[u];		
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1045.in", "r", stdin);
	freopen ("T1045.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &k);
	k--;
	A.resize(n);
	lev.resize(n);
	win.resize(n);
	lev[k].lev=1;
	pl.resize(n);

	for (int i=0; i<n-1; ++i){
		int u, v;
		lev[i].num=i;
		scanf ("%d%d", &u, &v);
		A[u-1].push_back(v-1);
		A[v-1].push_back(u-1);
	}
	lev[n-1].num=n-1;

	pl[k]=1;
	dfs (k);

	sort (lev.begin(), lev.end());

	for (int i=0; i<lev.size(); ++i){
		int u=lev[i].num;
		if (!win[u]){
			win[u]=3-pl[u];
			for (int j=0; j<A[u].size(); ++j){
				int v=A[u][j];
				if (win[v]==pl[u]){
					win[u]=pl[u];
				}
			}
		}
	}

	if (win[k]==1){
		for (int i=0; i<A[k].size(); ++i){
			int v=A[k][i];
			if (win[v]==1 && v+1<ans)
				ans=v+1;
		}
		printf ("First player wins flying to airport %d", ans);
	}
	else{
		printf ("First player loses");
	}
		
	return 0;
}