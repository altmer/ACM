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

const double eps=1e-6;
vector<string> grid;
vector<vector<int> > dist, tmp;
vector<vector<int> > snyk;
int m, n, k;
pair<int,int> st, end;
int dx[]={-1, 1, 0,0};
int dy[]={0, 0, -1,1};
int ans=100000000;

bool on_board(pair<int,int> v ){
	return v.first>=0 && v.first<m && v.second>=0 && v.second<n;
}

bool cansnyk(pair<int,int> f, pair<int,int> t){
	pair<double,double> from(f);
	pair<double,double> to(t);
	if(f.first!=t.first){
		from.first+=0.5/**((t.first-f.first)/abs(t.first-f.first))*/;
		to.first+=0.5/*((f.first-t.first)/abs(f.first-t.first))*/;
	}
	if(f.second!=t.second){
		from.second+=0.5/**double((t.second-f.second)/abs(t.second-f.second))*/;
		to.second+=0.5/**double((f.second-t.second)/abs(f.second-t.second))*/;
	}

	int delx=abs(from.first-to.first);
	int dely=abs(from.second-to.second);
	double dx,dy;
	if(delx>=dely){
		dx=0.5;
		if(delx==0)
			dy=0;
		else
			dy=(double(dely)*dx)/(double(delx));
	}
	else{
		dy=0.5;
		if(dely==0)
			dx=0;
		else
			dx=(double(delx)*dy)/(double(dely));
	}
	if(from.first>to.first)
		dx=-dx;
	if(from.second>to.second)
		dy=-dy;
	for (double x=from.first, y=from.second; fabs(x-to.first)>eps && fabs(y-to.second)>eps; x+=dx, y+=dy){
		vector<int> px, py;
		if(fabs(x-floor(x))<eps){
			px.push_back(floor(x)-1);
		}
		px.push_back(floor(x));

		if(fabs(y-floor(y))<eps){
			py.push_back(floor(y)-1);
		}
		py.push_back(floor(y));

		for (int i=0; i<px.size(); ++i){
			for (int j=0; j<py.size(); ++j){
				if(grid[px[i]][py[j]]=='*' && abs(px[i]-f.first)+abs(py[j]-f.second)>1)
					return true;
			}
		}
	}
	return false;
}

int fsnyk(pair<int,int> stt){
	queue<pair<int,int> > q;
	vector<vector<int> > dist(m, vector<int>(n,numeric_limits<int>::max()));
	dist[stt.first][stt.second]=0;
	q.push(stt);
	while(!q.empty()){
		pair <int,int> u=q.front();
		q.pop();
		for (int i=0; i<4; ++i){
			pair<int,int> v=make_pair(u.first+dx[i],u.second+dy[i]);
			if(on_board(v) && grid[v.first][v.second]!='*' && dist[v.first][v.second]>dist[u.first][u.second]+1){
				if(stt==make_pair(3,4) && v==make_pair(1,6)){
					cerr<<"Yay!";
				}
				q.push(v);
				dist[v.first][v.second]=dist[u.first][u.second]+1;
				if ((dist[v.first][v.second]>=5 || cansnyk(stt,v))){
					return 2*dist[v.first][v.second];
				}
			}
		}
	}
}

int bfs(pair<int,int> stt){
	queue<pair<int,int> > q;
	q.push(stt);
	vector<vector<int> > dist(m, vector<int>(n,10000000));
	dist[stt.first][stt.second]=0;
	while(!q.empty()){
		pair <int,int> u=q.front();
		q.pop();
		for (int i=0; i<4; ++i){
			pair<int,int> v=make_pair(u.first+dx[i],u.second+dy[i]);
			if(on_board(v) && grid[v.first][v.second]!='*' && dist[v.first][v.second]>dist[u.first][u.second]+1){
				q.push(v);
				dist[v.first][v.second]=dist[u.first][u.second]+1;
				if(v==end)
					return dist[v.first][v.second];
			}
		}
	}
	return 1000000000;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("maze.in", "r", stdin);
	freopen ("maze.out", "w", stdout);
#endif

	cin >> m >> n >> k >> st.second >> st.first >> end.second >> end.first;
	st.second--; st.first--;end.second--; end.first--;

	snyk.assign(m, vector<int> (n,0));
	dist.assign(n, vector<int>(n, numeric_limits<int>::max()));
	grid.resize(m);
	string musssor;
	getline(cin,musssor);
	for (int i=0; i<m; ++i){
		getline(cin, grid[i]);
	}

	for (int i=0; i<m; ++i){
		for (int j=0; j<n; ++j){
			if(grid[i][j]=='@'){
				snyk[i][j]=fsnyk(make_pair(i,j));
			}
		}
	}

	ans=min(ans,bfs(st));
	for (int i=0; i<m; ++i){
		for (int j=0; j<n; ++j){
			if(grid[i][j]=='@' && snyk[i][j]){
				vector<pair<int,int> > tt;
				for (int k=0; k<4; ++k){
					if(on_board(make_pair(i+dx[k], j+dy[k])) && grid[i+dx[k]][ j+dy[k]]=='*'){
						grid[i+dx[k]][ j+dy[k]]='.';
						tt.push_back(make_pair(i+dx[k], j+dy[k]));
					}
				}
				int mindist=bfs(st)+snyk[i][j];
				ans=min(ans,mindist);
				for (int i=0; i<tt.size(); ++i){
					grid[tt[i].first][tt[i].second]='*';
				}
			}
		}
	}
	if(ans>100000){
		printf("0\n");
	}
	else{
		printf("%d\n", ans);
	}

	return 0;
}