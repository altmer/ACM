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
#include <limits>
#include <set>
using namespace std;

class edge{
public:
	int dest, len;
	edge (int d=-1, int l=-1) : dest(d), len(l) {}
};

int INF=numeric_limits<int>::max();
vector <vector <edge> > A;
//vector <int> dist, num;
vector <vector <int> > num;
vector <bool> col;
int st, end, n, m;
int c_ans=-1, c_num=-1;

void bfs (int u){

	queue <int> q;
	q.push(u);

	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i){
			int v=A[u][i].dest;
			if (num[u][A[u][i].len]!=INF && num[u][A[u][i].len]+1 < num[v][A[u][i].len]){
				num[v][A[u][i].len]=num[u][A[u][i].len]+1;
				q.push(v);
			}
		}
	}
}

int main (void)
{
	freopen ("teleportation.in", "r", stdin);
	freopen ("teleportation.out", "w", stdout);

	scanf ("%d%d%d%d", &n, &m, &st, &end);
	st--; end--;
	A.resize(n);
	num.assign(n, 0);
	col.assign(n, false);
	num.assign(n, vector<int>(1020, numeric_limits<int>::max()));

	for (int i=0; i<m; ++i){
		int u, v, l;
		scanf ("%d%d%d", &u, &v, &l);
		u--; v--;
		A[u].push_back(edge(v, l));
		A[v].push_back(edge(u, l));
	}

	col[st]=true;
	num[st]=vector<int>(1020, 1);
	bfs(st);

	for (int i=num[end].size()-1; i>=0; --i){
		if (num[end][i]!=INF){
			printf ("%d %d", num[end][i], i);
			return 0;
		}
	}

	printf ("0 0");

	
	return 0;
}