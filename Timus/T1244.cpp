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

int a[200000];
int p[200000];
int w, n, sum, x;
vector <int> v, ans;
vector <bool> b;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1244.in", "r", stdin);
	freopen ("T1244.out", "w", stdout);
#endif

	memset(p, -1, 200000);

	scanf ("%d%d", &w, &n);
	v.resize(n);
	b.resize(n);

	a[0]=1;

	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i]);
		sum+=v[i];
	}

	x=sum-w;

	for (int i=0; i<n; ++i)
	{
		for (int j=sum-v[i]; j>=0; --j)
		{
			if (a[j])
			{
				a[j+v[i]]+=a[j];
				if (a[j+v[i]]==1)
					p[j+v[i]]=i;
			}
		}
	}

	if (a[x]==0)
		printf ("0");
	else if (a[x]>1)
		printf ("-1");
	else{
		int l=p[x];
		while (l!=-1){
			ans.push_back(l+1);
			x-=v[l];
			l=p[x];
		}			

		for (int i=ans.size()-1; i>=0; --i)
			printf ("%d ", ans[i]);
	}
		
	return 0;
}