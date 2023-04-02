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
#include <list>
#include <set>

using namespace std;
const int lim=1000000;
class Necrolog{
public:
	vector <string> templ;
	vector <bool> col;
	string ans;
	bool fin;
	void run(int u){
		if (ans.size()>lim)
			return;
		col[u]=true;
		for (int i=0; i<templ[u].size(); ++i){
			if (!fin || ans.size()>lim)
				return;
			if (templ[u][i]=='*'){
				++i;
				int wh=templ[u][i]-'0'-1;
				if (!col[wh])
					run(wh);
				else{
					fin=false;
					return;
				}
			}
			else{
				ans+=templ[u][i];
			}
		}
		col[u]=false;
	}	
};

Necrolog solve;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1253.in", "r", stdin);
	freopen ("T1253.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	string tmp, s;
	int i=0;
	solve.templ.reserve(n);
	while (i<n){
		getline (cin, s);
		if (!tmp.empty())
			tmp+="\n";
		tmp+=s;
		if (*(--s.end())=='#'){
			++i;
			tmp.erase((int)tmp.size()-1);
			solve.templ.push_back(tmp);
			tmp="";
		}
	}
	solve.ans.reserve(2*lim);
	solve.fin=true;
	solve.col.resize(solve.templ.size());
	solve.run(0);

	if (solve.fin && solve.ans.size()<=lim){
		cout << solve.ans << endl;
	}
	else{
		cout << "#\n";
	}

	return 0;
}