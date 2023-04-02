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

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1059.in", "r", stdin);
	freopen ("T1059.out", "w", stdout);
#endif

	printf ("0\n");
	scanf ("%d", &n);
	for (int i=1; i<=n; ++i){
		printf ("X\n*\n%d\n+\n", i);
	}

	return 0;
}