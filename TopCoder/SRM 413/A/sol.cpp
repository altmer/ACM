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

class ArithmeticProgression{
public:
	bool res;
	vector <int> v;
	int st;
	double BS (double l, double r)
	{
		double cur=st;
		double mid=(l+r)/2;
		if (r-l<1e-9)
			return mid;
		for (int i=0; i<v.size(); ++i){
			cur+=mid;
			if (floor(cur)<v[i])
				return BS(mid,r);
			if (floor(cur)>v[i])
				return BS(l,mid);
		}
		res=true;
		return BS(l,mid);
	}
	double minCommonDifference(int a0, vector <int> seq)
	{
		v=seq; st=a0;
		if (seq.empty())
			return 0;
		if (seq[0]<a0)
			return -1;
		for (int i=1; i<seq.size(); ++i){
			if (seq[i]<seq[i-1])
				return -1;
		}
		double ans=BS(seq[0]-a0, seq[0]-a0+1);
		return res ? ans : -1;
	}
};

//declarations

ArithmeticProgression solve;

void input (void){
}

void output (void){
	vector <int> v;
	v.push_back(6);
	v.push_back(14);
	cout << solve.minCommonDifference(0, v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}