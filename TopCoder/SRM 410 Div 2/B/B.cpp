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

class AddElectricalWires{
public:
	vector <string> G;
	vector <int> numGR;
	vector <int> color;
	void dfs (int u, int col){
		color[u]=col;
		numGR[col-1]++;
		for (int i=0; i<G[u].size(); ++i){
			if (!color[i] && G[u][i]=='1'){
				dfs(i, col);
			}
		}
	}
	int maxNewWires(vector <string> A, vector <int> v){
		G=A;
		int ans=0;
		color.resize(A.size());
		numGR.resize(v.size());
		for (int i=0; i<v.size(); ++i){
			dfs(v[i], i+1);
		}
		int maxGR=(max_element(numGR.begin(), numGR.end()))-numGR.begin();
		for (int i=0; i<color.size(); ++i){
			if (!color[i]){
				color[i]=maxGR+1;
			}
			for (int j=0; j<A[i].size(); ++j){
				if (j!=i && color[j]==color[i] && A[i][j]=='0'){
					A[i][j]='1';
					A[j][i]='1';
					ans++;
				}
			}
		}
		return ans;
	}
};

//declarations
AddElectricalWires solve;
vector <string> v;
vector <int> w;

void input (void){
	v.push_back("0100000");
	v.push_back("1010000");
	v.push_back("0101000");
	v.push_back("0010000");
	v.push_back("0000010");
	v.push_back("0000100");
	v.push_back("0000000");
	w.push_back(0);
}

void output (void){
	cout << solve.maxNewWires(v, w);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}