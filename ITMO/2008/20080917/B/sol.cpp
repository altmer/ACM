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
#include <limits>
#include <set>
using namespace std;

struct point{
	double x, y;
	point (double _X=0, double _Y=0){
		x=_X; y=_Y;
	}
	point operator + (const point &t){
		point res;
		res.x=x+t.x;
		res.y=y+t.y;
		return res;
	}
	point operator - (const point &t){
		point res;
		res.x=x-t.x;
		res.y=y-t.y;
		return res;
	}
	const double operator ^ (const point &t){
		return x*t.y-y*t.x;
	}
	const double operator * (const point &t){
		return x*t.x+y*t.y;
	}
	bool operator < (const point& t) const{
		if (x==t.x)
			return y<t.y;
		return x<t.x;
	}
};

vector <point> v;

bool intersect (const point &A, const point &B, const point &C, const point &D){
	double A1=B.y-A.y, B1=A.x-B.x, C1=A.x*A1+A.y*B1;
	double A2=D.y-C.y, B2=C.x-D.x, C2=C.x*A2+C.y*B2;
	double det=A1*B2-A2*B1;
	if (det==0){
		return false;
	}
	else{
		double x=(B2*C1-B1*C2)/det;
		double y=(A1*C2-A2*C1)/det;
		return x>=A.x && x<=B.x && y>=A.y && y<=B.y && x>=min(C.x, D.x) && x<=max(C.x, D.x) && y>=min(C.y, D.y) && y<=max(C.y, D.y);
	}		
}
bool isInPoly(point& P){
	// input data
	pair <int, int> ans;
	for (int test=0; test<10; ++test){
		point P2(rand()+1001, rand()+1001);
		int cnt=0;
		for (int i=1; i<v.size(); ++i){
			if (intersect(P, P2, v[i-1],v[i])){
				++cnt;
			}
		}
		if (cnt%2==0){
			ans.first++;// outer
		}
		else{
			ans.second++;// inter
		}
	}
	if (ans.first>ans.second)
		return false;
	else
		return true;
}

int n, h;
point u;
bool A[210][210];

int main (void)
{
	freopen ("trees.in", "r", stdin);
	freopen ("trees.out", "w", stdout);

	cin >> n >> h >> u.x >> u.y;
	v.resize(n);

	for (int i=0; i<n; ++i){
		cin >> v[i].x >> v[i].y;
	}
	v.push_back(v.front());
	vector <point> ans;

	point w;
	for (w.x=0; w.x<=100; ++w.x){
		for (w.y=0; w.y<=100; ++w.y){
			if (int(abs(w.x-u.x))%h==0 && int(abs(w.y-u.y))%h==0 && isInPoly(w)){
				ans.push_back(w);
			}
		}
	}

	sort(ans.begin(), ans.end());

	printf ("%d\n", ans.size());
	int st=0;
	while (st<ans.size()){
		int end=st+1;
		while (end<ans.size() && ans[end].x==ans[st].x)
			++end;
		printf ("%d ", int(ans[st].x));
		for (int i=st; i<end; ++i){
			printf ("%d ", int(ans[i].y));
		}
		printf ("\n");
		st=end;
	}

	return 0;
}