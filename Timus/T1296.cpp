#include <iostream>
#include <string>
using namespace std;

int sum=0, m=0, n, cur;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1296.in", "r", stdin);
	freopen ("T1296.out", "w", stdout);
#endif

	scanf ("%d", &n);

	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &cur);
		sum+=cur;
		if (sum<0)
			sum=0;
		if (sum>m)
			m=sum;
	}

	printf ("%d", m);

	return 0;
}