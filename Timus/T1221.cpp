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

int ntest, n;
vector <int> pre, len;
vector <vector <int> > A;

bool checkPat (int k, int l, int len)
{
	int dif=1;
	int bl=len/2+1;
	int wh=-1;
	for (int i=k; i<k+len; ++i){
		bl-=dif;
		wh+=2*dif;
		for (int j=l; j<l+bl; ++j){
			if(A[i][j]!=1)
				return false;
		}
		for (int j=l+bl; j<l+bl+wh; ++j){
			if(A[i][j]!=0)
				return false;
		}
		for (int j=l+bl+wh; j<l+len; ++j){
			if(A[i][j]!=1)
				return false;
		}
		if(!bl){
			dif=-1;
		}
	}
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1221.in", "r", stdin);
	freopen ("T1221.out", "w", stdout);
#endif

	while(true){
		scanf("%d",&n);
		if(n==0)
			break;
		int ans=0;
		A.assign(n, vector <int> (n, 0));
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				scanf ("%d", &A[i][j]);
			}
		}
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				if (A[i][j]==0 && j>0 && j<n-1 && A[i][j-1]==1 && A[i][j+1]==1){
					int shift=2;
					while(i+shift<n){
						if(A[i+shift][j-1]==1 && A[i+shift][j+1]==1){
							if(j>=shift/2 && j+shift/2<n && checkPat(i, j-shift/2, shift+1)){
								ans=max(ans, shift+1);
							}
							break;
						}
						if (A[i+shift][j-1]==1 || A[i+shift][j+1]==1){
							break;
						}
						shift+=2;
					}
				}
			}
		}
		if(ans)
			printf ("%d\n", ans);
		else
			printf ("No solution\n");
	}


	return 0;
}