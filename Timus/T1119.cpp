#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct coord 
{
	int x, y;
	coord():x(0), y(0) {}
	bool operator < (coord &s)
	{
		if (x==s.x)
			return y<s.y;
		return x<s.x;
	}

	bool operator << (coord &s)
	{
		return (x<s.x && y<s.y);
	}
};

int n, m, k;
coord diag[100];

int round (double &s)
{
 return int(floor (s+0.5));
}

int main (void)
{

#ifndef ONLINE_JUDGE
	freopen ("T1119.in", "r", stdin);
	freopen ("T1119.out", "w", stdout);
#endif

	int max[100];
	scanf ("%d%d\n%d", &n, &m, &k);
	for (int i=0; i<k; ++i)
	{
		scanf ("%d%d\n", &diag[i].x, &diag[i].y);
		max[i]=1;
	}

	sort (diag, diag+k);

	for (int i=1; i<k; ++i)
		for (int j=0; j<i; ++j)
			if (diag[j]<<diag[i] && max[i]<max[j]+1)
				max[i]=max[j]+1;

	int max_val=0;
	for (int i=0; i<k; ++i)
		if (max[i]>max_val)
			max_val=max[i];

	double ans = (m+n-2*max_val)*100 + sqrt(2.0)*max_val*100;

	cout << round (ans);
		
	return 0;
}