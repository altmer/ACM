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
#include <limits>
#include <map>
#include <set>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

class segm{
public:
	int l, r, num;
	bool b_use;
	bool operator < (const segm& t) const{
		if(l==t.l)
			return r<t.r;
		return l<t.l;
	}
};

class cmp{
public:
	bool operator () (segm* const& t1, segm* const& t2) const{
		if(t1->r==t2->r)
			return t1->l<t2->l;
		return t1->r<t2->r;
	}
};

int n, m, k, p;
vector <segm> v;
multiset <segm*, cmp> s;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1424.in", "r", stdin);
	freopen ("T1424.out", "w", stdout);
#endif

	scanf ("%d%d%d%d", &n, &m, &k, &p);
	v.resize(k);

	for (int i=0; i<k; ++i){
		scanf ("%d%d", &v[i].l, &v[i].r);
		v[i].l--; v[i].r--;
		v[i].num=i+1;
	}

	sort(v.begin(), v.end());
	
	for (int i=0; i<k; ++i){
		while (!s.empty() && (*s.begin())->r<=v[i].l){
			(*s.begin())->b_use=true;
			s.erase(s.begin());			
		}
		if(s.size()<m){
			s.insert(&v[i]);
		}
		else{
			if((*(--s.end()))->r>v[i].r){
				s.erase((--s.end()));
				s.insert(&v[i]);
			}
		}
	}

	while(!s.empty()){
		(*s.begin())->b_use=true;
		s.erase(s.begin());		
	}

	vector <int> ans;
	ans.reserve(k);
	for (int i=0; i<k; ++i){
		if(v[i].b_use){
			ans.push_back(v[i].num);
		}
	}

	printf ("%d\n", int(ans.size())*p);
	for (int i=0; i<ans.size(); ++i){
		printf ("%d ", ans[i]);
	}

	return 0;
}