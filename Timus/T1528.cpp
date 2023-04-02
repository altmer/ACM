#include <iostream>
using namespace std;

__int64 n, p, res;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1528.in", "r", stdin);
	freopen ("T1528.out", "w", stdout);
#endif

	do
	{
		scanf ("%d%d", &n, &p);
		res=1;
		if (p)
		{
			for (int i=1; i<=n; ++i)
			{
				res*=i%p;
				res%=p;
			}
			printf ("%I64d\n", res);
		}
	}
	while (n && p);
	
	return 0;
}