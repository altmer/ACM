#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

double a, b, per;
int ans;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1283.in", "r", stdin);
	freopen ("T1283.out", "w", stdout);
#endif

	scanf ("%lf%lf%lf", &a, &b, &per);

	while (a>b)
	{
		a-=a*per/100;
		++ans;
	}

	cout << ans;

	return 0;
}