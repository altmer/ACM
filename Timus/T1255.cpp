#include <iostream>
using namespace std;

int n, k;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1255.in", "r", stdin);
	freopen ("T1255.out", "w", stdout);
#endif

	cin >> n >> k;

	if (n<k)
		cout << "0";
	else if (2*(n%k)-k<0)
	{
		int ans =(n/k)*(n+n%k);
		cout << ans;
	}
	else
	{
		int ans = (n/k)*(n+n%k) + 2*(n%k)-k;
		cout << ans;
	}

	return 0;
}