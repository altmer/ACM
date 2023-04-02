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
#include <limits>
#include <map>
#include <set>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

enum {BACK, FRONT, BOTTOM, TOP, LEFT, RIGHT};

double A, B, C;

class dot{
public:
	double x, y, z;

	void getloc()
	{
		int loc=-1;
		if (x<C){
			loc=LEFT;
		}
		else if(x<=C+A){
			if (y<B){
				loc = BACK;
			}
			else if (y<B+C){
				loc = BOTTOM;
			}
			else if (y<B+C+B){
				loc = FRONT;
			}
			else{
				loc = TOP;
			}
		}
		else{
			loc=RIGHT;
		}
		switch (loc){
			case BACK: z = 0;
				x -= C;
				y = B - y;
				break;
			case FRONT: z=C;
				x-=C;
				y-=B+C;
				break;
			case BOTTOM: z = y - B;
				y=0;
				x-=C;
				break;
			case TOP: z = C - ( y - B - C - B );
				y = B;
				x-=C;
				break;
			case LEFT: z = x;
				x = 0;
				y-=B+C;
				break;
			case RIGHT: z = C - (x - C - A);
				x = A;
				y-=B+C;
				break;
		}
	}

	dot (){
		cin >> x >> y;
		getloc();
	}

	double dist (dot& t){
		return sqrt ((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y)+(z-t.z)*(z-t.z));
	}
};

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1489.in", "r", stdin);
	freopen ("T1489.out", "w", stdout);
#endif

	cin >> A >> B >> C;
	dot v1, v2;
	printf ("%.6lf", v1.dist(v2));

	return 0;
}