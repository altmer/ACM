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

struct jedi{
	string name;
	int a, b, c;
	bool win (jedi t){
		return (a>t.a && b>t.b) || (a>t.a && c>t.c) || (c>t.c && b>t.b);
	}
};

int n;
vector <vector <int> > A;
vector <jedi> p;
vector <bool> col;

void dfs (int u){
	col[u]=true;
	for (int i=0; i<A[u].size(); ++i){
		if (!col[A[u][i]])
			dfs(A[u][i]);
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1218.in", "r", stdin);
	freopen ("T1218.out", "w", stdout);
#endif

	cin >> n;
	A.resize(n);
	p.resize(n);
	col.resize(n);
	for (int i=0; i<n; ++i){
		cin >> p[i].name >> p[i].a >> p[i].b >> p[i].c;
		for (int j=i-1; j>=0; --j){
			if (p[i].win(p[j])){
				A[i].push_back(j);
			}
			else{
				A[j].push_back(i);
			}
		}
	}

	for (int i=0; i<n; ++i){
		for (int i=0; i<n; ++i)
			col[i]=false;
		dfs (i);
		bool res=true;
		for (int i=0; i<n; ++i){
			if (!col[i]){
				res=false;
				break;
			}
		}
		if (res)
			cout << p[i].name << "\n";
	}
	
	
	return 0;
}