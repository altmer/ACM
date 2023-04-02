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
	int dest, len;
};

int n, k;
vector <vector <edge> > v;
vector <__int64> A, p, D;
vector <bool> col;
__int64 max_hap, best_num, cur_ans;
vector <int> ans;

void dfs (int u){
	col[u]=true;
	if (D[u]>max_hap){
		max_hap=D[u];
		best_num=u;
	}

	for (int i=0; i<v[u].size(); ++i){
		__int64 cost=v[u][i].len+D[u];
		int vert=v[u][i].dest;
		cost+=A[vert];
		if (vert!=p[u]){
			p[vert]=u;
			D[vert]=cost;
			dfs(vert);
		}
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1463.in", "r", stdin);
	freopen ("T1463.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &k);
	v.resize(n);
	A.resize(n);
	p.resize(n);
	col.resize(n);
	D.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%d", &A[i]);
	}

	for (int i=0; i<k; ++i){
		int u, w, q;
		edge t;
		scanf ("%d%d%d", &u, &w, &q);
		t.dest=w-1;
		t.len=q;
		v[u-1].push_back(t);
		t.dest=u-1;
		v[w-1].push_back(t);
	}

	for (int i=0; i<n; ++i){
		if (!col[i]){
			p[i]=-1;
			D[i]=A[i];
			max_hap=0;
			dfs(i);
			max_hap=0;
			p[best_num]=-1;
			D[best_num]=A[best_num];
			dfs(best_num);
			if (max_hap>cur_ans){
				cur_ans=max_hap;
				ans.clear();
				while (best_num!=-1){
					ans.push_back(best_num);
					best_num=p[best_num];
				}
			}
		}
	}

	int L=ans.size();
	printf ("%d\n", cur_ans);
	printf ("%d\n", L);
	for (int i=0; i<ans.size(); ++i){
		printf ("%d ", ans[i]+1);
	}

	return 0;
}