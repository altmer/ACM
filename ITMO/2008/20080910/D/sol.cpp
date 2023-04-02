#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

int n, k;
int cur_fr;
int ans = 0;

int main (void)
{
	freopen ("curfew.in", "r", stdin);
	freopen ("curfew.out", "w", stdout);

	scanf ("%d%d", &n, &k);
	cur_fr=k;
	
	for (int i=0; i<n; ++i){
		int tmp;
		scanf ("%d", &tmp);
		if (tmp<=cur_fr){
			cur_fr-=tmp;
		}
		else{
			ans++;
			cur_fr=k-tmp;
			if (cur_fr<0){
				ans=-1;
				break;
			}
		}
		if (i==n-1 && cur_fr){
			if (n==1){
				ans=-1;
			}
			else if (!ans){
				ans=1;
			}
		}
	}

	printf ("%d", ans);

	return 0;
}