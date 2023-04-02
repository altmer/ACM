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

int n, d=1e+9;
vector <int> v, ans(10);

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1150.in", "r", stdin);
	freopen ("T1150.out", "w", stdout);
#endif

	scanf ("%d", &n);

	while (n/d==0)
		d/=10;

	// для старшего разряда

	for (int i=1; i<n/d; ++i)
	{
		ans[i]+=d;
	}

	ans[n/d]+=n%d+1;
	d/=10;

	while (d>=1)
	{
		for (int i=1; i<=9; ++i)
		{
			ans[i]+=d*(n/(d*10));
		}
		ans[0]+=d*(n/(d*10)-1);
		for (int i=0; i<(n/d)%10; ++i)
		{
			ans[i]+=d;
		}
		ans[(n/d)%10]+=n%d+1;
		d/=10;
	}

	for (int i=0; i<=9; ++i)
		printf ("%d\n", ans[i]);

	return 0;
}