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

enum {STR_RIGHT, UP_RIGHT, STR_UP, UP_LEFT, STR_LEFT, LOW_LEFT, STR_LOW, LOW_RIGHT};

class dot{
public:
	int x, y;
	dot(int a=-1001, int b=-1001) : x(a), y(b) {}
	bool operator == (const dot& t) const{
		return x==t.x && y==t.y;
	}
	bool operator < (const dot& t) const{
		if (x==t.x)
			return y<t.y;
		return x<t.x;
	}
};

int getDirect(const dot& t1, const dot& t2)
{
	if (t1.x==t2.x){
		if (t1.y>t2.y){
			return STR_LOW;
		}
		else{
			return STR_UP;
		}
	}
	if (t1.y==t2.y){
		if (t1.x>t2.x){
			return STR_LEFT;
		}
		else{
			return STR_RIGHT;
		}
	}
	if (t1.x<t2.x){
		if (t1.y<t2.y){
			return UP_RIGHT;
		}
		else{
			return LOW_RIGHT;
		}
	}
	else{
		if (t1.y<t2.y){
			return UP_LEFT;
		}
		else{
			return LOW_LEFT;
		}
	}
}

class stroke{
public:
	dot a1, a2;
	int from, to;
	int direct;
	stroke (const dot& a, const dot& b) : a1(a), a2(b), direct(getDirect(a, b)) {}
	bool operator < (const stroke& t) const{
		if (a1==t.a1)
			return a2<t.a2;
		return a1<t.a1;
	}
	bool operator != (const stroke& t){
		return from!=t.from || to!=t.to || getDirect(a1, a2)!=getDirect(t.a1, t.a2);
	}
};

set <dot> dfig, tfig;
vector <stroke> dsfig, tsfig;
int n, m;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int c=0;
	while(scanf ("%d", &n)!=EOF){
		if(c)
			printf("\n");
		++c;
		// enter right stroke
		dfig.clear();
		dsfig.clear();
		scanf ("%d", &m);
		for (int i=0; i<m; ++i){
			dot A, B;
			scanf ("%d%d%d%d", &A.x, &A.y, &B.x, &B.y);
			dfig.insert(A);
			dfig.insert(B);
			dsfig.push_back(stroke(A, B));
		}
		for (int i=0; i<m; ++i){
			int l=0;
			for (set<dot>::iterator it=dfig.begin(); it!=dfig.end(); ++it, ++l){
				if (*it==dsfig[i].a1){
					dsfig[i].from=l;
				}
				if (*it==dsfig[i].a2){
					dsfig[i].to=l;
				}
			}
		}
		sort(dsfig.begin(), dsfig.end());

		for (int k=1; k<n; ++k){
			tfig.clear();
			tsfig.clear();
			scanf ("%d", &m);
			for (int i=0; i<m; ++i){
				dot A, B;
				scanf ("%d%d%d%d", &A.x, &A.y, &B.x, &B.y);
				tfig.insert(A);
				tfig.insert(B);
				tsfig.push_back(stroke(A, B));
			}
			for (int i=0; i<m; ++i){
				int l=0;
				for (set<dot>::iterator it=tfig.begin(); it!=tfig.end(); ++it, ++l){
					if (*it==tsfig[i].a1){
						tsfig[i].from=l;
					}
					if (*it==tsfig[i].a2){
						tsfig[i].to=l;
					}
				}
			}
			sort(tsfig.begin(), tsfig.end());
			if (dfig.size()!=tfig.size() || tsfig.size()!=dsfig.size()){
				printf ("INCORRECT\n");
				continue;
			}
			bool fin=false;
			for (set<dot>::iterator it1=tfig.begin(), it2=dfig.begin(); it1!=tfig.end(); ++it1, ++it2){
				for (set<dot>::iterator itt1=tfig.begin(), itt2=dfig.begin(); itt1!=tfig.end(); ++itt1, ++itt2){
					if (it1!=itt1 && getDirect(*it1, *itt1)!=getDirect(*it2,*itt2)){
						fin=true;
						break;
					}
				}
				if(fin)
					break;
			}
			if(fin){
				printf ("INCORRECT\n");
				continue;
			}
			for (int i=0; i<dsfig.size(); ++i){
				if (tsfig[i]!=dsfig[i]){
					fin=true;
					break;
				}
			}
			if(fin){
				printf ("INCORRECT\n");
				continue;
			}
			printf ("CORRECT\n");
		}
	}
	return 0;
}