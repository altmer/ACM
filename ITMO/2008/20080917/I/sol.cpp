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

long long n=2;
long long ans;
long long s;

int main (void)
{
	freopen ("building.in", "r", stdin);
	freopen ("building.out", "w", stdout);

	cin >> s;

	for (long long n=1; n<=70000; ++n){
		long long t=n;
		t*=(n-1L);
		t/=2;
		if (t<s && (s-t)%n==0)
			ans=(s-t)/n;
	}

	cout << ans;

	return 0;
}