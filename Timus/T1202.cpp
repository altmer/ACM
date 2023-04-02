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

class Rect{
public:
	int x1, y1, x2, y2;
	bool overlap (const Rect& t){
		return ( (y2-t.y1>=2) && (t.y2-y1>=2) );
	}
};

class point{
public:
	int x, y;
	point(int a, int b) : x(a), y(b){}
	int MoveTo (int x, int y){
		int ans= abs(x-this->x) + abs(y-this->y);
		this->x = x;
		this->y = y;
		return ans;
	}
	int nearestY (int y1, int y2){
		if (this->y>=y1 && this->y<=y2){
			return this->y;
		}
		else{
			if (abs(this->y-y1)<abs(this->y-y2)){
				return y1;
			}
			else
				return y2;
		}
	}
};

int n, dist;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1202.in", "r", stdin);
	freopen ("T1202.out", "w", stdout);
#endif

	scanf ("%d", &n);
	
	point loc(1, 1);
	Rect prev, cur;
	
	scanf ("%d%d%d%d", &prev.x1,&prev.y1,&prev.x2, &prev.y2);
	cur=prev;
	
	for (int i=1; i<n; ++i){
		scanf ("%d%d%d%d", &cur.x1,&cur.y1,&cur.x2, &cur.y2);
		if (prev.overlap(cur)){
			dist+=loc.MoveTo(cur.x1, loc.nearestY(cur.y1+1, cur.y2-1) );
		}
		else{
			printf ("-1\n");
			return 0;
		}
		prev=cur;
	}
	dist+=loc.MoveTo(cur.x2-1,cur.y2-1);
	printf ("%d\n", dist);

	return 0;
}