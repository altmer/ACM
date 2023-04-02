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

int g, w, b, p;
int n, curmax=1<<30, ans=-1;
int arr[100100];

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	scanf("%d%d%d%d%d", &g, &w, &b, &p, &n);
	for (int i=0; i<n; ++i){
		scanf("%d", &arr[i]);
	}

	sort(arr,arr+n);

	for (int i=0; i+b<=g; ++i){
		int num = (-(lower_bound(arr, arr+n,i-w+1)-arr) + (lower_bound(arr, arr+n,i+b)-arr));
		int num2 = (-(lower_bound(arr, arr+n,i+p)-arr) + (lower_bound(arr, arr+n,i+b-p-w+1)-arr));
		//int num = (-(lower_bound(arr, arr+n,i-w+1)-arr) + (lower_bound(arr, arr+n,i+p)-arr)) + (-(lower_bound(arr, arr+n,i+b-p-w+1)-arr) + (lower_bound(arr, arr+n,i+b)-arr));
		if(num2>=0)
			num-=num2;
		if(num<curmax){
			curmax=num;
			ans=i;
		}
	}

	printf("%d\n", ans);

    return 0;
}