#include <iostream>

using namespace std;

int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1349.in", "r", stdin);
	freopen ("T1349.out", "w", stdout);
#endif

	cin >> n;

	if (n==0 || n>2)
		cout << "-1";
	else if (n==1)
		cout << "1 2 3";
	else 
		cout << "3 4 5";

	return 0;
}