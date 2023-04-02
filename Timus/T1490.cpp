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

__int64 x, q, p, z, y,r;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1490.in", "r", stdin);
	freopen ("T1490.out", "w", stdout);
#endif

	scanf("%I64d",&r);

	x=r;
	q=r*r;

	do{
		p=q-y*y;
		while( x*x >= p && x >= 0 )
			x--;
		z+=(x+1);
		y++;
	}while(y<r);

	z*=4;
	cout<<z;

	return 0;
}