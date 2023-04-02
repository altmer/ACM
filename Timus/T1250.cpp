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

struct coord{
	int x, y;
};
const int sea=1;
const int bord=0;
const int isl=2;
const int out=3;
vector <vector <int> > A;
queue <coord> q;
int w, h, x, y;
int ans;
int dx[] = {1, -1, 0,  0, 1, -1,  1, -1};
int dy[] = {0,  0, 1, -1, 1, -1, -1,  1};

void dfs1 (int y, int x){
	coord u, v;
	u.x=x;
	u.y=y;
	q.push(u);
	A[y][x]=out;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<8; ++i){
			v.y=u.y+dy[i];
			v.x=u.x+dx[i];
			if (v.x>=0 && v.x<w+2 && v.y>=0 && v.y<h+2 && A[v.y][v.x]==sea){
				A[v.y][v.x]=out;
				q.push(v);
			}				
		}
	}
}

void dfs2 (int y, int x){
	coord u, v;
	u.x=x;
	u.y=y;
	q.push(u);
	A[y][x]=out;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<4; ++i){
			v.y=u.y+dy[i];
			v.x=u.x+dx[i];
			if (v.x>=0 && v.x<w+2 && v.y>=0 && v.y<h+2 && (A[v.y][v.x]==sea || A[v.y][v.x]==isl || A[v.y][v.x]==bord)){
				A[v.y][v.x]=out;
				q.push(v);
			}				
		}
	}
}

void dfs3 (int y, int x){
	coord u, v;
	u.x=x;
	u.y=y;
	q.push(u);
	A[y][x]=out;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<4; ++i){
			v.y=u.y+dy[i];
			v.x=u.x+dx[i];
			if (v.x>=0 && v.x<w+2 && v.y>=0 && v.y<h+2 && A[v.y][v.x]==isl){
				A[v.y][v.x]=out;
				q.push(v);
			}				
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1250.in", "r", stdin);
	freopen ("T1250.out", "w", stdout);
#endif

	scanf ("%d%d%d%d\n", &w, &h, &x, &y);

	A.resize(h+2);
	for (int i=0; i<h+2; ++i){
		A[i].resize(w+2);
	}

	for (int i=1; i<=h; ++i){
		for (int j=1; j<=w; ++j){
			char ch;
			scanf ("%c", &ch);
			switch (ch){
				case '.': A[i][j]=sea;
					break;
				case '#': A[i][j]=isl;
					break;
			}
		}
		scanf ("\n");
	}

	dfs1(y, x);
	dfs2(0, 0);

	for (int i=1; i<=h; ++i){
		for (int j=1; j<=w; ++j){
			if (A[i][j]==isl){
				++ans;
				dfs3(i, j);
			}
		}
	}

	printf ("%d", ans);

	return 0;
}