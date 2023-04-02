#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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

bool A[901][8101];
int P[901][8101], L[901][8101];
int Q[10]={0,1,4,9,16,25,36,49,64,81};
int n,v1,v2;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	A[0][0]=true;
	P[0][0]=-1;
	L[0][0]=0;

	for (int i=0; i<=900; ++i){
		for (int j=0; j<=8100; ++j){
			if(A[i][j]){
				for (int k=1; k<=9;++k){
					int ci=i+k;
					int cj=j+Q[k];
					if(ci<=900 && cj<=8100 && (!A[ci][cj] || L[i][j]+1<L[ci][cj] || (L[i][j]+1==L[ci][cj] && k<=P[ci][cj] ) ) ){
						A[ci][cj]=true;
						P[ci][cj]=k;
						L[ci][cj]=L[i][j]+1;
					}
				}
			}
		}
	}
	scanf ("%d", &n);

	for (int i=0; i<n; ++i){
		scanf ("%d%d", &v1,&v2);
		if(v1>900 || v2>8100 || !A[v1][v2] || L[v1][v2]>100){
			printf("No solution\n");
			continue;
		}
		int nv1,nv2;
		while(P[v1][v2]!=-1){
			printf("%d", P[v1][v2]);
			nv1=v1-P[v1][v2];
			nv2=v2-Q[P[v1][v2]];
			v1=nv1;
			v2=nv2;
		}
		printf("\n");
	}

	return 0;
}