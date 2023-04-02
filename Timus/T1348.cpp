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

struct vect{
	double x, y;
	vect operator - (vect b){
		vect t;
		t.x=x-b.x;
		t.y=y-b.y;
		return t;
	}
	double operator * (vect b){
		return x*b.x+y*b.y;
	}
	double length (void){
		return sqrt(x*x+y*y);
	}
};

double dist_to_segm (vect P, vect A, vect B){
	vect v=A-B;
	vect w=P-B;
	double c1=v*w;
	if (c1<=0)
		return (B-P).length();
	double c2=v*v;
	if (c2<=c1)
		return (A-P).length();
	double b=c1/c2;
	vect Pb;
	Pb.x=B.x+b*v.x;
	Pb.y=B.y+b*v.y;
	return (Pb-P).length();
}

vect A, B, P;
double L;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1348.in", "r", stdin);
	freopen ("T1348.out", "w", stdout);
#endif

	scanf ("%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &P.x, &P.y, &L);

	double dist=dist_to_segm(P, A, B);
	if (L>dist)
		dist=L;
	printf ("%.2lf\n", fabs(L-dist));
	double d1=(A-P).length();
	double d2=(B-P).length();
	d1=max(d1, d2);
	if (L>d1)
		d1=L;
	printf ("%.2lf", fabs(d1-L));


	return 0;
}