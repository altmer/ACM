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

class ReversalChain{
public:
	map<string, int> mem;
	int rec (string rev, string init, string goal){
		int ret=1e+9;
		int len=init.length();
		if (init==goal)
			return 0;

		if (init.length()==1)
			return ret;

		if (mem.count(rev+init+goal)!=0)
			return mem[rev+init+goal];

		if (init[0]==goal[0]){
			ret=min(ret, rec("", init.substr(1, len-1), goal.substr(1, len-1)));
		}
		if (init[len-1]==goal[len-1]){
			ret=min(ret, rec("", init.substr(0, len-1), goal.substr(0, len-1)));
		}
		if(rev.empty()){
			string s=init;
			reverse(s.begin(), s.end());
			ret=min(ret, 1+rec("!",s, goal));
		}
		mem[rev+init+goal]=ret;
		return ret;
	}


	int minReversal(string init, string goal){
		int res=rec("",init, goal);
		return res==1e+9 ? -1 : res;
	}
};

//declarations
ReversalChain solve;
string s1, s2;

void input (void){
	getline(cin, s1);
	getline(cin, s2);
}

void output (void){
	cout << solve.minReversal(s1, s2);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}