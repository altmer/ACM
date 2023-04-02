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

enum en{UNDETER, WIN, LOSE};
int n, k;

class position
{
public:
	vector <int> grid;
	position():grid(){}
	position(const string& s)
	{
		int cnt=0;
		for (int i=0; i<s.size(); ++i){
			if (s[i]=='O')
				++cnt;
			else{
				if (cnt>=k && cnt<2*k){
					grid.push_back(k);
				}
				else if(cnt>=2*k){
					grid.push_back(cnt);
				}
				cnt=0;
			}
		}
		if (cnt>=k && cnt<2*k){
			grid.push_back(k);
		}
		else if(cnt>=2*k){
			grid.push_back(cnt);
		}
	}
};

string s;
vector <position> pos;
vector <int> win;
vector <set <int> > A;

void gen_tree (int u)
{
	queue<int> q;
	q.push(u);
	// determining next move
	while (!q.empty()){
		u=q.front();
		q.pop();
		if (!A[u].empty())
			continue;
		for (int i=0; i<pos[u].grid.size(); ++i){
			for (int j=0; j<=pos[u].grid[i]-k; ++j){
				position npos;
				if (j>=k && j<2*k){
					npos.grid.push_back(k);
				}
				else if (j>=2*k){
					npos.grid.push_back(j);
				}
				int ost=pos[u].grid[i]-j-k;
				if (ost>=k && ost<2*k){
					npos.grid.push_back(k);
				}
				else if (ost>=2*k){
					npos.grid.push_back(ost);
				}
				for (int k=0; k<i; ++k){
					npos.grid.push_back(pos[u].grid[k]);
				}
				for (int k=i+1; k<pos[u].grid.size(); ++k){
					npos.grid.push_back(pos[u].grid[k]);
				}
				sort(npos.grid.begin(), npos.grid.end());
				int num=-1;
				for (int k=0; k<pos.size(); ++k){
					if (npos.grid==pos[k].grid){
						num=k;
						break;
					}
				}
				if (num==-1){
					pos.push_back(npos);
					A.push_back(set<int>());
					if (npos.grid.empty())
						win.push_back(LOSE);
					else
						win.push_back(UNDETER);
					num=pos.size()-1;
				}
				A[u].insert(num);
				q.push(num);
			}
		}
	}
}

int dfs (int u)
{
	if (win[u]!=UNDETER)
		return win[u];
	for (set<int>::iterator it=A[u].begin(); it!=A[u].end(); ++it){
		if (dfs(*it)==LOSE){
			win[u]=WIN;
			return win[u];
		}
	}
	win[u]=LOSE;
	return win[u];
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("crossgam.in", "r", stdin);
	freopen ("crossgam.out", "w", stdout);
#endif

	scanf ("%d%d\n", &n, &k);
	getline(cin, s);
	pos.push_back(position(s));
	if (pos[0].grid.empty()){
		printf ("0");
		return 0;
	}
	win.push_back(UNDETER);
	A.push_back(set<int>());
	gen_tree(0);
	if (dfs(0)==WIN)
		printf ("1");
	else
		printf ("2");
	return 0;
}