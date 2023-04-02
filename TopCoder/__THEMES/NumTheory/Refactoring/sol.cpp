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

class Refactoring{
public:
	int refactor(int n, int prev=2)
	{
		int ret=0;
		int lim=static_cast<int>(sqrt(double(n)));
		for (int i=prev; i<=lim; ++i){
			if (n%i==0){
				++ret;
				ret+=refactor(n/i, i);
			}
		}
		return ret;
	}
};

//declarations
Refactoring solve;

void input (void){
}

void output (void){
	cout << solve.refactor(24);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}