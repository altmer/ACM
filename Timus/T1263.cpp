#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int V[10000], n, m;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1263.in", "r", stdin);
	freopen ("T1263.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);

	for (int i=0; i<m; ++i)
	{
		int v;
		scanf ("%d", &v);
		++V[v-1];
	}

	for (int i=0; i<n; ++i)
	{
		double ans;
		ans=(double(V[i])/double(m))*100;
		printf ("%.2lf%%\n", ans);
	}

	return 0;
}