#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <queue>
using namespace std;
int m,n;
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};
bool color[13][13];
pair<int,int> parent[13][13];
bool ins(int x, int y){
	return x>=0 && x<m && y>=0 && y<n;
}

bool f(int x, int y, int prevdir, int rd){
	if(rd==m*n)return true;
	bool res=false;
	for(int dir=0;!res && dir<8;dir++)
		if(dir!=prevdir)
			if(ins(x+dx[dir],y+dy[dir]) && !color[x+dx[dir]][y+dy[dir]]){
				color[x+dx[dir]][y+dy[dir]]=true;
				parent[x+dx[dir]][y+dy[dir]]=make_pair(x,y);
				res=f(x+dx[dir],y+dy[dir],dir,rd+1);
				color[x+dx[dir]][y+dy[dir]]=false;
			}
	return res;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin>>m>>n;
	double otv=m*n+(m+n+1)*sqrt(2.0)-m-n-1;
	printf("%.9lf",otv);
	return 0;
}