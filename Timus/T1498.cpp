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
#include <set>
using namespace std;

class coord{
public:
	int x, y;
	coord() : x(0), y(0) {}
	coord(int a, int b) : x(a), y(b) {}
};

int dx[4] = {0,  0, -1, 1};
int dy[4] = {1, -1,  0, 0};
int G[110][110];
int n, m, l;
coord st, tar;
int ans=0;

inline bool check (int x, int y)
{
	return x>=0 && x<n && y>=0 && y<m;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1498.in", "r", stdin);
	freopen ("T1498.out", "w", stdout);
#endif

	 scanf ("%d%d%d%d%d%d%d", &n, &m, &l, &st.x, &st.y, &tar.x, &tar.y);
	 st.x--; st.y--; tar.x--; tar.y--;
	 for (int i=0; i<110; ++i){
		 for (int j=0; j<110; ++j){
			 G[i][j]=1000000000;
		 }
	 }
	 G[st.x][st.y]=0;

	 queue <coord> q;
	 q.push(st);
	 while (!q.empty()){
		 coord u = q.front();
		 q.pop();

		 int dmove=l-G[u.x][u.y];
		 int ddy=abs(u.y-tar.y);
		 int ddx=abs(u.x-tar.x);

		 if (!ddx){
			 if (ddy==1)
				ans = max(ans, 1);
			 else if (ddy-1<=dmove){
				ans=max(ans, ddy);
			 }
		 }
		 else if (!ddy){
			 if (ddx==1)
				ans = max(ans, 1);
			 else if (ddx-1<=dmove){
				ans=max(ans, ddx);
			 }
		 }
 
		 else if (ddx==1 && ddy <= dmove){
			 ans=max(ans, ddy+1);
		 }
		 else if (ddy==1 && ddx <= dmove){
			 ans=max(ans, ddx+1);
		 }

		 for (int p=0; p<4; ++p){
			 int cx = u.x + dx[p];
			 int cy = u.y + dy[p];
			 if (check(cx, cy) && G[u.x][u.y]<l && G[cx][cy]>G[u.x][u.y]+1 && (cx!=tar.x || cy!=tar.y)){
				 G[cx][cy]=G[u.x][u.y]+1;
				 q.push(coord(cx, cy));
			 }
		 }
	 }

	 printf ("%d\n", ans);

	return 0;
}