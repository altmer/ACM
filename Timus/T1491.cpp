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

int n;
vector <int> ans, v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1491.in", "r", stdin);
	freopen ("T1491.out", "w", stdout);
#endif

	scanf ("%d", &n);
	ans.resize(n+2);
	v.resize(n+2);

	for (int i=0; i<n+1; ++i){
		int a, b,c;
		scanf ("%d%d%d", &a, &b, &c);
		v[a]+=c;
		v[b+1]-=c;
	}

	int dif=0;
	for (int i=1; i<=n; ++i){
		dif+=v[i];
		ans[i]+=dif;
	}

	for (int i=1; i<=n; ++i){
		printf ("%d ", ans[i]);
	}

	return 0;
}