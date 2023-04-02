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

int c[300][300], f[300][300];
int S=0, T;
int n;
int e[300], h[300], maxh[300];
int sz=0;

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	scanf("%d", &n);
	T=2*n+1;
	for (int i=1;i<=n; ++i){
		scanf("%d", &c[S][i]);
	}

	for (int i=1; i<=n; ++i){
		scanf("%d", &c[n+i][T]);
	}

	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			c[i][n+j]=100;
		}
	}

	h[S]=2*n+1;
	for (int i=1; i<=n; ++i){
		f[S][i]=c[S][i];
		f[i][S]=-c[S][i];
		e[i]=c[S][i];
	}

	for(;;){
		if(!sz){
			for (int i=1; i<=2*n; ++i){
				if(e[i]>0){
					if(sz && h[i]>h[maxh[0]]) sz=0;
					maxh[sz++]=i;
				}
			}
		}
		if(!sz) break;
		while(sz){
			int i=maxh[sz-1];
			bool pushed = false;
			for (int j=0; j<=2*n+1 && e[i]; ++j){
				if(c[i][j]-f[i][j]>0 && h[i]==h[j]+1){
					pushed=true;
					int addf = min (c[i][j]-f[i][j], e[i]);
					f[i][j] += addf,  f[j][i] -= addf;
					e[i] -= addf,  e[j] += addf;
					if (e[i] == 0)  --sz;
				}
			}
			if (!pushed) {
				h[i] = 1000*1000*1000;
				for (int j=0; j<=2*n+1; ++j)
					if (c[i][j]-f[i][j] > 0 && h[j]+1 < h[i])
						h[i] = h[j]+1;
				if (h[i] > h[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}	
	}

	for (int i=1; i<=n; ++i){
		if(f[S][i]!=c[S][i]){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			printf("%d ", f[i][n+j]);
		}
		printf("\n");
	}

    return 0;
}