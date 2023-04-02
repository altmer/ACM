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

int n;
int mod=1000000000;
vector <int> v;
vector <vector <int> > P, A;
int cur_fr;
int ans = 0;

int main (void)
{
	freopen ("tshirts.in", "r", stdin);
	freopen ("tshirts.out", "w", stdout);

	scanf ("%d\n", &n);

	v.assign(n, 0);
	P.assign(n+1, vector<int> (n+1, 0));
	A.assign(n+1, vector<int> (n+1, 0));

	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i]);
	}

	for (int len=1; len<=n; ++len){
		for (int i=0; i<=n-len; ++i){
			int j=i+len-1;
			P[i][j]=len;
			if (j>0){
				A[i][j]=(A[i][j-1]+A[i+1][j]-A[i+1][j-1])%mod;
				if(A[i][j]<0)
					A[i][j]+=mod;
			}
			if (i!=j && v[i]==v[j]){
				A[i][j]=A[i][j]+1;
				if (len>2){
					A[i][j]=(A[i][j]+P[i+1][j-1])%mod;
				}
			}
			P[i][j]=(P[i][j]+A[i][j])%mod;
		}
	}

	printf ("%d", P[0][n-1]);

	return 0;
}