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

struct vert{
	double x, y;
	double dist (vert t){
		return sqrt ( (x-t.x)*(x-t.x) + (y-t.y)*(y-t.y) );
	}
	vert operator - (vert t){
		vert u;
		u.x=x-t.x;
		u.y=y-t.y;
		return u;
	}
	double vp (vert t){
		return x*t.y-y*t.x;
	}
	bool operator < (vert t){
		if (x==t.x)
			return y<t.y;
		return x<t.x;
	}
};

vector <vert> v;
vector <bool> col;
double ans;
int n;

void solve (int k){
	double cur;
	vert op, v1, v2;

	for (int i=0; i<n; ++i){
		col[i]=false;
	}

	for (int i=k+1; i<n; ++i){
		if (!col[i]){
			col[i]=true;
			op=v[i];
			cur=v[k].dist(op);
			for (int j=i+1; j<n; ++j){
				v1=op-v[k];
				v2=v[j]-v[k];
				if (v1.vp(v2)==0){
					col[j]=true;
					cur=min(cur, v[k].dist(v[j]));
				}
			}
			ans+=cur;
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1588.in", "r", stdin);
	freopen ("T1588.out", "w", stdout);
#endif

	scanf ("%d", &n);

	v.resize(n);
	col.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%lf%lf", &v[i].x, &v[i].y);
	}

	sort (v.begin(), v.end());

	for (int i=0; i<n; ++i){
		solve (i);
	}

	printf ("%0.0lf", ans);

	return 0;
}