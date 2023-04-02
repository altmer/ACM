#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

int res[10000];
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf ("%d", &n);

	if (n<58){
		res[0]=0;
		for (int i=1; i<=n; ++i){
			bool dost[1000];
			memset (dost,0,sizeof(dost));
			for (int j=1; j<=i; ++j){
				int lres=max(0,j-2);
				int rres=max(0, i-j-1);
				dost[res[lres]^res[rres]]=true;
			}
			for (int j=0; j<=10000; ++j){
				if (!dost[j]){
					res[i]=j;
					break;
				}
			}
		}
		cout << ((res[n]) ? "White" : "Black") << endl;
	}
	else{
		n-=58;
		n%=34;
		if (n==0 || n==4 || n==14 || n==18 || n==30){
			cout << "Black" << endl;
		}
		else{
			cout << "White" << endl;
		}
	}
/*	for (int i=1; i<=10000; ++i){
		cout << ((res[i]) ? "White" : "Black") << endl;
	}
*/

/*	for (int i=0; i<=10000; ++i){
		if (!res[i])
			cout << i << endl;
	}
*/
/*
	int prev=0;
	for (int i=1; i<=10000; ++i){
		if (!res[i]){
			cout << i-prev << endl;
			prev=i;
		}
	}
*/

	return 0;
}