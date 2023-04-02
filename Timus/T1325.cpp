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
	int x, y;
};

int m, n;
int lim;
vert st, fin;
vector <vector <int> > G, C, D;
vector <vector <bool> > K;
queue <vert> q;
deque <vert> q1, q2;
int dx[8]={1, -1, 0,  0, 1, -1,  1, -1};
int dy[8]={0,  0, 1, -1, 1, -1, -1,  1};

void bfs1 (vert u){
	vert v;
	q1.push_back(u);
	K[u.x][u.y]=true;
	while ( !q1.empty() || !q2.empty()){
		if (q1.empty()){
			q2.swap(q1);
		}

		u=q1.front();
		q1.pop_front();

		for (int i=0; i<8; ++i){
			v.x=u.x+dx[i];
			v.y=u.y+dy[i];
			if (G[v.x][v.y] && !K[v.x][v.y]){
				K[v.x][v.y]=true;
				
				if (G[v.x][v.y]==G[u.x][u.y]){
					C[v.x][v.y]=C[u.x][u.y];
					q1.push_back(v);
				}
				else{
					C[v.x][v.y]=C[u.x][u.y]+1;
					q2.push_back(v);
				}
			}
		}
	}
}

void bfs2 (vert u){
	vert v;
	int dist;
	q.push(u);
	D[u.x][u.y]=1;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<8; ++i){
			v.x=u.x+dx[i];
			v.y=u.y+dy[i];
			dist=D[u.x][u.y]+1;
			if (G[v.x][v.y] && C[v.x][v.y]<=C[u.x][u.y] && (!D[v.x][v.y] || D[v.x][v.y]>dist) ){
					D[v.x][v.y]=dist;
					q.push(v);
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1325.in", "r", stdin);
	freopen ("T1325.out", "w", stdout);
#endif

	scanf ("%d%d\n", &m, &n);
	G.resize(m+2);
	C.resize(m+2);
	D.resize(m+2);
	K.resize(m+2);
	for (int i=0; i<m+2; ++i){
		G[i].resize(n+2);
		K[i].resize(n+2);
		C[i].resize(n+2);
		D[i].resize(n+2);
	}
	
	scanf ("%d%d\n%d%d\n", &st.x, &st.y, &fin.x, &fin.y);

	for (int i=1; i<=m; ++i){
		for (int j=1; j<=n; ++j){
			scanf ("%c", &G[i][j]);
			G[i][j]-='0';
		}
		scanf ("\n");
	}
	
	bfs1 (st);

	bfs2(fin);

	printf ("%d %d", D[st.x][st.y], C[fin.x][fin.y]);

	return 0;
}