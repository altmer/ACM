#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n, k;
double u, v;
__int64 TL, TP, TLD;
__int64 MT;
int ans=1;
__int64 U, V;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1602.in", "r", stdin);
	freopen ("T1602.out", "w", stdout);
#endif

	scanf ("%d%d%lf%lf", &n, &k, &u, &v);
	U=u*100000;
	V=v*100000;

	MT=(n-1)*U;

	TLD=(k-1)*V+15*100000;

	for (int i=n; i>=1; --i)
	{
		TL=max(TP, TLD)+(i-1)*V*2+5*100000;
		
		if (TL<MT || (TL==MT && ans==1))
		{
			MT=TL;
			ans=i;
		}
		TP+=U;
	}

	printf ("%d", ans);

	return 0;
}