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

int n, m, k;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1107.in", "r", stdin);
	freopen ("T1107.out", "w", stdout);
#endif

	scanf ("%d%d%d\n", &n, &m, &k);
	printf ("YES\n");
	for (int i=0; i<m; ++i){
		int t, t2;
		scanf ("%d", &t);
		printf ("%d\n", 2-(t%2));
		for (int j=0; j<t; ++j){
			scanf ("%d", &t2);
		}
	}

	return 0;
}