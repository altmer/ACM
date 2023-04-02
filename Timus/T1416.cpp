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

int maxint = numeric_limits<int>::max();

struct edge{
	int len, fr, to;
	bool used;
	edge() : len(-1), used(false), fr(0), to(0) {}
	bool operator < (const edge& T) const{
		return len<T.len;
	}
};

int n,m;
vector <vector <edge*> > G;
vector <vector <edge*> > A;
vector <edge> E;
vector <int> col;
vector <int> inc;
vector <int> par;
vector <int> lev;
int ans1=0, ans2=maxint;
bool fin=false;

void dfs (int u){
	col[u]=1;
	for (int i=0; i<A[u].size(); ++i){
		if (A[u][i]->used){
			int v;
			if (A[u][i]->fr!=u){
				v=A[u][i]->fr;
			}
			else{
				v=A[u][i]->to;
			}
			if (!col[v]){
				lev[v]=lev[u]+1;
				par[v]=u;
				dfs(v);
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1416.in", "r", stdin);
	freopen ("T1416.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	A.resize(n);
	lev.assign(n, 0);
	inc.assign(n, 0);

	G.resize(n);
	for (int i=0; i<n; ++i){
		G[i].resize(n);
	}
	
	E.assign(m, edge());
	col.assign(n, 0);

	for (int i=0; i<m; ++i){
		scanf ("%d%d%d", &E[i].fr,&E[i].to,&E[i].len);
		E[i].fr--;
		E[i].to--;
	}

	sort (E.begin(), E.end());

	// MST
	int ccol=1;
	for (int i=0; i<m; ++i){
		if (E[i].fr==E[i].to)
			continue;
		if (col[E[i].fr]==0 && col[E[i].to]==0){
			col[E[i].fr]=col[E[i].to]=ccol++;
			E[i].used=true;
			inc[E[i].fr]++;
			inc[E[i].to]++;
			ans1+=E[i].len;
		}
		else if (col[E[i].fr]==0 && col[E[i].to]!=0){
			col[E[i].fr]=col[E[i].to];
			E[i].used=true;
			inc[E[i].fr]++;
			inc[E[i].to]++;
			ans1+=E[i].len;
		}
		else if (col[E[i].fr]!=0 && col[E[i].to]==0){
			col[E[i].to]=col[E[i].fr];
			E[i].used=true;
			inc[E[i].fr]++;
			inc[E[i].to]++;
			ans1+=E[i].len;
		}
		else if (col[E[i].fr]!=col[E[i].to]){
			E[i].used=true;
			ans1+=E[i].len;
			inc[E[i].fr]++;
			inc[E[i].to]++;
			int top=col[E[i].fr];
			for (int j=0; j<n; ++j){
				if (col[j]==top){
					col[j]=col[E[i].to];
				}
			}
		}
	}
	
	for (int i=0; i<m; ++i){
		G[E[i].fr][E[i].to]=G[E[i].to][E[i].fr]=&E[i];
		A[E[i].fr].push_back(&E[i]);
		A[E[i].to].push_back(&E[i]);
	}

	col.assign(n,0);
	par.assign(n,-1);

	for (int i=0; i<n; ++i){
		if (inc[i]==1){
			dfs(i);
			break;
		}
	}
	
	for (int i=0; i<m; ++i){
		if (!E[i].used){
			fin=false;
			//E[i].used=true;
			int cur=ans1+E[i].len;
			int maxx=0;
			int vert1, vert2;
			vert1=E[i].to;
			vert2=E[i].fr;

			while (lev[vert1]<lev[vert2]){
				if (!((E[i].fr==vert2 && E[i].to==par[vert2]) || (E[i].to==vert2 && E[i].fr==par[vert2])))
					maxx=max(maxx, G[vert2][par[vert2]]->len);
				vert2=par[vert2];
			}
			while(lev[vert2]<lev[vert1]){
				if (!((E[i].fr==vert1 && E[i].to==par[vert1]) || (E[i].to==vert1 && E[i].fr==par[vert1])))
					maxx=max(maxx, G[vert1][par[vert1]]->len);
				vert1=par[vert1];
			}
			while(vert1!=vert2){
				if (!((E[i].fr==vert2 && E[i].to==par[vert2]) || (E[i].to==vert2 && E[i].fr==par[vert2])))
					maxx=max(maxx, G[vert2][par[vert2]]->len);
				vert2=par[vert2];
				if (!((E[i].fr==vert1 && E[i].to==par[vert1]) || (E[i].to==vert1 && E[i].fr==par[vert1])))
					maxx=max(maxx, G[vert1][par[vert1]]->len);
				vert1=par[vert1];
			}
			ans2=min(ans2, cur-maxx);
			//E[i].used=false;
		}
	}

	cout << "Cost: " << ans1 << endl;
	cout << "Cost: " << ((ans2==maxint) ? -1 : ans2) << endl;

	return 0;
}