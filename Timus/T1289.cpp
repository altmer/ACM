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
	freopen ("T1295.in", "r", stdin);
	freopen ("T1295.out", "w", stdout);
#endif

	scanf ("%d", &n);
	n=n/2-1;

	if (n==0){
		printf ("10");
		return 0;
	}

	for (int i=0; i<n; ++i)
		printf ("1");

	printf ("0");

	for (int i=0; i<n-1; ++i)
		printf ("8");
	printf ("9");

	printf ("0");


	return 0;
}