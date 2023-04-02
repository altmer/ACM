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

int n,m, l, K;

class Segm{
public:
	int L, R;
	Segm() : L(0), R(0) {}
	Segm(int x, int y) : L(x), R(y) {}
	bool empty() const {
		return L==R;
	}
	bool operator < (const Segm& t) const{
		if (t.L==L)
			return R>t.R;
		return L<t.L;
	}
};

class Ship{
public:
	int x1, y1, x2, y2;
	Ship() : x1(0), x2(0), y1(0), y2(0){}
	Ship (int _x1,int _y1, int len, char w) : x1(_x1),y1(_y1){
		if (w=='V'){
			y2=y1;
			x2=x1+len-1;
		}
		else{
			y2=y1+len-1;
			x2=x1;
		}
	}
	Segm CrossHor (int x){
		if (x1==x2){
			if (abs(x-x1)<=1){
				return Segm(max(y1-1,0), min(m-1, y2+1));
			}
			else{
				return Segm();
			}
		}
		else{
			if (x>=x1-1 && x<=x2+1){
				return Segm(max(y1-1,0), min(m-1, y1+1));
			}
			else{
				return Segm();
			}
		}
	}
	Segm CrossVer (int y){
		if (y1==y2){
			if (abs(y-y1)<=1){
				return Segm(max(x1-1,0), min(n-1, x2+1));
			}
			else{
				return Segm();
			}
		}
		else{
			if (y>=y1-1 && y<=y2+1){
				return Segm(max(x1-1,0), min(n-1, x1+1));
			}
			else{
				return Segm();
			}
		}
	}
};

int ans;
vector <Ship> v;
vector <Segm> s;
vector <Segm>::iterator it;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1212.in", "r", stdin);
	freopen ("T1212.out", "w", stdout);
#endif

	scanf ("%d%d%d\n", &n, &m, &l);
	v.reserve(l);
	for (int i=0; i<l; ++i){
		int x1, y1, len;
		char ch;
		scanf ("%d %d %d %c\n", &y1, &x1, &len, &ch);
		v.push_back(Ship(x1-1, y1-1, len, ch));
	}
	scanf ("%d", &K);

	// horizontals

	for (int i=0; i<n; ++i){
		s.clear();
		for (int j=0; j<l; ++j){
			Segm t=v[j].CrossHor(i);
			if (!t.empty()){
				s.push_back(t);
			}
		}
		s.push_back(Segm(m, m+1));
		sort(s.begin(), s.end());
		int cur=0; // first free
		for (it=s.begin(); it!=s.end(); ++it){
			if (it->L > cur){
				ans += max (0, (it->L-cur) - (K-1) );
				cur = it->R + 1;
			}
			else{
				cur=max(cur, it->R+1);
			}
		}
	}
	if (K!=1){
		for (int i=0; i<m; ++i){
			s.clear();
			for (int j=0; j<l; ++j){
				Segm t=v[j].CrossVer(i);
				if (!t.empty()){
					s.push_back(t);
				}
			}
			s.push_back(Segm(n, n+1));
			sort(s.begin(), s.end());
			int cur=0; // first free
			for (it=s.begin(); it!=s.end(); ++it){
				if (it->L > cur){
					ans += max (0, (it->L-cur) - (K-1) );
					cur = it->R + 1;
				}
				else{
					cur=max(cur, it->R+1);
				}
			}
		}
	}

	printf ("%d\n", ans);

	return 0;
}