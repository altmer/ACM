#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Marketing{
public:
	vector <vector <int> > A;
	vector <int> lev;
	bool bfs (int u){
		queue <int> q;
		lev[u]=1;
		q.push(u);
		while (!q.empty()){
			u=q.front();
			q.pop();
			for (int i=0; i<A[u].size(); ++i){
				int v=A[u][i];
				if (!lev[v]){
					q.push(v);
					lev[v]=3-lev[u];
				}
				else if (lev[v]!=3-lev[u]){
					return false;
				}
			}
		}
		return true;
	}

	long long howMany(vector <string> com){
		A.resize(com.size());
		lev.resize(com.size());
		long long res=1;
		for (int i=0; i<com.size(); ++i){
			istringstream str_in (com[i]);
			int u;
			while (str_in >> u){
				A[u].push_back(i);
				A[i].push_back(u);
			}
		}
		for (int i=0; i<A.size(); ++i){
			if (!lev[i]){
				if (bfs(i))
					res<<=1;
				else
					return -1;
			}
		}
		return res;
	}
};

//declarations
vector <string> A;
Marketing solve;

void input (void){
	int n;
	scanf ("%d\n", &n);
	A.resize(n);
	for (int i=0; i<n; ++i){
		getline (cin, A[i]);
	}
}

void output (void){
	cout << solve.howMany(A);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}