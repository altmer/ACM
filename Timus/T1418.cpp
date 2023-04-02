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

struct Point{
	int x, y;
	bool operator<(const Point& p) const{
		return x<p.x || x==p.x && y<p.y;
	}
};

bool cw (Point& a, Point& b, Point& c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<=0;
}

bool ccw (Point& a, Point& b, Point& c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>=0;
}

bool ol (Point& a, Point& b, Point& c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)==0;
}

Point arr[5000], up[5000], down[5000], arr2[5000];
int upn[5000],  dn[5000];
bool conv[5000];
int pa=0, pu=0, pd=0, pa2=0;

bool convex (){
	if(pa<3) return false;
	for (int i=0; i<pa; ++i){
		conv[i]=false;
	}

	sort(arr, arr+pa);

	Point p1=arr[0];
	Point p2=arr[pa-1];

	pu=pd=pa2=0;
	up[pu]=p1;
	upn[pu++]=0;
	down[pd]=p1;
	dn[pd++]=0;

	for (int i=1; i<pa; ++i){
		if(i==pa-1 || cw(p1,arr[i],p2)){
			while(pu>=2 && !cw(up[pu-2], up[pu-1], arr[i])){
				pu--;
			}
			up[pu]=arr[i];
			upn[pu++]=i;

		}
		if(i==pa-1 || ccw(p1,arr[i],p2)){
			while(pd>=2 && !ccw(down[pd-2], down[pd-1], arr[i])){
				pd--;
			}
			down[pd]=arr[i];
			dn[pd++]=i;
		}
	}


	for (int i=0; i<pu; ++i){
		conv[upn[i]]=true;
		arr2[i]=up[i];
	}
	for (int j=0; j<pd; ++j){
		conv[dn[j]]=true;
		if(j>0 && j<pd-1)
			arr2[pu+j-1]=down[j];
	}
	bool fin=true;
	for (int i=0; i<(pu+pd-2)-2; ++i){
		if(!ol(arr2[i],arr2[i+1],arr2[i+2])){
			fin=false;
		}
	}

	if(fin)
		return false;

	for (int i=0; i<pa; ++i){
		if(!conv[i]){
			arr2[pa2++]=arr[i];
		}
	}

	pa=pa2;
	for (int i=0;i<pa2; ++i){
		arr[i]=arr2[i];
	}

	return pu+pd-2>2;
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	scanf("%d", &pa);
	for (int i=0; i<pa; ++i){
		scanf("%d%d", &arr[i].x, &arr[i].y);
	}

	int ans=0;
	while(convex())
		ans++;
	printf("%d\n", ans);

    return 0;
}