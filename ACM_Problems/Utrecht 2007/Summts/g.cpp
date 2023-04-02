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

struct matr{
	int h;
	bool isp;
	int minim;
	bool versh;
};
struct coord{
	int h;
	int y,x;
	bool operator<(const coord &c)const{
		return h>c.h;
	}
};

int ntest;
matr m[501][501];
coord c[250003];
int pos;
int h,w,d;
int cnt;
int dx[4]={+1, 0,-1, 0};
int dy[4]={ 0,+1, 0,-1};

queue<int>qx;
queue<int>qy;
//-------------------------
void read();
void reshen();
//-------------------------
int main (void)
{
	/*
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);//*/

	scanf ("%d\n", &ntest);
	for (int testt=0; testt<ntest; ++testt){
		read();
		reshen();
		printf ("%d\n", cnt);
	}

	return 0;
}
//-------------------------
void read(){
	scanf("%d%d%d",&h,&w,&d);
	pos=0;
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			scanf("%d",&m[i][j].h);
			m[i][j].isp=false;
			m[i][j].versh=true;
			c[pos].h=m[i][j].h;
			c[pos].x=j;
			c[pos].y=i;
			++pos;
		}
	}
}
//-------------------------
void reshen(){
	cnt=0;
	sort(c,c+pos);
	for(int i=0;i<pos;++i){
		int x,y;
		y=c[i].y;
		x=c[i].x;
		if(m[y][x].isp)continue;
		++cnt;
		qx.push(x);
		qy.push(y);
		m[y][x].isp=true;
		m[y][x].minim=m[y][x].h;

		while(!qx.empty()){
			int tx=qx.front();qx.pop();
			int ty=qy.front();qy.pop();
			int minim=m[ty][tx].minim;
			for(int k=0;k<4;++k){
				int xt=tx+dx[k];
				int yt=ty+dy[k];
				if(xt<0||yt<0||xt>=w||yt>=h)continue;

				if(m[yt][xt].h>=minim+d)continue;

				if(!m[yt][xt].isp || (m[yt][xt].minim<m[ty][tx].minim && m[yt][xt].minim!=m[yt][xt].h)){
					if(m[yt][xt].h==m[y][x].h && !m[yt][xt].isp)
						++cnt;
					m[yt][xt].isp=true;
					m[yt][xt].minim=min(m[ty][tx].minim, m[yt][xt].h);
					qy.push(yt);
					qx.push(xt);
				}
			}
		}
	}
}