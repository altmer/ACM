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

int n, m;
char T[5010], S[10100], patt[5010];
int F[5010];

void prekmp(){
	F[0]=F[1]=0;
	for (int i=2; i<=n; ++i){
		int j=F[i-1];
		for (;;){
			if(patt[i-1]==patt[j]){
				F[i]=j+1;
				break;
			}
			if(j==0){
				F[i]=0;
				break;
			}
			j=F[j];
		}
	}
}

bool kmp(){
	prekmp();
	int i=0, j=0;
	for (;;){
		if(j==m){
			return false;
		}
		if(S[j]==patt[i]){
			++i;
			++j;
			if(i==n){
				return true;
			}
		}
		else if(i>0){
			i=F[i];
		}
		else
			++j;
	}
}

void makepat(char* str){
	for (int i=0; i<n; ++i){
		patt[i] = str[i]==T[i] ? '0' : '1';
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf("%s%s", T, S);
	n=strlen(T);
	m=2*n;
	for (int i=n; i<m; ++i){
		S[i]=S[i-n];
	}
	S[m]=0;

	for (int i=0; i<n; ++i){
		makepat(S+i);
		if(kmp()){
			printf("Yes");
			return 0;
		}
	}
	printf("No");

	return 0;
}