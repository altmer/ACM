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

vector <int> w;
int n, k;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1081.in", "r", stdin);
	freopen ("T1081.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &k);

	w.resize(44);
	w[0]=2;
	w[1]=3;

	for (int i=2; i<n; ++i)
		w[i]=w[i-1]+w[i-2];

	if (k>w[n-1])
	{
		printf ("-1");
		return 0;
	}

	k--;

	for (int i=0; i<n-1; ++i)
	{
		if (k/w[n-2-i]==0)
			printf ("0");
		else
		{
			printf ("1");
			k%=w[n-2-i];
		}
	}

	if (k)
		printf ("1");
	else
		printf ("0");

	return 0;
}