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
	bool operator !=(coord t){
		return x!=t.x || y!=t.y;
	}
	bool operator == (coord t){
		return x==t.x && y==t.y;
	}
};

vector <vector <bool> > v;
vector <coord> p;
int n,m, way;
coord treas, Lara, u;
int T, num;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1364.in", "r", stdin);
	freopen ("T1364.out", "w", stdout);
#endif
	scanf ("%d%d", &n, &m);
	v.resize(n+2);
	for (int i=0; i<v.size(); ++i){
		v[i].resize(m+2);
	}

	for (int i=0; i<n+2; ++i){
		v[i][0]=true;
		v[i][m+1]=true;
	}

	for (int i=0; i<m+2; ++i){
		v[0][i]=true;
		v[n+1][i]=true;
	}

	scanf ("%d%d%d%d%d", &treas.x, &treas.y, &Lara.x, &Lara.y, &T);

	u.x=1;
	u.y=0;
	way=1;

	while (u!=treas){
		switch(way){
			case 1: u.y+=1;
				if (!v[u.x][u.y]){
					v[u.x][u.y]=true;
					p.push_back(u);
				}
				else{
					u.y-=1;
					way=2;
				}
				break;
			case 2: u.x+=1;
				if (!v[u.x][u.y]){
					v[u.x][u.y]=true;
					p.push_back(u);
				}
				else{
					u.x-=1;
					way=3;
				}
				break;
			case 3: u.y-=1;
				if (!v[u.x][u.y]){
					v[u.x][u.y]=true;
					p.push_back(u);
				}
				else{
					u.y+=1;
					way=4;
				}
				break;
			case 4: u.x-=1;
				if (!v[u.x][u.y]){
					v[u.x][u.y]=true;
					p.push_back(u);
				}
				else{
					u.x+=1;
					way=1;
				}
				break;
		}
	}

	for (int i=0; i<p.size(); ++i){
		if (p[i]==Lara){
			num=i;
			break;
		}
	}

	int h=p.size()-1;
	for (int i=max(0, num-T); i<=min(num+T, h); ++i){
		printf ("%d %d\n", p[i].x, p[i].y);
	}
	
	return 0;
}