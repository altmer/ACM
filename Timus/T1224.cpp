#include <iostream>
using namespace std;

__int64 n, m, res;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1224.in", "r", stdin);
	freopen ("T1224.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	if (n<=m)
		res=2*(n-1);
	else
		res=2*m-1;
	cout << res;

	return 0;
}