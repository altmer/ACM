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

vector <int> v1, v2;
int n, m;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1249.in", "r", stdin);
	freopen ("T1249.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	v1.resize(m);
	v2.resize(m);

	for (int i=0; i<m; ++i)
		scanf ("%d", &v1[i]);

	for (int i=1; i<n; ++i)
	{
		for (int j=0; j<m; ++j)
			scanf ("%d", &v2[j]);

		for (int j=0; j<m-1; ++j)
		{
			if ( v2[j] && ( (v1[j] && v2[j+1] && !v1[j+1]) || (v1[j] && v1[j+1] && !v2[j+1]) || (v2[j+1] && v1[j+1] && !v1[j]))){
				printf ("No");
				return 0;
			}
			if (!v2[j] && v2[j+1] && v1[j+1] && v1[j]){
				printf ("No");
				return 0;
			}
		}
		v1.swap(v2);			
	}

	printf ("Yes");

	return 0;
}