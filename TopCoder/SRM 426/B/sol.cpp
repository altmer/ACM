#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <list>
#include <set>
using namespace std;

class TheLongPalindrome{
public:
	long long step26[100];
	long long stepk[10000];

	long long quickpow(long long  x, long long pow){
		long long ret=1;
		while(pow){
			if(pow%2){
				ret*=x;
				ret%=1234567891;
				pow--;
			}
			else{
				x*=x;
				x%=1234567891;
				pow/=2;
			}
		}
		return ret;
	}
	int count(int n, int k){
		long long st=1;
		int ptr=0;
		while(st<1234567891){
			st*=26;
			step26[cnt++]=st;
		}
		for (int i
		st=1;
		ptr=0;
		while(st<1234567891){
			st*=k;
			stepk[cnt++]=st;
		}
		for (int i=1; i<=n; ++i){
		}

		if(n%2){
			n=n/2+1;
		}
		else
			n/=2;
	}
};

//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}