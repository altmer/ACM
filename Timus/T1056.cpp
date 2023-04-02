#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int n, m;
vector < vector <int> > A;
bool out [10000], toout[10000];
int son [10000];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1056.in", "r", stdin);
	freopen ("T1056.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize (n);

	for (int i=1; i<=n-1; ++i)
	{
		int j;
		scanf ("%d", &j);
		A[i].push_back(j-1);
		A[j-1].push_back(i);
		++son[j-1];
		++son[i];
	}

	int num=n;

	while (num>2)
	{
		for (int i=0; i<n; ++i)
		{
			if (son[i]==1)
			{
				toout[i]=true;
				son[i]=0;
				--num;
			}
		}

		for (int i=0; i<n; ++i)
			if (toout[i]&&!out[i])
			{
				for (int k=0; k<A[i].size(); ++k)
				{
					if (!out[A[i][k]])
					{
						--son[A[i][k]];
						break;
					}
				}
				out[i]=true;
			}
	}

	for (int i=0; i<n; ++i)
		if (!out[i])
			printf ("%d ", i+1);
				

	return 0;
}