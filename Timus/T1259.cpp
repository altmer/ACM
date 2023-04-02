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

int gcd (int v1, int v2)
{
 while (v2)
 {
  int temp = v2;
  v2 = v1 % v2;
  v1 = temp;
 }
 return v1;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1259.in", "r", stdin);
	freopen ("T1259.out", "w", stdout);
#endif

	scanf ("%d", &n);
	int k=(n-1)/2;
	int ans=0;
	for (int i=1; i<=k; ++i){
		if (gcd(i, n)==1)
			++ans;
	}
	printf ("%d", ans);

	return 0;
}