#include <iostream>
#include <set>
using namespace std;

set <int> s;
int n, m, ans = 0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1196.in", "r", stdin);
	freopen ("T1196.out", "w", stdout);
#endif

	cin >> n;
	for (int i=1; i<=n; ++i)
	{
		int a;
		cin >> a;
		s.insert(a);
	}

	cin >> m;

	for (int i=1; i<=m; ++i)
	{
		int a;
		cin >> a;
		if (s.find(a)!=s.end()) 
			++ans;
	}

	cout << ans;

	return 0;
}