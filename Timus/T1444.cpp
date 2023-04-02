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
double mina, maxa, mid;
struct coord{
	int num, x, y;
	double angle;
	coord():x(0),y(0), num(0), angle(0){}
	coord(int _x, int _y):x(_x),y(_y), num(-1), angle(0){}
	bool operator < (const coord& t)const{
		if (fabs(angle-t.angle)<1e-6){
			if (angle<mid){
				if (x==t.x)
					return y<t.y;
				return x<t.x;	
			}
			else{
				if (x==t.x)
					return y>t.y;
				return x>t.x;	
			}
		}
		return angle<t.angle;
	}
	bool operator << (const coord& t) const{
		if (y==t.y)
			return x<t.x;
		return y<t.y;
	}
	coord operator - (const coord& t)const{
		coord tmp;
		tmp.x=x-t.x;
		tmp.y=y-t.y;
		return tmp;
	}
};

vector <coord> v;
int n;
double cosinus (const coord& a, const coord& b)
{
	return static_cast<double>((a.x*b.x+a.y*b.y))/(sqrt(static_cast<double>(a.x*a.x+a.y*a.y))*sqrt(static_cast<double>(b.x*b.x+b.y*b.y)));
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1444.in", "r", stdin);
	freopen ("T1444.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	coord cur(100000, 1000000), cur2;

	for (int i=0; i<n; ++i){
		scanf ("%d%d", &v[i].x, &v[i].y);
		v[i].num=i+1;
		if (v[i]<<cur)
			cur=v[i];
	}
	cur2.x=1;
	cur2.y=0;

	mina=+1e+9; maxa=-1e+9;

	for (int i=0; i<n; ++i){
		if (v[i].x==cur.x && v[i].y==cur.y){
			v[i].angle=acos(1.0);
		}
		else{
			v[i].angle=acos(cosinus(cur2, v[i]-cur));
			if (v[i].angle<mina)
				mina=v[i].angle;
			else if (v[i].angle>maxa)
				maxa=v[i].angle;
		}
	}

	mid=(mina+maxa)/2.0;

	sort(v.begin(), v.end());

	printf ("%d\n", n);
	int k=-1;
	for (int i=0; i<n; ++i){
		if (v[i].num==1){
			k=i;
			break;
		}
	}

	for (int i=k; i<n; ++i){
		printf ("%d\n", v[i].num);
	}

	for (int i=0; i<k;++i){
		printf ("%d\n", v[i].num);
	}

	return 0;
}