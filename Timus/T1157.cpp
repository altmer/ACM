#include <iostream>
#include <cmath>
using namespace std;

const int M=10000;
int A[M+1], n, m, l;

int num_div (int n)
{
	int count=0;
	for (int i=1; i<=sqrt(double(n)); ++i)
	{
		if (n%i==0)
		{
			++count;
		}
	}
	return count;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1157.in", "r", stdin);
	freopen ("T1157.out", "w", stdout);
#endif

	A[0]=0;
	A[1]=0;
	
	for (int i=2; i<=M; ++i)
	{
		A[i]=num_div(i);
	}

	scanf ("%d%d%d", &n, &m, &l);

	for (int i=1; i<=M-l; ++i)
	{
		if (A[i]==n && A[i+l]==m)
		{
			printf ("%d", i+l);
			return 0;
		}
	}

	printf ("0");

	return 0;
}