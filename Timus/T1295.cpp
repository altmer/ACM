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

int n;

int mpow (int x){
	int res=x;
	for (int i=2; i<=n; ++i){
		res*=x;
		res%=1000000;
	}
	return res;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1295.in", "r", stdin);
	freopen ("T1295.out", "w", stdout);
#endif

	scanf ("%d", &n);

	int res=1+mpow(2)+mpow(3)+mpow(4);

	int ans=0;
	while (res%10==0){
		++ans;
		res/=10;
	}
	printf ("%d", ans);

	return 0;
}