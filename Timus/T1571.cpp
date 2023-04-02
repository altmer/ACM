#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int n, r;
vector < vector < int > > v;
int A[200000], C[200000];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1579.in", "r", stdin);
	freopen ("T1579.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &r);
	
	v.resize(200000);
	for (int i=0; i<n; ++i)
		scanf ("%d", &A[i]);

	C[0]=0;
	v[0].push_back(1);
	int st=0;
	int c=1;
	for (int i=1; i<n; ++i)
	{
		if (A[i]-A[st]>r)
		{
			C[i]=C[st++];
			v[C[i]].push_back(i+1);
		}
		else
		{
			C[i]=c++;
			v[C[i]].push_back(i+1);
		}
	}

	printf ("%d\n", c);
	for (int i=0; i<c; ++i)
	{
		printf ("%d ", v[i].size());
		for (int j=0; j<v[i].size(); ++j)
			printf ("%d ", v[i][j]);
		printf ("\n");
	}

	return 0;
}