#include <iostream>
using namespace std;

int n, k, A[100];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1506.in", "r", stdin);
	freopen ("T1506.out", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> A[i];
	
	int row=n/k;
	while (row*k
		++row;

	
	
	for (int i=0; i<row; ++i)
	{
		for (int j=0; j<n; ++j)
			if (j%row==i)
				printf ("%4d", A[j]);	
		printf ("\n");
	}

	return 0;
}