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

class dot{
public:
	double x, y;
	dot (double a=-1, double b=-1) : x(a), y(b) {}
};

pair<double, double> center(dot A, dot B, dot C)
{
	double A1=A.x-B.x;
	double B1=A.y-B.y;
	double C1=A1*(A.x+B.x)/2.0+B1*(A.y+B.y)/2.0;
	double A2=C.x-A.x;
	double B2=C.y-A.y;
	double C2=A2*(C.x+A.x)/2.0+B2*(C.y+A.y)/2.0;
	double det=-B1*A2+B2*A1;
	if (fabs(det)>1e-6){
		return make_pair((-B1*C2+B2*C1)/det,(-A2*C1+A1*C2)/det);
	}
	return make_pair(-1, -1);
}

int n;
dot A, B, C;

int main (void)
{
	freopen ("army.in", "r", stdin);
	freopen ("army.out", "w", stdout);

	scanf ("%d", &n);

	scanf ("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);

	printf ("%.4lf %.4lf", center(A,B,C).first, center(A,B,C).second);

	return 0;
}