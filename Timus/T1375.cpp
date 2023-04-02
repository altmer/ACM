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

int k, p;
vector <pair <int, int> > v;
vector <bool> q;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1375.in", "r", stdin);
	freopen ("T1375.out", "w", stdout);
#endif

	v.reserve(1000000);
	q.resize(1000000);

	cin >> k >> p;

	for (long long x=0; x<=p/2; ++x){
		for (long long y=0; y<=p/2; ++y){
			long long t1=x;
			t1*=x;
			long long t2=y;
			t2*=y;
			t1+=t2;
			if (t1%p==k){
				cout << x << " " << y;
				return 0;
			}
		}
	}

	return 0;
}