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

int h,w,n;
int num, nt=1,quer;
int mas[1000000];

int build(int u){
	if(u>=nt)
		return mas[u];
	return mas[u]=max(build(2*u),build(2*u+1));
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("billboard.in", "r", stdin);
	freopen ("billboard.out", "w", stdout);
#endif

	scanf ("%d%d%d", &h, &w, &n);
	num=min(h,n);

	while(nt<num)
		nt*=2;

	for (int i=nt; i<nt+num; ++i){
		mas[i]=w;
	}
	build(1);

	for (int i=0; i<n; ++i){
		int j;
		scanf("%d", &quer);
		if(mas[1]<quer){
			printf("-1\n");
		}
		else{
			j=1;
			while(j<nt){
				j*=2;
				if(mas[j]<quer)
					j++;
			}
			if(mas[j]<quer)
				j++;
			printf("%d\n", j-nt+1);
			mas[j]-=quer;
			j/=2;
			while(j){
				mas[j]=max(mas[j*2],mas[j*2+1]);
				j/=2;
			}
		}
	}

	return 0;
}