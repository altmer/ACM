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
	int next, vert, num;
};

int n, m;

int fst[100];
Node E[10000];
int cnt=0;
bool col[1000];
int ans[10000];
int deg[100];
int c=1;

void dfs(int u){
	col[u]=true;
	for (int ind=fst[u]; ind!=-1; ind=E[ind].next){
		int v = E[ind].vert;
		if (ans[E[ind].num]==0)
			ans[E[ind].num]=c++;
		if(!col[v])
			dfs(v);
	}
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	for (int i=0; i<100; ++i){
		fst[i]=-1;
	}

	scanf("%d%d", &n, &m);

	for (int i=0; i<m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		deg[a]++;
		deg[b]++;
		E[cnt].next=fst[b];
		E[cnt].vert=a;
		E[cnt].num=i;
		fst[b]=cnt++;
		E[cnt].next=fst[a];
		E[cnt].vert=b;
		E[cnt].num=i;
		fst[a]=cnt++;
	}
	int st=-1;
	int cur=1<<30;

	for (int i=0; i<n; ++i){
		if(deg[i]<cur){
			cur=deg[i];
			st=i;
		}
	}

	dfs(st);

	printf("YES\n");
	for (int i=0; i<m; ++i){
		printf("%d ", ans[i]);
	}
	printf("\n");

    return 0;
}