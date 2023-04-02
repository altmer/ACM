#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Collision{
public:
	double probability(vector <int> A, int ids){
		double p1=1;
		int sum=0;
		for (int i=0; i<A.size(); ++i){
			sum+=A[i];
		}
		if(sum>ids)
			return 0;
		for (int i=ids; i>ids-sum; --i){
			p1*=double(i)/double(ids);
		}
		double p2=1;
		int ch=A[0];
		for (int i=1; i<A.size(); ++i){
			for (int j=0; j<A[i]; ++j){
				p2*=double(ids-ch-j)/double(ids-j);
			}
			ch+=A[i];
		}
		return fabs(p2-p1);
	}
};

//declarations
vector <int> v;
int ids;
Collision solve;

void input (void){
	v.push_back(20);
	v.push_back(20);
	ids=1000;
}

void output (void){
	cout << solve.probability(v, ids);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}