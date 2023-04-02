#include <iostream>
using namespace std;

__int64 A[11];
int n;

__int64 fact (int n)
{
	if (n<=1)
		return 1;
	else
		return n*fact(n-1);
}

__int64 c (int n, int k)
{
	return fact(k)/(fact(n)*fact(k-n));
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1142.in", "r", stdin);
	freopen ("T1142.out", "w", stdout);
#endif

	A[0]=1;
	A[1]=1;

	for (int k=2; k<=10; ++k)
		for (int i=1; i<=k; ++i)
			A[k]=A[k]+c(i,k)*A[k-i];
	
	while (n!=-1)
	{
		scanf ("%d", &n);
		if (n!=-1)
					printf ("%d\n", A[n]);
	}

	return 0;
}