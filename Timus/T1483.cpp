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
	freopen ("T1483.in", "r", stdin);
	freopen ("T1483.out", "w", stdout);
#endif

	scanf ("%d", &n);

	printf ("%d ", n-1);
	if (n%2==0)
		printf ("%d", 3*((n-2)/2)+1);
	else
		printf ("%d", 3*((n - 1) / 2));


	return 0;
}