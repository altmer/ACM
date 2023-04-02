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

struct city{
	int tram, num;
	city():tram(0),num(-1){}
	bool operator < (const city& t)const{
		if (tram==t.tram)
			return num<t.num;
		return tram<t.tram;
	}
};

int n, q;
int l, r, m;
vector <city> v;

bool BS (int l, int r, int x, int fl, int fr)
{
	if (l>r)
		return false;
	int mid=(l+r)/2;
	if (v[mid].tram<x){
		return BS(mid+1, r, x, fl, fr);
	}
	else if (v[mid].tram>x){
		return BS(l, mid-1, x, fl, fr);
	}
	else{
		if (v[mid].num>=fl && v[mid].num<=fr){
			return true;
		}
		else if (v[mid].num<fl){
			return BS(mid+1, r, x, fl, fr);
		}
		else{
			return BS(l, mid-1, x, fl, fr);
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1613.in", "r", stdin);
	freopen ("T1613.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i].tram);
		v[i].num=i+1;
	}

	sort (v.begin(), v.end());

	scanf ("%d", &q);
	for (int i=0; i<q; ++i){
		scanf ("%d%d%d", &l, &r, &m);
		printf ("%d", static_cast<int>(BS(0, n-1, m, l, r)));
	}

	return 0;
}