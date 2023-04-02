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

struct coord{
	int x, y;
	bool operator < (coord t){
		if (y==t.y)
			return x<t.x;
		return y<t.y;
	}
};

coord minn, a, b;
int ind, n;
vector <coord> v;

int vp (coord a, coord b)
{
	return a.x*b.y-a.y*b.x;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1246.in", "r", stdin);
	freopen ("T1246.out", "w", stdout);
#endif

	scanf ("%d", &n);
	minn.x=1e+9;
	minn.y=1e+9;

	v.resize(n+2);

	for (int i=1; i<=n; ++i)
	{
		scanf ("%d%d", &v[i].x, &v[i].y);
		if (v[i]<minn){
			minn=v[i];
			ind=i;
		}
	}

	v[0]=v[n];
	v[n+1]=v[1];

	a.x=v[ind-1].x-v[ind].x;
	a.y=v[ind-1].y-v[ind].y;
	b.x=v[ind+1].x-v[ind].x;
	b.y=v[ind+1].y-v[ind].y;

	if (vp (a, b)>0)
		printf ("cw");
	else
		printf ("ccw");


	return 0;
}