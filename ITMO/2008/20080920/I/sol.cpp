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
using namespace std;

const int INF = 1000000000;
int n,m;
int mas[50100];
int a, b;
int t;

int main (void)
{
	freopen ("i.in", "r", stdin);
	//freopen ("i.out", "w", stdout);

	mas[1]=0;
	
	scanf ("%d%d", &n, &m);
	for (int i=2; i<=n; ++i){
		mas[i]=INF;
	}

	for (int i=0; i<m; ++i){
		scanf ("%d%d", &a, &b);
		t=mas[a]+1;
		while (mas[b]>t){
			mas[b--]=t;
		}
	}

	printf ("%d\n", mas[n]);

	return 0;
}