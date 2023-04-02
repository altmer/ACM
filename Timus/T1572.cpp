#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int t, a;
int n, ans;
double hole;

double max_fig (int t, double a)
{
	switch (t)
	{
	case 1: 
		return 2.0*a;
	case 2:
		return sqrt(2.0)*a;
	case 3:
		return a;
	}
}

double min_fig (int t, double a)
{
	switch (t)
	{
	case 1:
		return 2.0*a;
	case 2: 
		return a;
	case 3:
		return a*sqrt(3.0)/2.0;
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1290.in", "r", stdin);
	freopen ("T1290.out", "w", stdout);
#endif

	scanf ("%d%d%d", &t, &a, &n);
	hole=max_fig(t, a);

	for (int i=0; i<n; ++i)
	{
		scanf ("%d%d", &t, &a);
		if (min_fig(t, a)<=hole)
			++ans;
	}

	printf ("%d", ans);
	
	return 0;
}