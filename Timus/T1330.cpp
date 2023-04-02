#include <iostream>
using namespace std;

int n, q;
int a[10001] = {0}, sum[10001] = {0};

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1330.in", "r", stdin);
	freopen ("T1330.out", "w", stdout);
#endif

	cin >> n;

	for (int i=1; i<=n; ++i)
	{
		cin >> a[i];
		sum[i]=sum[i-1]+a[i];
	}

	cin >> q;

	for (int i=1; i<=q; ++i)
	{
		int x, y;
		cin >> x >> y;
		cout << sum[y]-sum[x]+a[x] << "\n";
	}

	return 0;
}