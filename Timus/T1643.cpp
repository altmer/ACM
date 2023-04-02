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

struct point{
	int x, y;
	point(int a=-1,int b=-1, int c=-1) :x(a),y(b){}
};

vector <string> grid;
int A[3][200][200];
int D[200][200];
bool F[200][200];
vector <point> T[255];
int n, m;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int ans=2000000000;
int lx, ly;
point q[1000000];
int head,tail;
point cat, jin;

bool onboard(point p){
	return p.x>=0 && p.x<n && p.y>=0 && p.y<m;
}

void bfs(point u, int w){
	A[w][u.x][u.y]=0;
	queue<point>q;
	q.push(u);
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<8; ++i){
			point v(u.x+dx[i],u.y+dy[i]);
			if (onboard(v) && grid[v.x][v.y]!='#' && A[w][v.x][v.y]==100000000){
				A[w][v.x][v.y]=A[w][u.x][u.y]+1;
				q.push(v);
				if (isupper(grid[v.x][v.y])){
					for (int k=0; k<T[grid[v.x][v.y]].size(); ++k){
						if (A[w][T[grid[v.x][v.y]][k].x][T[grid[v.x][v.y]][k].y]==100000000){
							A[w][T[grid[v.x][v.y]][k].x][T[grid[v.x][v.y]][k].y]=A[w][v.x][v.y];
							q.push(T[grid[v.x][v.y]][k]);
						}
					}
				}
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf("%d%d\n", &n, &m);
	grid.resize(n);

	for (int i=0; i<n; ++i){
		getline(cin, grid[i]);
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			A[0][i][j]=A[1][i][j]=A[2][i][j]=100000000;
			if (isupper(grid[i][j])){
				T[grid[i][j]].push_back(point(i,j));
			}
			if (grid[i][j]=='*'){
				lx=i;ly=j;
				grid[i][j]='#';
			}
			if (grid[i][j]=='$'){
				cat=point(i,j,0);
			}
			if (grid[i][j]=='!'){
				jin=point(i,j,1);
			}
		}
	}


	bfs(cat,0);
	bfs(jin,1);

	for (int k=0; k<8; ++k){
		point v(lx+dx[k],ly+dy[k]);
		if (onboard(v)){
			ans=min(ans, max(A[0][v.x][v.y],A[1][v.x][v.y])+1);
		}
	}

	if (ans>=100000000){
		cout << "Impossible\n";
	}
	else{
		cout << ans << endl;
	}

	return 0;
}