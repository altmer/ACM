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

int n, k, m;
int ans;
vector <vector <int> > v;
vector <bool> color;

void dfs (int u)
{
	color[u]=true;
	for (int i=0; i<v[u].size(); ++i)
	{
		int d=v[u][i];
		if (!color[d])
			dfs(d);
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1272.in", "r", stdin);
	freopen ("T1272.out", "w", stdout);
#endif

	scanf ("%d%d%d", &n, &k, &m);

	v.resize(n);
	color.resize(n);

	for (int i=0; i<k; ++i)
	{
		int u, t;
		scanf ("%d%d", &u, &t);
		v[u-1].push_back(t-1);
		v[t-1].push_back(u-1);
	}
	
	for (int i=0; i<n; ++i){
		if (!color[i]){
			dfs(i);
			++ans;
		}
	}

	printf ("%d", ans-1);
		
	return 0;
}