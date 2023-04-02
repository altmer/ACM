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

struct circ{
	double x, y, r;
	bool inside (double q, double w){
		return sqrt((x-q)*(x-q)+(y-w)*(y-w))<=r;
	}
};

vector <circ> v;
int num, n;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1061.in", "r", stdin);
	freopen ("T1061.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%lf%lf%lf", &v[i].x, &v[i].y, &v[i].r);
		v[i].x*=1000;
		v[i].y*=1000;
		v[i].r*=1000;
	}

	for (double x=0; x<=1000; ++x){
		for (double y=0; y<=1000; ++y){
			for (int i=0; i<v.size(); ++i){
				if (v[i].inside(x, y)){
					++num;
					break;
				}
			}
		}
	}

	double ans=(double(num)/(1000000.0))*100.0;
	printf ("%.0lf", ans);

	return 0;
}