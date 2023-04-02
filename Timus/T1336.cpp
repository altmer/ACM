#include <iostream>
using namespace std;

__int64 m, n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1336.in", "r", stdin);
	freopen ("T1336.out", "w", stdout);
#endif

	cin >> n;

	m=n*n;

	cout << m << endl;
	cout << n << endl;
	
	return 0;
}