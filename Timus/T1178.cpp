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

struct point{
	int x, y, n;
	bool operator < (point t){
		if (x==t.x)
			return y<t.y;
		return x<t.x;
	}
};

vector <point> v;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1178.in", "r", stdin);
	freopen ("T1178.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%d%d", &v[i].x, &v[i].y);
		v[i].n=i+1;
	}

	sort (v.begin(), v.end());

	for (int i=0; i<n; i+=2){
		printf ("%d %d\n", v[i].n, v[i+1].n);
	}

	return 0;
}