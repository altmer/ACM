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
char str1[100100], str2[100100];
ull hash1[100100], hash2[100100];
ull p[100100];
ull f[100100];
int n;
int ans=-1;
int len=0;

inline int charToInt(char& c){
	return c-'A'+1;
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	scanf("%d\n%s\n%s", &n, str1, str2);

	p[0]=1;
	for (int i=1; i<=n; ++i){
		p[i]=p[i-1]*31;
	}

	hash1[0]=charToInt(str1[0]);
	for (int i=1; i<n; ++i){
		hash1[i]=hash1[i-1]+p[i]*charToInt(str1[i]);
	}

	hash2[0]=charToInt(str2[0]);
	for (int i=1; i<n; ++i){
		hash2[i]=hash2[i-1]+p[i]*charToInt(str2[i]);
	}

	int L = 0;
	int R = n;

	while(L<=R){
		int mid = (R+L)/2;
		bool found = false;

		int cnt = n-mid+1;
		for (int i=0; i<cnt; ++i){
			f[i] = hash1[i+mid-1];
			if(i) f[i]-=hash1[i-1];
			f[i]*=p[n-i];
		}

		sort(f,f+cnt);

		ull cur;
		for (int i=0; i<cnt; ++i){
			cur = hash2[i+mid-1];
			if(i) cur-=hash2[i-1];
			cur*=p[n-i];
			if(binary_search(f,f+cnt,cur)){
				ans = i;
				len = mid;
				found = true;
				break;
			}
		}

		if(found){
			L=mid+1;
		}else{
			R=mid-1;
		}
	}

	for (int i=ans; i<ans+len; ++i){
		printf("%c", str2[i]);
	}
	printf("\n");

    return 0;
}