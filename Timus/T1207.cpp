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

struct dot{
	double x, y, an;
	int num;
	void angle (dot p, dot t){
		an=(p.x*t.y-p.y*t.x)/(sqrt(p.x*p.x+p.y*p.y)*sqrt(t.x*t.x+t.y*t.y));
	}
	bool operator < (dot t){
		return an<t.an;
	}
	bool operator == (dot t){
		return x==t.x && y==t.y;
	}
	dot operator - (dot t){
		dot p;
		p.x=x-t.x;
		p.y=y-t.y;
		return p;
	}
};

int n;
dot A, vect;
vector <dot> v;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1207.in", "r", stdin);
	freopen ("T1207.out", "w", stdout);
#endif
	
	A.x=1e+9+1;

	scanf ("%d", &n);
	v.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%lf%lf", &v[i].x, &v[i].y);
		v[i].num=i+1;
		if (v[i].x<A.x)
			A=v[i];
		else if (v[i].x==A.x && v[i].y<A.y)
			A=v[i];
	}

	vect.x=1.0;

	for (int i=0; i<n; ++i){
		if (v[i]==A)
			v[i].an=16.0;
		else{
			v[i].angle(vect, v[i]-A);
		}
	}

	sort (v.begin(), v.end());

	printf ("%d %d", A.num, v[n/2-1].num);

	return 0;
}