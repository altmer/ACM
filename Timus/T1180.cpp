#include <iostream>
using namespace std;

char ch;
int sum = 0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1180.in", "r", stdin);
	freopen ("T1180.out", "w", stdout);
#endif
	
	while (cin >> ch)
		sum+=ch-'0';

	if (sum%3)
	{
		cout << "1\n" << sum%3;
	}

	else cout << "2";

	return 0;
}