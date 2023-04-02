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

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1335.in", "r", stdin);
	freopen ("T1335.out", "w", stdout);
#endif

	scanf ("%d", &n);

	printf ("%d %d %d", n*n, n*n+n+1, n*n+1);


	return 0;
}