#include <iostream>
#include <algorithm>
using namespace std;

int A[500000];
int n, k, out;
int cur=1, ans=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1510.in", "r", stdin);
	freopen ("T1510.out", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; ++i)
	{
		scanf("%d",  &A[i]);
	}

	sort (A, A+n);

	for (int i=1; i<n; ++i)
	{
		if (A[i]==A[i-1])
			++cur;
		else
		{
			if (cur>ans)
			{
				ans=cur;
				out=A[i-1];
			}
			cur=1;
		}
	}

	if (cur>ans)
	{
		ans=cur;
		out=A[n-1];
	}

	cout << out;

	return 0;
}