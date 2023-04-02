#include <iostream>
#include <sstream>
#include <cstdio>
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
#include <map>
#include <set>
using namespace std;

class edge{
public:
	int dest;
	bool used;
	edge(int a) : dest(a), used(false) {}
};

int n,m, st=-1;
vector <vector <edge> > A(10010);
vector <int> in(10010), out(10010);
stack <int> s, c;

void euler()
{
	s.push(st);
	while (!s.empty()){
		int u = s.top();
		bool found=false;
		for (int i=0; i<A[u].size(); ++i){
			if (!A[u][i].used){
				s.push(A[u][i].dest);
				A[u][i].used=true;
				found=true;
				break;
			}
		}
		if (!found){
			c.push(u);
			s.pop();
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1137.in", "r", stdin);
	freopen ("T1137.out", "w", stdout);
#endif

	scanf ("%d", &n);
	for (int i=0; i<n; ++i){
		int prev, cur;
		scanf ("%d%d", &m, &prev);
		if (st==-1)
			st=prev;
		for (int j=1; j<=m; ++j){
			scanf ("%d", &cur);
			A[prev].push_back(edge(cur));
			out[prev]++;
			in[cur]++;
			prev=cur;
		}
	}

	for (int i=0; i<in.size(); ++i){
		if (in[i]!=out[i]){
			printf ("0\n");
			return 0;
		}
	}
	euler();

	printf ("%d ", c.size()-1); 
	while (!c.empty()){
		printf ("%d ", c.top());
		c.pop();
	}

	return 0;
}