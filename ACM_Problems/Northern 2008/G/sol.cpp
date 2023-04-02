#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <functional>
using namespace std;
const double eps(1e-9);
int n,k,alp;
double ha,hb,hc,hbha;
double al;
bool b[4200][4200];
void print_gilb(){
	for(int j=k-1;j>=0;j--){
		for(int i=0;i<k;i++)
			if(b[i][j])printf("_");
			else printf("#");
		printf("\n");
	}
}
void construct(){
	k=1;
	b[0][0]=true;
	for(int lev=2;lev<=n;lev++){
		int nk=2*k+1;
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				b[i+k+1][j]=b[i][j];
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				b[k-j-1][k+i+1]=!b[i][j];
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				b[k+j+1][k+i+1]=!b[i][j];
		b[k][k]=true;
		for(int i=0;i<k;i++){
			b[i][k]=true;
			b[k+1+i][k]=true;
			b[k][nk-i-1]=true;
		}
		k=nk;
	}
}
double fill(int x, int y, int dir, double h){
	if(x<0 || x>=k || y<0 || y>=k || !b[x][y] || h<eps)return 0.0;
	if(h>hc)h=hc;
	double res=h*(ha+hb)-ha*hb;
	if(alp!=0){
		if(h>ha)res-=(h-ha)*(h-ha)/hbha/2.0;
		else res+=(h-ha)*(h-ha)*hbha/2.0;
		if(h>hb)res-=(h-hb)*(h-hb)*hbha/2.0;
		else res+=(h-hb)*(h-hb)/hbha/2.0;
	}
	else res=1.0;
	if(dir!=1)res+=fill(x,y+1,2,h-ha);
	if(dir!=2)res+=fill(x,y-1,1,h+ha);
	if(dir!=3)res+=fill(x+1,y,4,h-hb);
	if(dir!=4)res+=fill(x-1,y,3,h+hb);
	return res;
}
int main(){
	freopen("ground.in", "r", stdin);
	freopen("ground.out","w",stdout);
	cin>>n>>alp;
	al=(alp*acos(-1.0)/180.0);
	construct();
	double ans=0.0;
	ha=cos(al);
	hb=sin(al);
	hc=ha+hb;
	hbha=tan(al);
	for(int i=0;i<k;i++)
		if(b[i][k-1])
			ans+=fill(i,k-1,1,ha);
	//print_gilb();
	printf("%.7lf",ans);
	return 0;
}