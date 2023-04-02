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

const double minn=1.0;
const double maxx=50.0;
const double pi=3.1415926535898;
const double eps=1e-6;

struct point{
	double x, y;
	point(){
		x=y=0;
	}
	double dist(point t){
		return sqrt((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y));
	}
};

vector <point> T;
vector <vector< double> > A;
vector <double> lim;

int n;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1405.in", "r", stdin);
	freopen ("T1405.out", "w", stdout);
#endif

	scanf ("%d", &n);
	T.resize(n);
	lim.resize(n);
	A.resize(n);
	for (int i=0; i<n; ++i){
		lim[i]=1e+9;
		A[i].resize(n);
		scanf ("%lf%lf", &T[i].x, &T[i].y);
	}

	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			double r=T[i].dist(T[j]);
			A[i][j]=r;
			A[j][i]=r;
			lim[i]=min(lim[i], r);
			lim[j]=min(lim[j], r);
		}
	}

	double ans=0;
	for (int i=0; i<n; ++i){
		if (lim[i]+eps<minn)
			continue;
		if (lim[i]>maxx)
			lim[i]=maxx;
		for (int j=i+1; j<n; ++j){
			if (lim[j]+eps<minn)
				continue;
			if (lim[j]>maxx)
				lim[j]=maxx;
			double R=A[i][j];
			if (R<lim[i]+lim[j] && !(fabs(R-lim[i]-lim[j])<eps)){
				double r2=max(lim[i], lim[j]);
				if (R-r2<1.0 && !(fabs(R-r2-1.0)<eps)){
					if (R>2.0 || fabs(R-2.0)<eps)
						ans=max(ans, pi+pi*(R-1.0)*(R-1.0));
				}
				else{
					ans=max(ans, pi*r2*r2+pi*(R-r2)*(R-r2));
				}
			}
			else{
				ans=max(ans, pi*lim[i]*lim[i]+pi*lim[j]*lim[j]);
			}
		}
	}

	printf ("%.4lf", ans);

	return 0;
}