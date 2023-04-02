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

class Parking{
public:
	struct edge{
		int car, park, len;
		edge() : car(-1),park(-1), len(-1) {}
		edge(int a, int b, int c) : car(a), park(b), len(c) {}
		bool operator < (const edge& t) const{
			return len < t.len;
		}
	};
	struct coord{
		int x, y;
		coord () : x(-1), y(-1) {}
		coord (int a, int b) : x(a), y(b) {}
	};
	//graph
	int S, T;
	int num;
	vector <vector <int> > flow;
	vector <bool> vis;
	vector <int> par;
	//all_nodes
	int car, parking;
	multiset <edge> se;
	multiset <edge>::iterator it;
	// map
	int n, m;
	vector <vector <int> > A;
	vector <vector <int> > D;
	// BS
	int L, R;

	void make_map(vector <string> park){
		n = park.size();
		m = park[0].size();
		A.assign (n, vector <int> (m, -1));
		car = 0;
		parking = 0;
		for (int i=0; i<n; ++i){
			for (int j=0; j<m; ++j){
				switch (park[i][j]){
					case '.':
						A[i][j]=-1;
						break;
					case 'X':
						A[i][j]=-2;
						break;
					case 'C':
						A[i][j]=car++;
						break;
					case 'P':
						A[i][j]=100+parking++;
						break;

				}
			}
		}
	}

	void bfs (coord u, int f){
		int dx[] = { 0,  0, -1, 1};
		int dy[] = {-1,  1,  0, 0};
		D.assign(n, vector <int> (m, -1));
		D[u.x][u.y]=0;
		queue <coord> q;
		q.push(u);
		while (!q.empty()){
			u = q.front();
			q.pop();
			if (A[u.x][u.y]>=100){
				se.insert(edge(f, A[u.x][u.y]-100, D[u.x][u.y]));
				R = max(R, D[u.x][u.y]);
			}
			for (int i=0; i<4; ++i){
				int cx = u.x + dx[i];
				int cy = u.y + dy[i];
				if (cx >=0 && cx < n && cy>=0 && cy<m && A[cx][cy]>-2 && D[cx][cy]==-1){
					D[cx][cy]=D[u.x][u.y]+1;
					q.push(coord(cx,cy));
				}
			}
		}
	}

	void make_nodes(){
		for (int i=0; i<A.size(); ++i){
			for (int j=0; j<A[i].size(); ++j){
				if (A[i][j]>=0 && A[i][j]<100){
					bfs (coord(i, j), A[i][j]);
				}
			}
		}
	}

	void make_graph (int dist){
		num = car + parking + 2;
		S = num - 2;
		T = num - 1;
		flow.assign(num, vector <int> (num, 0));
		vis.assign(num, false);
		par.assign (num,  -1);
		for (it=se.begin(); it!=se.end(); ++it){
			if (it->len<=dist){
				flow[it->car][car + it->park]=1;
			}
			else
				break;
		}
		for (int i=0; i<car; ++i){
			flow[S][i]=1;
		}
		for (int i=car; i<car+parking; ++i){
			flow[i][T]=1;
		}
	}

	bool find_path(){
		vis.assign(num, false);
		queue <int> q;
		q.push(S);
		vis[S]=true;
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (int i=0; i<num; ++i){
				if (flow[u][i] && !vis[i]){
					par[i]=u;
					vis[i]=true;
					if(i==T)
						return true;
					q.push(i);
				}
			}
		}
		return false;
	}

	int max_flow(int dist){
		int ret = 0;
		make_graph(dist);
		while (find_path()){
			int cur=T;
			++ret;
			while (par[cur]!=-1){
				flow[par[cur]][cur]=0;
				flow[cur][par[cur]]=1;
				cur=par[cur];
			}
		}
		return ret;
	}

	int minTime(vector <string> park){
		make_map(park);
		if (car>parking)
			return -1;
		R=0;
		make_nodes();
		L=0;
		int ans = 1000000000;
		while (L<=R){
			int dist = (L+R)/2;
			int res = max_flow(dist);
			if (res<car){
				L=dist+1;
			}
			else if (res>=car){
				ans = min(ans, dist);
				R=dist-1;
			}
		}
		return ans==1000000000 ? -1 : ans;
	}
};

//declarations
Parking solve;
vector <string> v;

void input (void){
	v.push_back("C.....P");
	v.push_back("C.....P");
	v.push_back("C.....P");
}

void output (void){
	cout << solve.minTime(v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}