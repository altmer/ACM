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

int n, k;
vector <int> v;
int maxx, ans;

void bs (int l, int r)
{
	if (l>r)
		return;
	int x=(l+r)/2;
	int num=0;
	for (int i=0; i<v.size(); ++i)
		num+=v[i]/x;
	if (num==k)
	{
		ans=x;
		bs(x+1, r);
	}
	else if (num<k)
	{
		bs (l, x-1);
	}
	else
	{
		ans=max(ans,x);
		bs (x+1, r);
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1184.in", "r", stdin);
	freopen ("T1184.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &k);

	for (int i=0; i<n; ++i)
	{
		double t;
		scanf ("%lf", &t);
		v.push_back(int(t*100));
		if (v[i]>maxx)
			maxx=v[i];
	}

	bs(1, maxx);

	double t=double(ans)/100;

	printf ("%.2lf", t);

	return 0;
}