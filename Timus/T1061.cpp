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

int n, k;
deque <int> W;
int res, ans=1e+9, num;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1061.in", "r", stdin);
	freopen ("T1061.out", "w", stdout);
#endif

	scanf("%d%d\n", &n, &k);
	int t=n/80;
	if (n%80!=0)
		++t;

	int step=0;
	for (int i=0; i<t; ++i){
		char str[100];
		scanf ("%s", str);
		for (int j=0; j<strlen(str); ++j){
			step++;
			if (str[j]=='*'){
				if (W.size()==k && res<ans){
					ans=res;
					num=step-k;
				}
				res=0;
				W.clear();
			}
			else{
				if (W.size()<k){
					int y=str[j]-'0';
					W.push_back(y);
					res+=y;
				}
				else{
					if (res<ans){
						ans=res;
						num=step-k;
					}
					int y=str[j]-'0';
					int x=W.front();
					W.pop_front();
					W.push_back(y);
					res=res-x+y;
				}
			}
		}
	}

	step++;
	if (W.size()==k && res<ans){
		ans=res;
		num=step-k;
	}

	printf ("%d", num);

	return 0;
}