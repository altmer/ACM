#include <iostream>
#include <cmath>
using namespace std;

double const pi=3.14159265358979;
double h, w, x, y, r;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1550.in", "r", stdin);
	freopen ("T1550.out", "w", stdout);
#endif

	cin >> h >> w >> x >> y >> r;

	double res = w*w*h/3-h*pi*r*r*(w-2*fabs( (((y >= x && y >= -x) || (y < x && y < -x)) ? y : x)) )/w;

	printf ("%.3lf", res);

	return 0;
}