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

struct shpal{
	int l, r;
	bool operator < (shpal t){
		return l<t.l;
	}
	bool operator > (shpal t){
		return l>t.l && r>t.r;
	}
};

vector <shpal> v;
vector <int> L;
int ans, n;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1273.in", "r", stdin);
	freopen ("T1273.out", "w", stdout);
#endif

	scanf ("%d", &n);
	L.resize(n);
	v.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%d%d", &v[i].l, &v[i].r);
	}

	sort (v.begin(), v.end());

	for (int i=0; i<n; ++i){
		L[i]=1;
		for (int j=i-1; j>=0; --j){
			if (v[i]>v[j] && L[j]+1>L[i]){
				L[i]=L[j]+1;
			}
		}
		if (L[i]>ans)
			ans=L[i];
	}

	printf ("%d", n-ans);

	return 0;
}