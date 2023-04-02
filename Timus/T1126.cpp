#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

multiset <int> S;
int A[50000];
int m;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1126.in", "r", stdin);
	freopen ("T1126.out", "w", stdout);
#endif

	scanf ("%d", &m);
	for (int i=0; i<m; ++i)
	{
		scanf ("%d", &A[i]);
		S.insert(A[i]);
	}

	printf ("%d\n", *(--S.end()));
	int j=m;

	scanf ("%d", &A[j]);

	while (A[j]!=-1)
	{
		S.erase(S.find(A[j-m]));
		S.insert(A[j++]);
		printf ("%d\n", *(--S.end()));
		scanf ("%d", &A[j]);
	}

	return 0;
}