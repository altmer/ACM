#include <iostream>
using namespace std;

int A[102][102];
int n, m = -150;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1146.in", "r", stdin);
	freopen ("T1146.out", "w", stdout);
#endif

	cin >> n;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
		{
			cin >> A[i][j];
			A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1];
		}

	for (int i=1; i<=n; ++i)
	for (int j=1; j<=n; ++j)
	{
		for (int k=i; k<=n; ++k)
		for (int l=j; l<=n; ++l)
		{
			int sum = A[k][l]-A[k][j-1]-A[i-1][l]+A[i-1][j-1];
			if (sum>m) 
				m=sum;
		}
	}

	cout << m;
	return 0;
}