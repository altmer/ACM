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

vector <pair<int, int> > ans;

class Graph{
protected:
	vector <int> inc;
	vector <vector <int> > A;
	int n, m;
public:
	Graph()
	{
		scanf ("%d%d", &n, &m);
		inc.assign(n, 0);
		A.resize(n);
		for (int i=0; i<m; ++i){
			int a, b;
			scanf ("%d%d", &a, &b);
			a--; b--;
			inc[a]++; inc[b]++;
			A[a].push_back(b);
			A[b].push_back(a);
		}
	}
	bool run()
	{
		bool res=false;
		for (int i=0; i<n; ++i){
			if (inc[i]==1){
				int to=-1;
				for (int j=0; j<A[i].size(); ++j){
					if (inc[A[i][j]]>0){
						to=A[i][j];
						break;
					}
				}
				for (int j=0;j<A[to].size(); ++j){
					inc[A[to][j]]--;
				}
				inc[to]=0;
				ans.push_back(make_pair(i+1, to+1));
				res=true;
			}
		}
		return res;
	}
};

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1389.in", "r", stdin);
	freopen ("T1389.out", "w", stdout);
#endif

	ans.reserve(1000000);
	Graph G;
	while (G.run());

	printf ("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
	{
		printf ("%d %d\n", ans[i].first, ans[i].second);
	}
		
	return 0;
}