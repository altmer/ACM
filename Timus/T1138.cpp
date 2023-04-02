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
int n, s, ans;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1138.in", "r", stdin);
	freopen ("T1138.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &s);
	v.assign(n+1, 0);
	
	v[s]=1;
	ans=v[s];
	for (int i=s; i<=n; ++i){
		if (v[i]!=0){
			if (v[i]>ans)
				ans=v[i];
			for (int j=1; j<=100; ++j){
				if ((i*j)%100==0){
					int k=(i*j)/100;
					if (i+k<=n &&v[i+k]<v[i]+1){
						v[i+k]=v[i]+1;
					}
				}
			}
		}
	}

	printf ("%d", ans);

	return 0;
}