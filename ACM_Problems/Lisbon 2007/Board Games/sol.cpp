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
using namespace std;

struct edge{
	int dest, len;
	edge():dest(-1),len(0){}
	edge(int x, int y):dest(x),len(y){}
};

int n, st, end,m;
vector <int> dist, enc;
vector <vector <edge> > A;
int ntest;
bool bad=false;

void bfs (int u)
{
	queue <int> q;
	q.push(u);
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i){
			if (dist[u]+A[u][i].len<dist[A[u][i].dest]){
				dist[A[u][i].dest]=dist[u]+A[u][i].len;
				q.push(A[u][i].dest);
				enc[A[u][i].dest]++;
				if (enc[A[u][i].dest]>n){
					bad=true;
					return ;
				}
			}
		}
	}
}

int main (void)
{
	//freopen ("T1109.in", "r", stdin);
	//freopen ("T1109.out", "w", stdout);

	scanf ("%d", &ntest);
	for (int test=0; test<ntest; ++test){
		bad=false;
		scanf ("%d%d%d", &n, &st, &end);
		A.assign(n,vector<edge>());
		dist.assign(n, 1e+9);
		enc.assign(n, 0);
		dist[st]=0;
		scanf ("%d", &m);
		for (int i=0; i<m; ++i){
			int q,b,c;
			scanf ("%d%d%d", &q, &b, &c);
			A[q].push_back(edge(b,c));
		}
		bfs(st);
		if (bad || dist[end]==1e9)
			printf ("infinity\n");
		else
			printf ("%d\n", dist[end]);
		if (test!=ntest-1)
			printf ("\n");
	}

	return 0;
}