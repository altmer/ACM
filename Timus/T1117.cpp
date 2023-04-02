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

int a, b;
vector <int> v;

int f (int x)
{
	if (x==1)
		return 0;

	int lbit=1;
	int tmp=x;
	int i=0;
	while (tmp>1){
		++i;
		tmp>>=1;
		lbit<<=1;
	}
	if (lbit==x)
		return v[i];

	return v[i]+max(0,i-1)+f(x-lbit);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1117.in", "r", stdin);
	freopen ("T1117.out", "w", stdout);
#endif

	long long k=4;
	v.push_back(0);
	v.push_back(0);
	while (k<2000000000){
		v.push_back(2*v.back()+int(v.size())-1);
		k<<=1;
	}

	scanf ("%d%d", &a, &b);

	printf ("%d", abs(f(a)-f(b)));

	return 0;
}