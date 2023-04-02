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

typedef unsigned long long ull;

struct str{
	ull h;
	int x,y;
	bool operator <(const str& T)const {
		return h<T.h;
	}
};

ull p[1001000];
char s[510][510];
ull hash[510][510];
int n, m;
str f[1001000];
int cnt=0;
int curans=0, curx1, cury1, curx2,cury2;

inline int charToInt(char& ch){
	return ch-'a'+1;
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	scanf("%d%d\n", &n, &m);

	for (int i=0; i<n; ++i){
		scanf("%s", s[i]);
	}

	p[0] = 1;
	for (int i=1; i<=n*m; ++i){
		p[i]=p[i-1]*31L;
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			hash[i][j] = p[i*m+j]*charToInt(s[i][j]);
			if(i) hash[i][j] += hash[i-1][j];
			if(j) hash[i][j] += hash[i][j-1];
			if(i&&j) hash[i][j] -= hash[i-1][j-1];
		}
	}

	int L=1;
	int R = min(n,m);

	while(L<=R){
		int k = (L+R)/2;
		cnt=0;

		for (int i=0; i<n-k+1; ++i){
			for (int j=0; j<m-k+1; ++j){
				f[cnt].x=i;
				f[cnt].y=j;

				f[cnt].h=hash[i+k-1][j+k-1];

				if(i) f[cnt].h -= hash[i-1][j+k-1];
				if(j) f[cnt].h -= hash[i+k-1][j-1];
				if(i&&j) f[cnt].h+=hash[i-1][j-1];

				f[cnt].h*=p[n*m-i*m-j];

				cnt++;
			}
		}

		sort(f,f+cnt);

		bool found = false;
		for (int i=1; i<cnt; ++i){
			if(f[i].h==f[i-1].h){
				found=true;
				curans=k;
				curx1=f[i].x+1;
				cury1=f[i].y+1;
				curx2=f[i-1].x+1;
				cury2=f[i-1].y+1;
				break;
			}
		}
		if(found) L=k+1;
		else R=k-1;
	}

	printf("%d\n", curans);
	if(curans){
		printf("%d %d\n%d %d\n", curx1, cury1, curx2,cury2);
	}

    return 0;
}