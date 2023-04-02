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

vector <vector <bool> > A;
vector <int> match;
vector <bool> v, res;
int m, n, k;
int ans=0;

bool find_pair (int k){
	if (v[k])
		return false;

	v[k]=true;

	for (int i=0; i<m; ++i){
		if (A[k][i] && (match[i]==-1) ){
			match[i]=k;
			return true;
		}
	}
	for (int i=0; i<m; ++i){
		if (A[k][i] && match[i]!=-1 && (find_pair(match[i])) ){
			match[i]=k;
			return true;
		}
	}
	return false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1109.in", "r", stdin);
	freopen ("T1109.out", "w", stdout);
#endif

	scanf ("%d%d%d", &n, &m, &k);
	match.assign(m, -1);
	res.assign(n, false);
	A.assign(n,vector<bool>(m,false));

	for (int i=0; i<k; ++i){
		int q, w;
		scanf ("%d%d", &q, &w);
		A[q-1][w-1]=true;
	}

	for (int i=0; i<n; ++i){
		v.assign(n, false);
		if (find_pair(i)){
			++ans;
			res[i]=true;
		}
	}

	for (int i=0; i<n; ++i)
		if (!res[i])
			++ans;
	for (int i=0; i<m; ++i)
		if (match[i]==-1)
			++ans;

	printf ("%d\n", ans);
	return 0;
}