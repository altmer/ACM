#include <iostream>
#include <cmath>
using namespace std;

double n, y, y2, x, dif;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1010.in", "r", stdin);
	freopen ("T1010.out", "w", stdout);
#endif

	scanf ("%lf", &n);

	scanf ("%lf%lf", &y, &y2);
	dif = fabs(y-y2);
	x=1;
	y=y2;

	for (int i=3; i<=n; ++i)
	{
		scanf ("%lf", &y2);
		if (fabs(y-y2)>dif)
		{
			x=i-1;
			dif=fabs(y-y2);
		}
		y=y2;
	}

	printf("%.0lf %.0lf", x, x+1);

	return 0;
}