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
#include <set>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int INF = 1000000000;
int mas[10010];
int len=0;
int n,m;

int posit (int x, int l, int r)
{
	if(l>=r)
		return l;
	int mid=(l+r)/2;
	if(mas[mid]<=x){
		return posit(x,mid+1, r);
	}
	else
		return posit(x, l, mid);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1439.in", "r", stdin);
	freopen ("T1439.out", "w", stdout);
#endif

	mas[len]=INF;
	
	scanf ("%d%d\n", &n, &m);

	for (int i=0; i<m; ++i){
		char ch;
		int t;
		scanf ("%c %d\n", &ch, &t);
		if(ch=='L'){
			printf ("%d\n", t+posit(t, 0, len));
		}
		else{
			int p=posit(t, 0, len);
			for (int i=p; i<len; ++i)
				mas[i]--;
			for (int i=len; i>p; --i)
				mas[i]=mas[i-1];
			mas[p]=t;
			mas[++len]=INF;
		}
	}

	return 0;
}