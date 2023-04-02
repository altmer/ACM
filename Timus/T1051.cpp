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

int n, m;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1051.in", "r", stdin);
	freopen ("T1051.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	int t=n;
	n=min(t, m);
	m=max(t, m);

	if (n==1){
		printf ("%d", (m+1)/2);
	}
	else if (n%3==0 || m%3==0)
		printf ("2");
	else
		printf ("1");

	return 0;
}