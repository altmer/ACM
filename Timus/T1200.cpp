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

double a, b;
int h1, h2;
double ans;
int k;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1200.in", "r", stdin);
	freopen ("T1200.out", "w", stdout);
#endif

	scanf ("%lf%lf%d", &a, &b, &k);

	for (int i=0; i<=k; ++i){
		double t=fabs(b/2;
		int j1=ceil(t);
		if (j1>k-i)
			j1=k-i;
		double sum1=a*i+j1*b-i*i-j1*j1;
		int j2=floor(t);
		if (j2>k-i)
			j2=k-i;
		double sum2=a*i+j2*b-i*i-j2*j2;
		if (sum2>ans){
			ans=sum2;
			h1=i;
			h2=j2;
		}
		if (sum1>ans){
			ans=sum1;
			h1=i;
			h2=j1;
		}
	}

	printf ("%.2lf\n%d %d", ans, h1, h2);


	return 0;
}