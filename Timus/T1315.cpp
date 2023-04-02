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
#include <list>
#include <set>
using namespace std;

enum en {WALL, WATER, FREE, UNDETER};
int dx[] = {0,  0, 1, -1 };
int dy[] = {1, -1, 0,  0 };

class Location{
public: 
	int x, y, oxy;
	Location() : x(0), y(0), oxy(0) {}
	Location(int a, int b) : x(a), y(b), oxy(0) {}
	Location(int a, int b, int c) : x(a), y(b), oxy(c) {}
};

class Grid{
protected:
	int N, M;
	vector <vector <int> > mapp;
	vector <vector <int> > O;
	bool res;
	bool check (int x, int y){
		return x>=0 && x<N && y>=0 && y<M;
	}
	void Fill (Location u){
		queue <Location> q;
		mapp[u.x][u.y]=WATER;
		q.push(u);
		while (!q.empty()){
			u = q.front();
			q.pop();
			for (int i=0; i<3; ++i){
				int cx = u.x+dx[i];
				int cy = u.y+dy[i];
				if (check(cx, cy) && mapp[cx][cy]==UNDETER){
					mapp[cx][cy]=WATER;
					q.push(Location(cx, cy));
				}
			}
		}
	}
	void FloodFill (){
		Location u;
		res = false;
		for (int i=0; i<M; ++i){
			if (mapp[0][i]==UNDETER){
				res = true;
				Fill(Location (0, i));
			}
		}
	}
public:
	Grid (int x, int y) : N(x), M(y), res (true){
		mapp.assign(N, vector<int> (M, -1));
		O.assign (N, vector<int> (M, 0));
		string tmp;
		for (int i=0; i<N; ++i){
			getline (cin, tmp);
			for (int j=0; j<M; ++j){
				switch (tmp[j]){
					case '#': mapp[i][j]=WALL;
						break;
					case '.': mapp[i][j]=UNDETER;
						break;
				}
			}
		}
		FloodFill();
	}
	bool run (Location u){
		if (!res)
			return res;
		queue <Location> q;
		int max_oxy = u.oxy;
		q.push(u);
		O[u.x][u.y]=u.oxy;
		while (!q.empty()){
			u = q.front();
			q.pop();
			for (int i=0; i<4; ++i){
				int cx = u.x+dx[i];
				int cy = u.y+dy[i];
				if (check(cx, cy) && mapp[cx][cy]!=WALL){
					if (mapp[cx][cy]==WATER){
						if (u.oxy-1 > O[cx][cy]){
							O[cx][cy]=u.oxy-1;
							q.push(Location(cx, cy, O[cx][cy]));
						}
					}
					else if (O[cx][cy]==0){
						O[cx][cy]=max_oxy;
						q.push(Location(cx, cy, O[cx][cy]));
					}
				}
			}
		}
		for (int i=0; i<M; ++i){
			if (O[0][i]>0)
				return true;
		}
		return false;
	}
};

int n, m, x, y, D;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1315.in", "r", stdin);
	freopen ("T1315.out", "w", stdout);
#endif

	scanf ("%d%d%d%d%d\n", &m, &n, &y, &x, &D);
	
	x=n-x;
	--y;

	Grid solve(n, m);
	if (solve.run (Location (x, y, D)))
		printf("Can be rescued by himself\n");
	else
		printf("Rescue operation required");

	return 0;
}