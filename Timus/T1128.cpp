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

struct Node{
	int next, vert;
};

int fst[10000];
Node E[100000];
int cnt = 0;

int n;

int gr[10000];
int num[2];

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	for (int i=0; i<10000; ++i){
		fst[i]=-1;
	}

	scanf("%d", &n);

	for (int i=0; i<n; ++i){
		int t;
		scanf("%d", &t);
		for (int j=0; j<t; ++j){
			int b;
			scanf("%d", &b);
			b--;
			E[cnt].vert=b;
			E[cnt].next=fst[i];
			fst[i]=cnt++;
		}
	}

	num[0]=n;

	bool fin=false;
	while(!fin){
		fin=true;
		for (int i=0; i<n; ++i){
			int en=0;
			bool bad=false;
			for (int ind=fst[i]; ind!=-1; ind=E[ind].next){
				if(gr[i]==gr[E[ind].vert]){
					++en;
					if(en>1){
						bad=true;
						break;
					}
				}
			}
			if(bad){
				num[gr[i]]--;
				num[gr[i]^1]++;
				gr[i]=1^gr[i];
				fin=false;
			}
		}
	}

	if(num[0]<num[1]){
		printf("%d\n", num[0]);
		for (int i=0; i<n; ++i){
			if(gr[i]==0){
				printf("%d ", i+1);
			}
		}
	}else if (num[0]>num[1]){
		printf("%d\n", num[1]);
		for (int i=0; i<n; ++i){
			if(gr[i]==1){
				printf("%d ", i+1);
			}
		}
	}else{
		if(gr[0]==0){
			printf("%d\n", num[0]);
			for (int i=0; i<n; ++i){
				if(gr[i]==0){
					printf("%d ", i+1);
				}
			}
		}else{
			printf("%d\n", num[1]);
			for (int i=0; i<n; ++i){
				if(gr[i]==1){
					printf("%d ", i+1);
				}
			}
		}
	}

    return 0;
}