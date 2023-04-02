#include <iostream>
using namespace std;

int n, c1, t, c2;
int base, comb, unlim, m=0, s=0, mi;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1576.in", "r", stdin);
	freopen ("T1576.out", "w", stdout);
#endif

	scanf ("%d%d", &base, &c1);
	scanf("%d%d%d", &comb, &t, &c2);
	scanf ("%d", &unlim);
	scanf ("%d", &n);
	for (int i=0; i<n; ++i)
	{
		scanf ("%d:%d", &m, &s);
		mi=m;

		if (!mi && s>6)
			++mi;
		else if (mi && s)
			++mi;

		base+=c1*mi;
		t-=mi;
		if (t<0)
		{
			comb+=abs(t)*c2;
			t=0;
		}
	}

	printf ("Basic:     %d\nCombined:  %d\nUnlimited: %d", base, comb, unlim);

	return 0;
}