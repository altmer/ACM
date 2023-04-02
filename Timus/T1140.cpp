#include <iostream>
#include <string>
using namespace std;

int n, x, y, z;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1140.in", "r", stdin);
	freopen ("T1140.out", "w", stdout);
#endif

	scanf ("%d\n", &n);

	int k;
	char ch;
	for (int i=0; i<n; ++i)
	{
		cin >>  ch >> k;
		switch (ch)
		{
		case 'X': x+=k;
			break;
		case 'Y': x+=k;
			z+=k;
			break;
		case 'Z': z+=k;
			break;
		}
	}

	y=0;

	if (x>0 && z>0)
		y=min (x, z);
	else if (x<0 && z<0)
		y=-min(-x, -z);

	x-=y;
	z-=y;

	printf ("%d\n", bool(x)+bool(y)+bool(z));
	if (x)
		printf ("X %d\n", -x);
	if (y)
		printf ("Y %d\n", -y);
	if (z)
		printf ("Z %d\n", -z);


	return 0;
}