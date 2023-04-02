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

struct edge{
	int st, end, len;
	edge():st(-1), end(-1), len(0){}
	edge (int x, int y, int z) : st(x), end(y), len(z){}
	bool operator < (const edge& t)const{
		return len<t.len;
	}
};

map <string, int> num;
vector <int> color;
vector <edge> E;
int ntest;
int n, m;


int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	scanf ("%d", &ntest );

	for (int test=0; test<ntest; ++test){
		scanf ("%d%d", &n, &m);
		color.assign(n, 0);
		num.clear();
		E.clear();
		int cnt=0;
		for (int i=0; i<m; ++i){
			string s1, s2;
			int L;
			cin >> s1 >> s2 >> L;
			if (!num.count(s1))
				num[s1]=cnt++;
			if (!num.count(s2))
				num[s2]=cnt++;
			E.push_back(edge(num[s1],num[s2],L));
		}
		sort(E.begin(), E.end());
		int col=1;
		int ans=0;
		for (int i=0; i<E.size(); ++i){
			if (E[i].st==E[i].end)
				continue;
			if (color[E[i].st]==0 && color[E[i].end]==0){
				color[E[i].st]=color[E[i].end]=col++;
				ans+=E[i].len;
			}
			else if (color[E[i].st]==0){
				color[E[i].st]=color[E[i].end];
				ans+=E[i].len;
			}
			else if (color[E[i].end]==0){
				color[E[i].end]=color[E[i].st];
				ans+=E[i].len;
			}
			else if (color[E[i].st]!=color[E[i].end]){
				int top=color[E[i].st];
				for (int j=0; j<n; ++j){
					if (color[j]==top)
						color[j]=color[E[i].end];
				}
				ans+=E[i].len;
			}
		}
		printf ("%d\n", ans);
		if (test!=ntest-1)
			printf ("\n");
	}

	return 0;
}