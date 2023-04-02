#include <iostream>
using namespace std;
int n;

int main (void)
{
	#ifndef ONLINE_JUDGE
	freopen ("T1082.in", "r", stdin);
	freopen ("T1082.out", "w", stdout);
	#endif
	
	cin >> n;
	for (int i=1;i<=n; ++i)
		cout << i << " ";
  
	return 0;
}
