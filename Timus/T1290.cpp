#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector <int> v;
int n;

bool sortf (int &a, int &b)
{
	return a>b;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1290.in", "r", stdin);
	freopen ("T1290.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);

	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &v[i]);
	}

	sort (v.begin(), v.end(), sortf);

	for (int i=0; i<n; ++i)
	{
		printf ("%d\n", v[i]);
	}	

	return 0;
}