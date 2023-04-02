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

__int64 s, n, cur;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1515.in", "r", stdin);
	freopen ("T1515.out", "w", stdout);
#endif

	scanf ("%d", &n);

	for (int i=0; i<n; ++i){
		scanf ("%d", &cur);
		if (cur<=s+1){
			s+=cur;
		}
		else{
			printf ("%d", s+1);
			return 0;
		}
	}

	printf ("%d", s+1);

	return 0;
}