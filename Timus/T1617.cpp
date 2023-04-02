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

vector <int> a(1000);
int n;
int ans;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1617.in", "r", stdin);
	freopen ("T1617.out", "w", stdout);
#endif

	scanf ("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int t;
		scanf ("%d", &t);
		a[t]++;
	}

	for (int i=0; i<a.size(); ++i)
	{
			ans+=a[i]/4;
	}

	printf ("%d",  ans);

	return 0;
}