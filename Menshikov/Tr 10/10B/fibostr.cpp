#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
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

int n;
string s;
vector <string> f, h, t;
vector <int> v;

int hash_search (const string& tem, const string& s)
{
	int ret=0;
	if (tem.size()<s.size()){
		return 0;
	}
	else if (tem.size()==s.size()){
		return int(tem==s);
	}

	for (int i=0; i<tem.size(); ++i){
		if (tem[i]==s[0]){
			int j=0;
			while (j<s.size() && tem[i+j]==s[j])
				++j;
			if (j==s.size())
				++ret;
		}
	}
	return ret;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("fibostr.in", "r", stdin);
	freopen ("fibostr.out", "w", stdout);
#endif
	
	f.push_back("A");
	f.push_back("B");
	
	scanf ("%d\n", &n);

	getline (cin, s);

	for (int i=2; i<=min(n,10); ++i){
		f.push_back(f[i-1]+f[i-2]);
	}

	v.resize(f.size());

	for (int i=0; i<v.size(); ++i){
		v[i]=hash_search(f[i], s);
	}
	if (n<=10){
		printf ("%d", v[n-1]);
		return 0;
	}

	h.resize(f.size());
	t.resize(f.size());
	h[9]=f[9].substr(0, s.size()-1);
	t[9]=f[9].substr(f[9].size()-s.size()+1);
	h[10]=f[10].substr(0, s.size()-1);
	t[10]=f[10].substr(f[10].size()-s.size()+1);
	
	for (int i=11; i<n; ++i){
		v.push_back(v[i-1]+v[i-2]+hash_search(t[i-1]+h[i-2], s));
		h.push_back(h[i-1]);
		t.push_back(t[i-2]);
	}

	printf ("%d", v[n-1]);

	return 0;
}