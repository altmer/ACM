#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <stack>
using namespace std;

int n, s, k;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1228.in", "r", stdin);
	freopen ("T1228.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &s);

	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &k);
		printf ("%d ", s/k-1);
		s/=(s/k);
	}

	return 0;
}
