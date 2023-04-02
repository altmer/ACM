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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

const double eps=1e-9;

class point{
public:
	double x, y;
	point (double a=0, double b=0) : x(a), y(b) {}
	point operator - (const point& T)const {
		return point (x-T.x, y-T.y);
	}
	double operator * (const point& T)const{// scalar prod
		return x*T.x+y*T.y;
	}
	double operator ^ (const point& T)const{// vector prod
		return x*T.y-y*T.x;
	}
	double dist (point& T){
		return sqrt((x-T.x)*(x-T.x)+(y-T.y)*(y-T.y));
	}
};

vector <point> pol;

bool intersect (point& A, point& B, point& C, point& D)
{
	double A1=B.y-A.y;
	double B1=A.x-B.x;
	double C1=A1*A.x+B1*A.y;
	double A2=D.y-C.y;
	double B2=C.x-D.x;
	double C2=A2*C.x+B2*C.y;
	double det = A1*B2-A2*B1;
	if(fabs(det)<eps){
		return false;
	}
	else{
		double x=(B2*C1-B1*C2)/det;
		double y=(A1*C2-C1*A2)/det;
		return x>=min(A.x, B.x) && x<=max(A.x,B.x) && y>=min(A.y,B.y) && y<=max(A.y,B.y) && 
			x>=min(C.x, D.x) && x<=max(C.x, D.x) && y>=min(C.y, D.y) && y<=max(C.y, D.y); 
	}
	return false;
}

bool isInPoly(point& P)
{
	pair <int, int> ans;
	for (int test=0; test<100; ++test){
		point P2(rand()+2001, rand()+2001);
		int cnt=0;
		for (int i=1; i<pol.size(); ++i){
			if (intersect(P, P2, pol[i-1],pol[i])){
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

double distToLine (point& A, point& B, point& C){
	double dist=((B-A)^(C-B))/(A.dist(B));
	if ((B-A)*(C-B)>0)
		return B.dist(C);
	if((A-B)*(C-A)>0)
		return A.dist(C);
	return fabs(dist);
}

int n;
point O;
double ans=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1215.in", "r", stdin);
	freopen ("T1215.out", "w", stdout);
#endif

	scanf ("%lf%lf%d", &O.x, &O.y, &n);
	pol.resize(n+1);
	for (int i=0; i<n; ++i){
		scanf ("%lf%lf", &pol[i].x, &pol[i].y);
	}
	pol[n]=pol[0];
	if(!isInPoly(O)){
		ans=numeric_limits<double>::max();
		for (int i=1; i<=n; ++i){
			ans=min(ans, distToLine(pol[i-1],pol[i], O));
		}
	}

	printf ("%.3lf\n", ans*2.0);

	return 0;
}