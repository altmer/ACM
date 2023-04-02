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

int a[55];
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1260.in", "r", stdin);
	freopen ("T1260.out", "w", stdout);
#endif

	a[0]=1;
	a[1]=1;
	a[2]=2;

	scanf ("%d", &n);

	for (int i=3; i<n; ++i)
	{
		a[i]=a[i-3]+a[i-1]+1;
	}

	printf ("%d", a[n-1]);

	

	return 0;
}