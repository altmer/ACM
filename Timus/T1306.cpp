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
#include <list>
#include <set>
using namespace std;

priority_queue <int> q;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1306.in", "r", stdin);
	freopen ("T1306.out", "w", stdout);
#endif

	scanf ("%d", &n);
	int lim = n/2 + 1;

	for (int i=0; i<n; ++i){
		int a;
		scanf ("%d", &a);
		q.push(a);
		if (q.size()>lim){
			q.pop();
		}		
	}

	int f=q.top();
	q.pop();
	int s=q.top();

	if (n%2){
		printf ("%d.0\n", f);
	}
	else{
		printf ("%.1lf\n", (double(f)+double(s))/2.0);
	}

	return 0;
}