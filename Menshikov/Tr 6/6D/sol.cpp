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

class Rect{
public:
	int xmin, ymin, xmax, ymax;
	Rect() : xmin(-1), ymin(-1), xmax(-1), ymax(-1) {}
	Rect (int x1, int y1, int x2, int y2) : xmin(min(x1, x2)), ymin(min(y1,y2)),xmax(max(x1, x2)),ymax(max(y1,y2)) {}
	bool intersect (int x1, int y1){
		return x1>=xmin && x1<xmax && y1>=ymin && y1<ymax;
	}
};

int n;
long long ans;
set <int> x, y;
set <int>::iterator itx, ity;
vector <Rect> v;

set <int>::iterator next (const set <int>::iterator& it){
	set <int>::iterator tmp = it;
	return ++tmp;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf ("%d", &n);
	v.reserve(n);

	for (int i=0;i<n; ++i){
		int a, b, c, d;
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		v.push_back(Rect(a, b, c,d));
		x.insert(a);
		x.insert(c);
		y.insert(b);
		y.insert(d);
	}

	itx = x.begin();
	int i=0;
	while (i<x.size()-1){
		ity = y.begin();
		int j=0;
		while (j < y.size()-1){
			for (int k=0; k<v.size(); ++k){
				if (v[k].intersect(*itx, *ity)){
					ans += (*(next(itx))-*itx)*(*(next(ity))-*ity);
					break;
				}
			}
			++j;
			++ity;
		}
		++i;
		++itx;
	}

	cout << ans << endl;

	return 0;
}