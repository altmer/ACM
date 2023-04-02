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

int n, cur;
vector <bool> S(50100);

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("sums.in", "r", stdin);
	freopen ("sums.out", "w", stdout);
#endif

	scanf ("%d", &n);
	S[0]=true;

	for (int i=0; i<n; ++i){
		scanf ("%d", &cur);
		for (int j=S.size()-1-cur; j>=0; --j){
			if (S[j]){
				S[j+cur]=true;
			}
		}
	}

	int ans=0;
	for (int i=0; i<S.size(); ++i){
		if (S[i])
			ans++;
	}

	printf ("%d", ans);

	return 0;
}