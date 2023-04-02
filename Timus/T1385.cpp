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
	freopen ("T1385.in", "r", stdin);
	freopen ("T1385.out", "w", stdout);
#endif

	scanf ("%d", &n);

	if (n==1)
		printf ("14");
	else if (n==2)
		printf ("155");
	else{
		printf ("1575");
		for (int i=3; i<n; ++i)
			printf ("0");
	}
	
	return 0;
}

