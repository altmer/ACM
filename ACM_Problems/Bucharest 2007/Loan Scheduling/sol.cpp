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

struct loan{
	int p, d;
	loan():p(0),d(0){}
	loan(int _p, int _d):p(_p),d(_d){}
	bool operator < (const loan& t)const{
		if (t.p==p)
			return d<t.d;
		return p>t.p;
	}
};

bool cmp(const loan& t1, const loan& t2)
{
	if (t1.d==t2.d)
		return t1.p>t2.p;
	return t1.d>t2.d;
}

int n, L;
multiset <loan> q;
vector <loan> v;

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	while (scanf ("%d%d", &n, &L)!=EOF){
		
		int ans=0;
		q.clear();
		v.resize(max(n, static_cast<int>(v.size())));
		for (int i=0; i<n; ++i){
			scanf ("%d%d", &v[i].p, &v[i].d);
		}
		sort(v.begin(), v.begin()+n, cmp);
		int cur_day=1e+5;
		int cur_loan=0;
		for (int i=0; i<n; ++i){
			if (v[i].d!=cur_day){
				while (cur_loan && !q.empty()){
					ans+=q.begin()->p;
					q.erase(q.begin());
					--cur_loan;
				}
				int stor=(cur_day-v[i].d-1)*L;
				while (stor && !q.empty()){
					ans+=q.begin()->p;
					q.erase(q.begin());
					--stor;
				}
				cur_day=v[i].d;
				cur_loan=L;
			}
			q.insert(v[i]);
			if (cur_loan){
				ans+=q.begin()->p;
				q.erase(q.begin());
				--cur_loan;
			}
		}
		while (cur_loan && !q.empty()){
			ans+=q.begin()->p;
			q.erase(q.begin());
			--cur_loan;
		}
		int stor=(cur_day)*L;
		while (stor && !q.empty()){
			ans+=q.begin()->p;
			q.erase(q.begin());
			--stor;
		}
		printf ("%d\n", ans);
	}

	return 0;
}