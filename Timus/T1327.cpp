#include <iostream>
using namespace std;

int a, b, ans=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1327.in", "r", stdin);
	freopen ("T1327.out", "w", stdout);
#endif

	cin >> a;
	cin >> b;

	for (int i=a; i<=b; ++i)
		if (i%2==1)
			++ans;
	cout << ans;

	return 0;
}