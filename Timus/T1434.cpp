#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class rs{
public:
	int route, stop;
	rs(): route(0), stop(0){}
	rs(int x, int y):route(x), stop(y){}
};

int n, m, k;
int A, B;
vector <vector <int> > v, r;
vector <int> dist;
vector <rs> par;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1434.in", "r", stdin);
	freopen ("T1434.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	v.resize(m+1);
	r.resize(n);
	dist.assign(n, 1e+9);
	par.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%d", &k);
		for (int j=0; j<k; ++j){
			int t;
			scanf ("%d", &t);
			v[t].push_back(i);
			r[i].push_back(t);
		}
	}	
	scanf ("%d%d", &A, &B);

	queue <int> q;
	
	for (int i=0; i<v[A].size(); ++i){
		dist[v[A][i]]=1;
		q.push(v[A][i]);
		par[v[A][i]]=rs(-1, A);
	}	

	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (int i=0; i<r[u].size(); ++i){
			if (r[u][i]==B){
				stack <int> st;
				printf ("%d\n", dist[u]);
				st.push(B);
				while (par[u].stop!=A){
					st.push(par[u].stop);
					u=par[u].route;
				}
				st.push(A);
				while (!st.empty()){
					printf ("%d ", st.top());
					st.pop();
				}
				return 0;
			}
			else{
				for (int j=0; j<v[r[u][i]].size(); ++j){
					if (dist[v[r[u][i]][j]]>dist[u]+1){
						dist[v[r[u][i]][j]]=dist[u]+1;
						par[v[r[u][i]][j]]=rs(u, r[u][i]);
						q.push(v[r[u][i]][j]);
					}
				}
			}
		}
	}

	printf ("-1");

	return 0;
}