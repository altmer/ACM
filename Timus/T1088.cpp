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

int d, e, f, h, dp, ep;
int ans;

void up (int &l, int &n, int num){
	for (int i=0; i<num; ++i){
		--l;
		n=(n+1)/2;
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1088.in", "r", stdin);
	freopen ("T1088.out", "w", stdout);
#endif

	scanf ("%d%d%d%d%d%d", &d, &e, &f, &dp, &ep, &h);
	
	d=f-d;
	e=f-e;

	for (int i=f; i>d; --i)
		dp=(dp+1)/2;

	for (int i=f; i>e; --i){
		ep=(ep+1)/2;
	}

	if (d<e){
		ans+=abs(e-d);
		up (e, ep, e-d);
	}
	else if (d>e){
		ans+=abs(d-e);
		up (d, dp, d-e);
	}

	while (dp!=ep){
		ans+=2;
		up (e, ep, 1);
		up (d, dp, 1);
	}

	if (ans<=h)
		printf ("YES");
	else
		printf ("NO");


	return 0;
}