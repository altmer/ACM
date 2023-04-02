#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector <vector <int> > V;
vector <int> E;
int n, m, time;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1280.in", "r", stdin);
	freopen ("T1280.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	V.resize (n);
	E.resize (n);

	for (int i=0; i<m; ++i)
	{
		int u, v;
		scanf ("%d%d", &u, &v);
		V[u-1].push_back (v-1);
		++E[v-1];
	}

	int cur;
	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &cur);
		if (E[--cur])
		{
			printf ("NO");
			return 0;
		}
		for (int i=0; i<V[cur].size(); ++i)
			--E[V[cur][i]];
	}

	printf ("YES");

	return 0;
}