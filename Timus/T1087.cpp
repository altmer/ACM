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

vector <int> a, k;
int n, m;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1087.in", "r", stdin);
	freopen ("T1087.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	a.resize(n+1);
	k.resize(m);
	a[0]=1;

	for (int i=0; i<m; ++i)
	{
		scanf ("%d", &k[i]);
	}
	
	for (int i=1; i<=n; ++i)
	{
		for (int j=0; j<m; ++j)
		{
			if (i>=k[j])
			{
				if (a[i-k[j]]==2)
				{
					a[i]=1;
					break;
				}
			}
		}
		if (a[i]==0)
			a[i]=2;
	}

	printf ("%d", a[n]);

	return 0;
}