#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int cop, rob=0, n, A;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1191.in", "r", stdin);
	freopen ("T1191.out", "w", stdout);
#endif

	scanf ("%d%d", &cop, &n);
	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &A);
		rob+=A;
		if (cop<rob)
		{
			printf ("YES");
			return 0;
		}
		int st=cop-rob;
		int rem = st%A;
		
		cop+=A-rem;
	}

	printf ("NO");

	return 0;
}