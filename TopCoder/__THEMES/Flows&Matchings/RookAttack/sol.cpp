#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class RookAttack{
public:
	static const int INF = 1000000000;
	int n;
	int S, T;
	vector <vector <int> > flow;
	vector <vector <bool> > grid;
	vector <bool> vis;
	vector <int> par;

	bool bfs(){
		queue <int> q;
		q.push(S);
		vis.assign(n, false);
		par.assign(n, -1);
		vis[S]=true;
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (int v=0; v<n; ++v){
				if (flow[u][v] && !vis[v]){
					vis[v]=true;
					par[v]=u;
					if (v==T)
						return true;
					q.push(v);
				}
			}
		}
		return false;
	}

	int max_flow(){
		int ans=0;

		while(bfs()){
			// find max increasing flow
			int cur = T;
			int res = INF;
			while (par[cur]!=-1){
				res = min(res, flow[par[cur]][cur]);
				cur = par[cur];
			}
			cur = T;
			while (par[cur]!=-1){
				flow[par[cur]][cur]-=res;
				flow[cur][par[cur]]+=res;
				cur = par[cur];
			}
			ans+=res;
		}

		return ans;
	}

	int howMany(int rows, int cols, vector <string> cutouts){
		grid.assign (rows, vector <bool> (cols, false));

		for (int i=0; i<cutouts.size(); ++i){
			int x, y;
			int st=0;
			for (int j=0; j<cutouts[i].size(); ++j){
				if (cutouts[i][j]==','){
					istringstream strin (cutouts[i].substr(st, j-st));
					st=j+1;
					strin >> x >> y;
					grid[x][y]=true;
				}
			}
			if (st<cutouts[i].size()){
				istringstream strin (cutouts[i].substr(st));
				strin >> x >> y;
				grid[x][y]=true;
			}
		}
		
		n = rows + cols + 2;
		S=n-2;
		T=n-1;
		flow.assign(n, vector <int> (n, 0));
		vis.assign(n, false);
		par.assign(n, -1);
		for (int i=0; i<rows; ++i){
			flow[S][i]=1;
			for (int j=0; j<cols; ++j){
				flow[rows+j][T]=1;
				if (!grid[i][j]){
					flow[i][rows+j]=1;
				}
			}
		}

		return max_flow();
	}

};

//declarations
RookAttack solve;
vector <string> v;

void input (void){
	v.push_back("1 0");
}

void output (void){
	cout << solve.howMany (8, 8, v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}