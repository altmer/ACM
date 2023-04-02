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

int n, ans;
vector <int> v;
vector <bool> u;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1431.in", "r", stdin);
	freopen ("T1431.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	u.resize(n);
	for (int i=0; i<n; ++i)
		scanf ("%d", &v[i]);
	
	sort(v.begin(), v.end());

	for (int i=0; i<n; ++i)
	{
		if (!u[i])
		{
			for (int j=0; j<=i; ++j)
			{
				if (!u[j] && abs(v[i]-v[j])==1)
				{
					u[i]=true;
					u[j]=true;
					++ans;
					break;
				}
			}
		}
	}

	for (int i=0; i<n; ++i)
		if (!u[i])
			++ans;

	printf ("%d", ans);
	

	return 0;
}