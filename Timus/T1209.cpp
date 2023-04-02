#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector <int> v;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1209.in", "r", stdin);
	freopen ("T1209.out", "w", stdout);
#endif
	v.reserve(65535);
	v.push_back(1);
	v.push_back(2);
	double i=4, step=3;
	double p = pow(2.0, 31)-1;
	while (i<p)
	{
		v.push_back(i);
		i+=step++;
	}

	cin >> n;

	for (int i=1; i<=n; ++i)
	{
		int p;
		cin >> p;
		if (binary_search (v.begin(), v.end(), p))
			cout << "1 ";
		else
			cout << "0 ";
	}



	return 0;
}