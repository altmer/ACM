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

class ForbiddenStrings{
public:
	long long countNotForbidden(int n)
	{
		vector <long long> forb(40), nfor(40);
		forb[0]=0; nfor[0]=1;
		forb[1]=0; nfor[1]=3;
		forb[2]=0; nfor[2]=9;
		forb[3]=6; nfor[3]=21;
		for (int i=4; i<=n; ++i){
			forb[i]=forb[i-1]*3+nfor[i-3]*4;
			nfor[i]=(forb[i-1]+nfor[i-1])*3-forb[i];
		}
		return nfor[n];
	}	
};

//declarations
ForbiddenStrings solve;

void input (void){
}

void output (void){
	cout << solve.countNotForbidden(30);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}