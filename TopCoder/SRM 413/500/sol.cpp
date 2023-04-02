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
map <long long, long long> dict;
class InfiniteSequence2{
public:
	int p1,q1, x1, y1;
	long long calc2 (long long n){
		if (n<=0)
			return 1;
		if (dict.count(n))
			return dict[n];
		return dict[n]=long long (calc2 (floor(static_cast<double>(n)/static_cast<double>(p1)-x1)))
			+ long long (calc2 (floor(static_cast<double>(n)/static_cast<double>(q1)-y1)));
	}
	long long calc(long long n, int p, int q, int x, int y)
	{	
		p1=p;q1=q;x1=x;y1=y;
		return calc2(n);	
	}
};

//declarations

InfiniteSequence2 solve;

void input (void){
}

void output (void){
	long long a=1e+6;
	a*=1000000;
	a*=10;

	cout << solve.calc(10000000000000, 2, 2, 3, 1757567);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}