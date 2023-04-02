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
	int dest, appl;
};

int n, q;
vector <vector <edge> > A;
vector <bool> color;

vector <int> dfs (int u){
	color[u]=true;
	vector <int> v1, v2, ret;
	for (int i=0; i<A[u].size(); ++i){
		int v=A[u][i].dest;
		int dist=A[u][i].appl;
		if (!color[v]){
			v1=dfs(v);
			v1.push_back(0);
			for (int j=v1.size()-1; j>=1; --j){
				v1[j]=v1[j-1];
			}
			for (int j=1; j<v1.size(); ++j){
				v1[j]+=dist;
			}
			v2.swap(v1);
		}
	}
	if (v1.empty())
		v1.push_back(0);
	if (v2.empty())
		v2.push_back(0);
	ret.resize(v1.size()+ v2.size()-1);
	for (int i=0; i<ret.size(); ++i){
		for (int j=0; j<=i; ++j){
			int k=i-j;
			if (j<v1.size() && k<v2.size() && v1[j]+v2[k]>ret[i]){
					ret[i]=v1[j]+v2[k];
			}
		}
	}
	return ret;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1018.in", "r", stdin);
	freopen ("T1018.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &q);
	A.resize(n);
	color.resize(n);

	for (int i=0; i<n-1; ++i){
		int u, v;
		edge t;
		scanf ("%d%d%d", &u, &v, &t.appl);
		t.dest=--v;
		A[--u].push_back(t);
		t.dest=u;
		A[v].push_back(t);
	}

	vector <int> ans=dfs(0);

	printf ("%d", ans[q]);

	return 0;
}