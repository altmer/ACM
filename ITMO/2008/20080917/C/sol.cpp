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
#include <limits>
#include <set>
using namespace std;

int n, p;
double s;

int main (void)
{
	freopen ("credit.in", "r", stdin);
	freopen ("credit.out", "w", stdout);

	cin >> n >> s >> p;

	int sk=int(s/double(n));
	double cur=s;

	for (int i=1; i<n; ++i){
		printf ("%d %d.00 %.2lf %.2lf\n", i, sk, cur*double(p)/100.0, cur*double(p)/100.0+sk);
		cur-=sk;
	}
	printf ("%d %.2lf %.2lf %.2lf\n", n, cur, cur*double(p)/100.0, cur*double(p)/100.0+cur);

	return 0;
}