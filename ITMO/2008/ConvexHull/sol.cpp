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

const double eps=1e-9;

struct point{
	double x, y;
	int num;
	bool hull;
	bool operator <(const point& p)const{
		if (fabs(y-p.y)<1e-9){
			return x<p.x;
		}
		return y<p.y;
	}
};

vector <point> v;
int n;

void convhull(){
	int p=0;
	for (int i=1; i<n; ++i){
		if(v[i]<v[p]){
			p=i;
		}
	}
	int start=p;
	v[p].hull=true;
	double dx=-1;
	double dy=0;
	do{
		double coss=-2;
		double dist=0.0;
		int next=-1;
		for (int i=0; i<n; ++i){
			double sp=dx*(v[i].x-v[p].x)+dy*(v[i].y-v[p].y);
			double len=sqrt((v[i].x-v[p].x)*(v[i].x-v[p].x) + (v[i].y-v[p].y)*(v[i].y-v[p].y));
			if (fabs(len)>eps){
				double ccos=sp/len;
				if (ccos>coss){
					coss=ccos;
					dist=len;
					next=i;
				}
				else if (fabs(ccos-coss)<eps && dist>len){
					coss=ccos;
					dist=len;
					next=i;
				}
			}
		}
		v[next].hull=true;
		dx=(v[next].x-v[p].x)/dist;
		dy=(v[next].y-v[p].y)/dist;
		p=next;
	}while(p!=start);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%lf%lf", &v[i].x, &v[i].y);
		v[i].num=i+1;
	}

	convhull();

	for (int i=0; i<n; ++i){
		if (v[i].hull){
			cout << v[i].num << endl;
		}
	}

	return 0;
}