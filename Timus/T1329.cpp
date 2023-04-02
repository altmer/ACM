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

int n, m;
int cn=0;
map <int, int> match;
vector <vector <int> > A;
vector <int> par, time_ent, time_ext;
int ctime=1;

void dfs(int u)
{
	for (int i=0; i<A[u].size(); ++i){
		time_ent[A[u][i]]=ctime++;
		dfs(A[u][i]);
	}
	time_ext[u]=ctime++;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1329.in", "r", stdin);
	freopen ("T1329.out", "w", stdout);
#endif

	int root;
	scanf ("%d", &n);
	A.resize(n);
	par.assign(n,-1);
	time_ent.assign(n,0);
	time_ext.assign(n,0);
	for (int i=0; i<n; ++i){
		int ID, p;
		int fr, to;
		scanf ("%d%d", &ID, &p);
		if (match.count(ID)==0){
			to=cn;
			match[ID]=cn++;
		}
		else
			to=match[ID];
		if (p!=-1){
			if (match.count(p)==0){
				fr=cn;
				match[p]=cn++;
			}
			else
				fr=match[p];
			A[fr].push_back(to);
			par[to]=fr;
		}
		else
			root=to;
	}

	dfs(root);

	scanf ("%d", &m);

	for (int i=0; i<m; ++i){
		int u, v;
		scanf ("%d%d", &u, &v);
		u=match[u];/
		v=match[v];
		if (time_ent[u]>time_ent[v] && time_ent[u]<time_ext[v]){
			printf ("2\n");
		}
		else if (time_ent[v]>time_ent[u] && time_ent[v]<time_ext[u]){
			printf("1\n");
		}
		else
			printf ("0\n");
	}

	return 0;
}