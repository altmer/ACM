#include <iostream>
using namespace std;

int A[10000010], k, p;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1537.in", "r", stdin);
	freopen ("T1537.out", "w", stdout);
#endif

	scanf ("%d%d", &k, &p);

	A[1]=0;
	A[2]=1%p;

	for (int i=3; i<=k; ++i)
	{
		if (i%2)
			A[i]=A[i-1]%p;		
		else
			A[i]=(A[i-1]+A[i/2])%p;
	}

	cout << A[k];

	return 0;
}