#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct point{
	double x, y;
	point (){
		x=y=0;
	}
	point (int _X, int _Y){
		x=_X; y=_Y;
	}
	point operator + (const point &t){
		point res;
		res.x=x+t.x;
		res.y=y+t.y;
		return res;
	}
	point operator - (const point &t){
		point res;
		res.x=x-t.x;
		res.y=y-t.y;
		return res;
	}
	const double operator ^ (const point &t){
		return x*t.y-y*t.x;
	}
	const double operator * (const point &t){
		return x*t.x+y*t.y;
	}
};

class PointInPolygon{
public:
	bool intersect (const point &A, const point &B, const point &C, const point &D){
		double A1=B.y-A.y, B1=A.x-B.x, C1=A.x*A1+A.y*B1;
		double A2=D.y-C.y, B2=C.x-D.x, C2=C.x*A2+C.y*B2;
		double det=A1*B2-A2*B1;
		if (det==0){
			return false;
		}
		else{
			double x=(B2*C1-B1*C2)/det;
			double y=(A1*C2-A2*C1)/det;
			return x>=A.x && x<=B.x && y>=A.y && y<=B.y && x>=min(C.x, D.x) && x<=max(C.x, D.x) && y>=min(C.y, D.y) && y<=max(C.y, D.y);
		}		
	}
	string testPoint(vector <string> vert, int PX, int PY){
		// input data
		point P(PX, PY);
		vector <point> v;
		for (int i=0; i<vert.size(); ++i){
			int x, y;
			istringstream str_in (vert[i]);
			str_in >> x >> y;
			v.push_back(point(x, y));
		}
		v.push_back(v.front());
		// check if boundary
		for (int i=1; i<v.size(); ++i){
			if (((v[i]-v[i-1])^(P-v[i-1]))==0 && 
				P.x>=min(v[i].x, v[i-1].x) && P.x<= max(v[i].x, v[i-1].x) && P.y>=min(v[i].y, v[i-1].y) && 
				P.y<=max(v[i].y, v[i-1].y)){
				return "BOUNDARY";
			}
		}
		// check randomize
		pair <int, int> ans;
		for (int test=0; test<100; ++test){
			point P2(rand()+1001, rand()+1001);
			int cnt=0;
			for (int i=1; i<v.size(); ++i){
				if (intersect(P, P2, v[i-1],v[i])){
					++cnt;
				}
			}
			if (cnt%2==0){
				ans.first++;// outer
			}
			else{
				ans.second++;// inter
			}
		}
		if (ans.first>ans.second)
			return "EXTERIOR";
		else
			return "INTERIOR";
	}
};

//declarations
int x, y;
vector <string> A;
PointInPolygon solve;

void input (void){
	int n;
	scanf ("%d\n", &n);
	A.resize(n);
	for (int i=0; i<n; ++i){
		getline (cin, A[i]);
	}
	scanf ("%d%d", &x, &y);
}

void output (void){
	cout << solve.testPoint(A, x ,y);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}