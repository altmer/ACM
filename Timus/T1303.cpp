#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct segm{
	int L, R;
	bool operator < (segm t){
		if (L==t.L)
			return R>t.R;
		return L<t.L;
	}
};

int m, r;
bool cand;
segm t;
vector <segm> v, ans;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1303.in", "r", stdin);
	freopen ("T1303.out", "w", stdout);
#endif

	scanf ("%d", &m);

	do{
		scanf ("%d%d", &t.L, &t.R);
		if (t.L!=t.R)
			v.push_back(t);
	}
	while (t.L!=t.R || t.L!=0 || t.R!=0);

	sort (v.begin(), v.end());

	for (int i=0; i<v.size(); ++i){
		if (v[i].L<=0){
			if (v[i].R>r){
				cand=true;
				t=v[i];
				r=v[i].R;
			}
		}
		else{
			if (ans.empty()){
				ans.push_back(t);
				cand=false;
			}
			if (r>=m)
				break;
			if (v[i].L>r){
				if (!cand)
					break;
				cand=false;
				ans.push_back(t);
				r=t.R;
				--i;
			}
			else{
				if (!cand){
					if (v[i].R>r){
						cand=true;
						t=v[i];
					}
				}
				else if (v[i].R>t.R){
						t=v[i];
				}
			}
		}
	}

	if(cand){
		ans.push_back(t);
		r=t.R;
	}

	if (r>=m){
		printf ("%d\n", ans.size());
		for (int i=0; i<ans.size(); ++i){
			printf ("%d %d\n", ans[i].L, ans[i].R);
		}
	}
	else
		printf ("No solution");

	return 0;
}