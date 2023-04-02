#include <iostream>
using namespace std;

int W[501], B[501], A[501][501];
int n, K;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1167.in", "r", stdin);
	freopen ("T1167.out", "w", stdout);
#endif
	
	cin >> n >> K;

	for (int i=1; i<=n; ++i)
	{
		bool a;
		cin >> a;
		if (a)
		{
			B[i]=B[i-1]+1;
			W[i]=W[i-1];
		}
		else
		{
			W[i]=W[i-1]+1;
			B[i]=B[i-1];
		}
	}

	for (int i=1; i<=n;++i)
		A[1][i]=B[i]*W[i];

	for (int i=2; i<=K; ++i)
		for (int j=1; j<=n; ++j)
		{
			int min=1000000;
			bool res=0;
			for (int k=j-1; k>0; --k)
			{
				res=1;
				int cur = A[i-1][k] +(B[j]-B[k])*(W[j]-W[k]);
				if (cur<min)
					min=cur;
			}
			A[i][j]=min*res;
		}

	cout << A[K][n];

	return 0;
}