#include <iostream>
#include <deque>
using namespace std;

deque <int> v;
int n;

int gcd (int &a, int &b)
{
	while (b)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1053.in", "r", stdin);
	freopen ("T1053.out", "w", stdout);
#endif

	cin >> n;

	for (int i=1; i<=n; ++i)
	{
		int a;
		cin >> a; 
		v.push_back(a);
	}

	while (v.size()!=1)
	{
		v[1]=gcd(v[0], v[1]);
		v.pop_front();
	}

	cout << v[0];
	
	return 0;
}