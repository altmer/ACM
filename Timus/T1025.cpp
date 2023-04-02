#include <iostream>
#include <algorithm>
using namespace std;

int k, A[105];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1025.in", "r", stdin);
	freopen ("T1025.out", "w", stdout);
#endif

	cin >> k;

	for (int i=0; i<=k;++i)
		cin >> A[i];

	sort (A, A+k);

	int ans=0;
	for (int i=0; i<=k/2; ++i)
		ans+=A[i]/2+1;
	cout << ans;
	return 0;
}