#include <iostream>
#include <math.h>
using namespace std;

long x, y;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1214.in", "r", stdin);
	freopen ("T1214.out", "w", stdout);
#endif

	cin >> x >> y;

	if (x<0 || y<0 || (x+y)%2==0)
		cout << x << " " << y;
	else
		cout << y << " " << x;
	
	return 0;
}