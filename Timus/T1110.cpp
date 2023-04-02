#include <iostream>
#include <cmath>
using namespace std;

int n, m, y;
bool res=false;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1110.in", "r", stdin);
	freopen ("T1110.out", "w", stdout);
#endif
	
	scanf ("%d%d%d", &n, &m, &y);
	for (int i=0; i<=m-1; ++i)
	{
		int p=1;
		for (int j=1; j<=n; ++j)
		{
			p*=i;
			p%=m;
		}
		if (p==y)
		{
			res=true;
			printf ("%d ", i);
		}
	}
	if (!res)
		printf("-1");
	
	return 0;
}