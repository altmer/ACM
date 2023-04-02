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

long long A[15][100];
long long T[15][100];
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1217.in", "r", stdin);
	freopen ("T1217.out", "w", stdout);
#endif

	for (int i=0; i<=9; ++i)
		T[1][i]=A[1][i]=1;
	for (int i=2; i<=10; ++i){
		T[i][0]=A[i][0]=1;
		for (int j=1; j<=90; ++j){
			for (int k=0; k<=j; ++k){
					T[i][j]+=A[i/2][k]*A[i/2][k]*A[i-i/2][j-k]*A[i-i/2][j-k];
					A[i][j]+=A[i/2][k]*A[i-i/2][j-k];
			}
		}
	}

	scanf ("%d", &n);

	long long ans=0;
	for (int i=0; i<=90; ++i){
		ans+=T[n/2][i];
	}
	printf ("%I64d\n", ans);

	return 0;
}