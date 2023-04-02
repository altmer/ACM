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

class RedIsGood{
public:
	double rec (double p,  int R, int B)
	{
		double sum1=0, sum2=0;
		double p1=0, p2=0;
		// red card?
		if (R){
			p1=p*double(R)/double(R+B);
			sum1 = p1 + rec(p1, R-1, B);
		}
		else 
			return 0;
		if(B){
			p2=p*double(B)/double(R+B);
			sum2 = -p2 + rec(p2, R, B-1);
		}

		if(sum1<0)
			sum1=0;
		if(sum2<0)
			sum2=0;

		return sum1+sum2;
	}
	double getProfit(int R, int B)
	{
		return rec (1, R, B);
	}
};

//declarations
RedIsGood solve;

void input (void){
}

void output (void){
	cout << solve.getProfit(12,4);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}