#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

int N, Q;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("die.in", "r", stdin);
	freopen ("die.out", "w", stdout);
#endif

	scanf ("%d%d", &N, &Q);

	vector < vector <double> > A(N+1, vector <double> (Q+1, 0.0) );

	A[0][0]=1;

	for (int i=1; i<=N; ++i){
		for (int j=1; j<=Q; ++j){
			double cur=0;
			cur+=A[i-1][j-1];
			if (j>1)
				cur+=A[i-1][j-2];
			if (j>2)
				cur+=A[i-1][j-3];
			if (j>3)
				cur+=A[i-1][j-4];
			if (j>4)
				cur+=A[i-1][j-5];
			if (j>5)
				cur+=A[i-1][j-6];
			A[i][j]=cur/6;
		}
	}

	cout << A[N][Q];

	return 0;
}