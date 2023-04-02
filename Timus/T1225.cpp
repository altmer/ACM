#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <stack>
using namespace std;

__int64 n, A[100];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1225.in", "r", stdin);
	freopen ("T1225.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A[0]=0;
	A[1]=2;
	A[2]=2;
	for (int i=3; i<=n; ++i)
		A[i]=A[i-1]+A[i-2];

	cout << A[n];

	return 0;
}