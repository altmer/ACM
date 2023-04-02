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

int n, m, k;
double p, q;
vector <vector <double> > A;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1314.in", "r", stdin);
	freopen ("T1342.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	A.assign(n+1, vector<double>());
	for (int i=0; i<A.size(); ++i){
		A[i].assign(m+1, 2e+9);
		A[i][0]=0;
	}

	for (int i=1; i<=n; ++i){
		scanf ("%d%lf%lf", &k, &p, &q);
		vector <double> v(k+1, 0);
		if (k==1){
			v[k]=p;
		}
		else{
			double step=(q-p)/(static_cast<double>(k-1));
			for (int j=1; j<=k; ++j){
				v[j]=v[j-1]+p+step*(j-1);
			}
		}
		for (int j=1; j<=m; ++j){
			for (int l=0; l<=min(j, static_cast<int>(v.size())-1); ++l){
				A[i][j]=min(A[i-1][j-l]+v[l], A[i][j]);
			}
		}
	}
	if (A[n][m]==2e+9){
		for (int i=m; i>=1; --i){
			if (A[n][i]<2e+9){
				printf ("Maximum possible amount: %d\n", i);
				printf ("Minimum possible cost: %.2lf", A[n][i]);
				return 0;
			}
		}
	}
	else{
		printf ("Minimum possible cost: %.2lf", A[n][m]);
	}

	return 0;
}