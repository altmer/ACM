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

double eps=1e-6;
double pi2=1.57079632679489;
double a, b, c, mx, my;

double fx (double x, double y,double a)
{
	return x*cos(a)+y*sin(a);
}

double fy (double x, double y, double a)
{
	return x*sin(a)+y*cos(a);
}

bool fit (double x, double y)
{
	for (double i=0; i<=pi2; i+=eps){
		if (fx(x,y,i)<=mx+eps && fy(x,y,i)<=my+eps)
			return true;
	}
	return false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1234.in", "r", stdin);
	freopen ("T1234.out", "w", stdout);
#endif

	scanf ("%lf%lf%lf%lf%lf", &a, &b, &c, &mx, &my);

	if (fit(a,b) || fit(a, c) || fit (b,c))
		printf ("YES");
	else
		printf ("NO");

	return 0;
}