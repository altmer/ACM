#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
__int64 ans;
vector <int> p, v;

int gcd (int a, int b)
{
	while (a)
	{
		int t=b%a;
		b=a;
		a=t;
	}
	return b;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1024.in", "r", stdin);
	freopen ("T1024.out", "w", stdout);
#endif

	scanf ("%d", &n);
	p.resize(n);
	v.resize(n);
	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &p[i]);
	}

	for (int i=0; i<n; ++i)
	{
		int k=1;
		int j=p[i]-1;
		while (i!=j)
		{
			++k;
			j=p[j]-1;
		}
		v[i]=k;
	}
	ans=v[0];
	for (int i=1; i<n; ++i)
	{
		ans*=v[i]/gcd(ans, v[i]);
	}
	printf ("%d", ans);

	return 0;
}