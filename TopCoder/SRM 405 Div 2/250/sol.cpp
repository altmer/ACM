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

class FallingFactorialPower{
public:
	double compute(int n, int k){
		double ans=1.0;
		if (k>0){
			for (int i=0; i<k; ++i){
				ans*=double(n-i);
			}
			return ans;
		}
		else if (k<0){
			for (int i=1; i<=abs(k); ++i){
				ans/=double(n+i);
			}
			return ans;
		}
		return ans;
	}
};

//declarations
int n;
// FallingFactorialPower solve;

void input (void){
	scanf ("%d", &n);
}

void output (void){
	printf ("");
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}