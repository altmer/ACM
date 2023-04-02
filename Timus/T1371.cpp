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
#include <map>
#include <set>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

class edge{
public:
	int dest, len;
	long long num;
	edge (int a=-1, int b=-1) : dest(a), len(b), num(-1) {}
};

int n;
vector <vector <edge> > A;
long long ans=0;
long long add;
vector <int> ch;
vector <bool> col;

int count(int u){
	col[u]=true;

	for (int i=0; i<A[u].size(); ++i){
		int v=A[u][i].dest;
		if (!col[v]){
			ch[u]+=count(v);
			A[u][i].num=0;
		}
	}

	for (int i=0; i<A[u].size(); ++i){
		if (A[u][i].num==0){
			add = ch[A[u][i].dest]+1;
			add*=(n-add);
			add*=A[u][i].len;
			add*=2;
			ans+=add;
		}
	}
	return ch[u]+1;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1371.in", "r", stdin);
	freopen ("T1371.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize(n);
	ch.resize(n);
	col.assign(n, false);

	for (int i=0; i<n-1; ++i){
		int u, v, c;
		scanf ("%d%d%d", &u, &v, &c);
		u--; v--;
		A[u].push_back(edge(v, c));
		A[v].push_back(edge(u, c));
	}

	count(0);

	printf ("%.4lf", double(ans)/(double(n)*double(n-1)));

	return 0;
}