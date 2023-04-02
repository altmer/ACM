#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

const double eps=1e-9;
int n;
double x, y;
double sx=-1001, sy=-1001;
double ans=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; ++i){
		cin >> x >> y;
		ans=max(ans, sqrt((x-sx)*(x-sx)+(y-sy)*(y-sy)));
	}

	printf ("%.9lf %.9lf %.9lf", sx, sy, ans);

	return 0;
}