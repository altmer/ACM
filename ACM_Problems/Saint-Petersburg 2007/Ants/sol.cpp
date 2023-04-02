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

struct coord{
	int x, y;
	coord():x(0),y(0){}
	coord (int _x, int _y):x(_x),y(_y){}
};

vector <coord> v1, v2;
vector <int> match;
int n;

bool intersect (const coord& p1, const coord& p2, const coord& p3, const coord& p4)
{
	double A1=p2.y-p1.y;
	double B1=p1.x-p2.x;
	double C1=A1*p1.x+B1*p1.y;
	double A2=p4.y-p3.y;
	double B2=p3.x-p4.x;
	double C2=A2*p3.x+B2*p3.y;
	double det=A1*B2-A2*B1;
	if (fabs(det)<1e-6){
		return false;
	}
	else{
		double x=(B2*C1-B1*C2)/det;
		double y=(A1*C2-A2*C1)/det;
		return x>=min(p1.x, p2.x) && x<=max(p1.x, p2.x) && x>=min(p3.x, p4.x) && x<=max(p3.x, p4.x) 
			&& y>=min(p1.y,p2.y) && y<=max(p1.y, p2.y) && y>=min(p3.y, p4.y) && y<=max(p3.y, p4.y);
	}
}

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	while (scanf ("%d", &n)!=EOF){
		if (!n)
			break;
		v1.assign(n, coord());
		v2.assign(n, coord());
		match.assign(n, 0);
		for (int i=0; i<n; ++i){
			scanf ("%d%d", &v1[i].x, &v1[i].y);
			match[i]=i;
		}
		for (int i=0; i<n; ++i){
			scanf ("%d%d", &v2[i].x, &v2[i].y);
		}
		bool fin=false;
		while (!fin){
			fin=true;
			for (int i=0; i<n; ++i){
				for (int j=i+1; j<n; ++j){
					if (intersect(v1[i], v2[match[i]], v1[j], v2[match[j]])){
						int tmp=match[i];
						match[i]=match[j];
						match[j]=tmp;
						fin=false;
					}
				}
			}
		}
		for (int i=0; i<n; ++i){
			printf ("%d\n", match[i]+1);
		}
		printf ("\n");
	}

	return 0;
}