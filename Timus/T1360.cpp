#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

double pi=3.1415926535897932384626433832795;
double x, y, eps;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1360.in", "r", stdin);
	freopen ("T1360.out", "w", stdout);
#endif

	scanf ("%lf%lf%lf", &x, &y, &eps);
	double t = acos(y);
	while(true){
		t += 2.0*pi;
		if (sqrt((cos(t)-y)*(cos(t)-y)+(sin(sqrt(t))-x)*(sin(sqrt(t))-x))<=eps){
			printf ("%.4lf\n", t);
			return 0;
		}
	}
	
	return 0;
}