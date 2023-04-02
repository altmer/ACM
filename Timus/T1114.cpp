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

unsigned __int64 n, a, b, ans, a1, a2, a3, a4, a5, a6;

unsigned __int64 fact (unsigned __int64 x, unsigned __int64 y){
	unsigned __int64 res=1, d=x-y;
	for (unsigned __int64 i=1; i<=d; ++i){
		res*=(i+y);
		res/=i;
	}
	return res;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1114.in", "r", stdin);
	freopen ("T1114.out", "w", stdout);
#endif

	cin >> n >> a >> b;

	ans=fact(n+a, a)*fact(n+b, b);

	cout << ans;

	return 0;
}