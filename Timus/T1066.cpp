#include <iostream>
using namespace std;

int n;
double A[1000];
double good, bad, mid;

bool isAbove (double mid)
{
	A[1]=mid;
	for (int i=2; i<n; ++i)
	{
		A[i]=2*A[i-1]-A[i-2]+2;
		if (A[i]<0)
			return false;
	}
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1066.in", "r", stdin);
	freopen ("T1066.out", "w", stdout);
#endif

	scanf ("%d%lf", &n, &A[0]);

	good=A[0];
	bad=0;

	while (true)
	{
		mid = (good+bad)/2;
		if (mid==good || mid==bad)
			break;

		if (isAbove(mid))
			good=mid;
		else
			bad=mid;	
	}

	A[1]=good;
	for (int i=2; i<n; ++i)
		A[i]=2*A[i-1]-A[i-2]+2;

	printf ("%.2lf", A[n-1]);

	return 0;
}