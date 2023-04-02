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

vector <bool> A;
vector <int> s;
vector <vector <int> > par;

void dfs (int u){
	for (int i=0; i<par[u].size(); ++i){
		int v=par[u][i];
		s[v]++;
		dfs(v);
	}
}

class CorporationSalary{
public:
	long long totalSalary(vector <string> r){

		// vector <vert> s;

		A.resize(r.size());
		par.resize(r.size());
		s.resize(r.size());
		for (int i=0; i<r.size(); ++i){
			for (int j=0; j<r[i].size(); ++j){
				if (r[i][j]=='Y'){
					A[i]=true;
					par[j].push_back(i);;
				}
			}
		}
		for (int i=0; i<A.size(); ++i){
			if (!A[i]){
				s[i]=1;
				dfs(i);
			}
		}
		int res=0;
		for (int i=0; i<s.size(); ++i){
			res+=s[i];
		}
		return res;
	}
};

//declarations
CorporationSalary solve;
int n;
string line;
vector <string> o;

void input (void){
	scanf ("%d\n", &n);
	for (int i=0; i<n; ++i){
		getline (cin, line);
		o.push_back(line);
	}
}

void output (void){
	cout << solve.totalSalary(o);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}