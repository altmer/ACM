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

int n,m;
vector <int> v, w;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1134.in", "r", stdin);
	freopen ("T1134.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	v.assign(n+1, 2);
	w.resize(m);

	v[0]=1;
	v[n]=1;

	for (int i=0; i<m; ++i){
		scanf ("%d", &w[i]);
	}

	sort (w.begin(), w.end());

	for (int i=0; i<m; ++i){
		v[w[i]]--;
		if (v[w[i]]==0 && w[i]<n){
			v[w[i]+1]--;
		}
	}

	bool res=true;
	for (int i=0; i<v.size(); ++i){
		if (v[i]<0){
			res=false;
			break;
		}
	}

	if (res)
		printf ("YES");
	else
		printf ("NO");
	
	return 0;
}