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

int n, m, num;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf ("%d", &num);

	for (int i=0; i<num; ++i){
		scanf ("%d%d", &n, &m);
		if (n==m){
			printf ("%.6lf\n", 1.0/double(n+1));
		}
		else if (n>m){
			printf ("%.6lf\n", double(n-m+1)/double(n+1));
		}
		else
			printf ("0\n");
	}

	return 0;
}