#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

int bc[32][32];

class FactoryCounting{
public:
	long long ans;
	int num1, num2;
	vector <bitset<30> > A;
	void bin_coef()
	{
		for (int i=0; i<=30; ++i){
			bc[i][i]=1;
			bc[i][0]=1;
		}
		for (int i=1; i<=30; ++i){
			for (int j=1; j<=30; ++j){
				bc[i][j]=bc[i-1][j-1]+bc[i-1][j];
			}
		}
	}

	void sel (int n, int town, bitset<30> bSet)
	{
		if (n==num1){
			if (bSet.count()>=num2){
				ans+=bc[bSet.count()][num2];
			}
			return;
		}
		if (town>=A.size())
			return;
		sel(n+1,town+1, bSet&A[town]);
		sel(n, town+1, bSet);
	}

	long long count(int n, int m, vector <string> county)
	{
		ans=0;
		num1=n;
		num2=m;
		bin_coef();
		A.resize(county.size());
		for (int i=0; i<county.size(); ++i){
			for (int j=0; j<county[i].size(); ++j){
				if (county[i][j]=='Y'){
					A[i][j]=1;
				}
			}
		}
		bitset <30> tmp;
		tmp.set();

		sel(0,0, tmp);
		return ans;
	}
};

//declarations
vector <string> v;
FactoryCounting solve;

void input (void){
	v.push_back( "NYYYNYYNYY");
	v.push_back(  "YNYYYYYYYN");
	v.push_back(  "YYNYYYNYYN");
	v.push_back(  "YYYNYYNYNY");
	v.push_back(  "NYYYNYYYYY");
	v.push_back(   "YYYYYNYYNY");
	v.push_back(  "YYNNYYNYYN");
	v.push_back(   "NYYYYYYNNY");
	v.push_back(  "YYYNYNYNNY");
	v.push_back(  "YNNYYYNYYN");

}

void output (void){
	cout << solve.count(3, 3, v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}