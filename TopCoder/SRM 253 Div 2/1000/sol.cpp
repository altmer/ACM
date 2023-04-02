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

	int dx[]={-1, 1, -1, 1, -1, 1, 0,  0};
	int dy[]={ 0, 0, -1, -1, 1, 1, -1, 1};

class ABCPath{
public:
	int bfs(coord u, vector <string> &grid, vector <vector <int> > &dist){
		int res=1;
		queue <coord> q;
		q.push(u);
		dist[u.x+1][u.y+1]=1;
		while (!q.empty()){
			u=q.front();
			q.pop();
			for (int i=0; i<8; ++i){
				coord v;
				v.x=u.x+dx[i];
				v.y=u.y+dy[i];
				if ((dist[v.x+1][v.y+1]==0 || dist[v.x+1][v.y+1]<dist[u.x+1][u.y+1]+1 )  && grid[v.x][v.y]-grid[u.x][u.y]==1  ) {
					dist[v.x+1][v.y+1]=dist[u.x+1][u.y+1]+1;
					res=max(res, dist[v.x+1][v.y+1]);
					q.push(v);
				}
			}
		}
		return res;
	}
	int length(vector <string> grid){
		int n=grid.size()+2;
		int m=grid[0].size()+2;
		vector <vector <int> > A;
		A.resize(n);
		for (int i=0; i<n; ++i){
			A[i].resize(m);
		}
		for (int i=0; i<n; ++i){
			A[i][0]=1e+9;
			A[i][m-1]=1e+9;
		}
		for (int i=0; i<m; ++i){
			A[0][i]=1e+9;
			A[n-1][i]=1e+9;
		}
		coord u;
		int ans=0;
		for (u.x=0; u.x<grid.size(); ++u.x){
			for (u.y=0; u.y<grid[u.x].size(); ++u.y){
				if (grid[u.x][u.y]=='A'){
					for (int i=1; i<=grid.size(); ++i){
						for (int j=1; j<=grid[0].size(); ++j){
							A[i][j]=0;
						}
					}
					ans=max (ans, bfs(u, grid, A));
				}
			}
		}
		return ans;
	}
};

ABCPath solve;
//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	vector <string> grid(4);
	grid[0]="ABE";
	grid[1]="CFG";
	grid[2]="BDH";
	grid[3]="ABC";
int x= solve.length(grid);

	return 0;
}