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

string ord = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
int cost[500];

class lett{
public:
	char sym;
	int pos;
	bool operator < (const lett& t) const{
		if (cost[sym]==cost[t.sym])
			return pos<t.pos;
		return cost[sym]<cost[t.sym];
	}
};

string s;
string ans;
vector <lett> v;
vector <bool> c;
int st;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1322.in", "r", stdin);
	freopen ("T1322.out", "w", stdout);
#endif

	for (int i=0; i<ord.size(); ++i){
		cost[ord[i]]=i;
	}

	scanf ("%d\n", &st);
	--st;
	s.reserve(100000);

	char ch;
	while (scanf("%c", &ch)!=EOF && ch!='\n')
		s+=ch;

	ans.reserve(s.size());
	v.resize(s.size());
	c.resize(s.size());

	for (int i=0; i<s.size(); ++i){
		v[i].sym=s[i];
		v[i].pos=i;
	}

	sort (v.begin(), v.end());

	int k=st;
	do {
		c[k]=true;
		ans+=v[k].sym;
		k=v[k].pos;
	} while (!c[k]);

	if (ans.size()!=s.size()){
		int lim = (int)s.size()/(int)ans.size();
		string tmp = ans;
		for (int i=0; i<lim-1; ++i)
			ans+=tmp;
	}

	cout << ans;

	return 0;
}