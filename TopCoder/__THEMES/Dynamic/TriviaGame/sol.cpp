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

class TriviaGame{
public:
	vector <vector <int> > A;
	vector <int> v, b;
	int cnt;

	int rec (int cur, int tok)
	{
		if (cur==v.size()){
			return 0;
		}
		if (A[cur][tok]>-1){
			return A[cur][tok];
		}
		int answrong = rec(cur+1,tok);
		int ansright;
		if (tok+1==cnt){
			ansright=rec(cur+1,0)+v[cur]+b[cur];
		}
		else{
			ansright=rec(cur+1,tok+1)+v[cur];
		}
		return A[cur][tok]=max(answrong,ansright);
	}

	int maximumScore(vector<int> points, int tokensNeeded, vector<int> bonuses){
		v=points;
		b=bonuses;
		cnt=tokensNeeded;
		A.assign(points.size(), vector <int> (points.size(), -1));
		return rec(0,0);
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