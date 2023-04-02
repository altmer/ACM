#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct vert{
	int step, lev, num;
	bool operator < (vert t){
		if (lev==t.lev)
			return step<t.step;
		return lev<t.lev;
	}
};

struct coord{
	int x, y;
};

const int bor=-1000;
int n;
vector <vector <int> > A;
vector <vert> dist;
vector <coord> ans;
queue <int> q;

void bfs (int u){
	q.push(u);
	int	step=1;
	dist[u].lev=1;
	dist[u].step=1;
	while (!q.empty()){
		u=q.front();
		q.pop();
		dist[u].num=u;
		for (int i=0; i<A[u].size(); ++i){
			int v=A[u][i];
			if (dist[v].lev==0){
				step++;
				dist[v].step=step;
				dist[v].lev=dist[u].lev+1;
				q.push(v);
			}
		}
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1358.in", "r", stdin);
	freopen ("T1358.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize(n);
	ans.resize(n);
	dist.resize(n);

	for (int i=0; i<n-1; ++i){
		int u, v;
		scanf ("%d%d", &u, &v);
		A[u-1].push_back(v-1);
		A[v-1].push_back(u-1);
	}

	bfs(0);	

	sort (dist.begin(), dist.end());

	int x=bor;
	int y=bor;
	ans[dist[0].num].x=x;
	ans[dist[0].num].y=y;
	for (int i=1; i<dist.size(); ++i){
		if (dist[i].lev!=dist[i-1].lev){
			x=bor;
			y+=2;
		}
		ans[dist[i].num].x=x;
		ans[dist[i].num].y=y;
		x+=2;
	}

	for (int i=0; i<ans.size(); ++i){
		printf ("%d %d\n", ans[i].x, ans[i].y);
	}

	
	return 0;
}