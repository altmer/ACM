#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class TVTower{
public:
	double mRad;
	vector <double> x, y;
	double cx, cy;
	
	void check(double xx, double yy)
	{
		double cur=0;
		for (int i=0; i<x.size(); ++i){
			cur=max(cur, sqrt((x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy)));
		}
		mRad=min(mRad, cur);
	}

	void center(int i, int j, int k)
	{
		double A1=x[j]-x[i];
		double B1=y[j]-y[i];
		double C1=A1*(x[j]+x[i])/2.0+B1*(y[j]+y[i])/2.0;
		double A2=x[k]-x[j];
		double B2=y[k]-y[j];
		double C2=A2*(x[k]+x[j])/2.0+B2*(y[k]+y[j])/2.0;
		double det=-B1*A2+B2*A1;
		if (fabs(det)>1e-6){
			cx=(-B1*C2+B2*C1)/det;
			cy=(-A2*C1+A1*C2)/det;
		}
	}
	double minRadius(vector <int> _x, vector <int> _y)
	{
		mRad=1e+9;
		cx=2e+9;
		cy=2e+9;
		x.resize(_x.size());
		y.resize(_y.size());
		for (int i=0; i<_x.size(); ++i){
			x[i]=_x[i];
			y[i]=_y[i];
		}
		if (x.size()==1)
			return 0;
		for (int i=0; i<x.size(); ++i){
			for (int j=i+1; j<x.size(); ++j){
				check ((x[i]+x[j])/2.0, (y[i]+y[j])/2.0);
				for (int k=j+1; k<x.size(); ++k){
					center (i, j, k);
					check(cx, cy);
				}
			}
		}
		return mRad;
	}
};

//declarations
vector <int> x, y;
TVTower solve;

void input (void){
	x.push_back(5);
	x.push_back(-3);
	x.push_back(-4);
	y.push_back(0);
	y.push_back(4);
	y.push_back(-3);
/*	x.push_back(1000);
	x.push_back(1000);
	x.push_back(1000);
	x.push_back(1000);
	x.push_back(995);
	y.push_back(500);
	y.push_back(1000);
	y.push_back(-300);
	y.push_back(-989);
	y.push_back(-300);*/

}

void output (void){
	cout << solve.minRadius(x, y);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}