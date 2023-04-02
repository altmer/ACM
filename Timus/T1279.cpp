#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector <int> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1279.in", "r", stdin);
	freopen ("T1279.out", "w", stdout);
#endif
	
	scanf ("%d%d%d", &n, &m, &k);
	for (int i=0; i<n*m; ++i)
	{
		int a;
		scanf ("%d", &a);
		v.push_back(a);
	}

	sort (v.begin(), v.end());

	while (k>0)
	{
		int i=1, count=1, rem=0;
		while (i!=v.size() && v[i]==v[i-1])
		{
			++count;
			++i;
		}

		if (i!=v.size())
			rem=k-count*(v[i]-v[i-1]);

		if (rem<0 || i==v.size())
		{
			v[0]+=k/i;
			k=0;
		}
		else
		{
			for (int j=0; j<i; ++j)
				v[j]=v[i];
			k=rem;
		}
	}

	printf ("%d", v[0]);

	return 0;
}