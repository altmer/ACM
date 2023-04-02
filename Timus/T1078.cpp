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
	int a, b, n;
	bool operator < (segm t){
		return b-a>t.b-t.a;
	}
	bool incl (segm t){
		return a>t.a && b<t.b;
	}
};

int n, ans=0, num=-1;
vector <int> c, p;
vector <segm> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1078.in", "r", stdin);
	freopen ("T1078.out", "w", stdout);
#endif

	scanf ("%d", &n);
	c.resize(n);
	p.resize(n);
	v.resize(n);

	for (int i=0; i<n; ++i){
		p[i]=-1;
		c[i]=1;
		scanf ("%d%d", &v[i].a, &v[i].b);
		v[i].n=i+1;
	}
		
	sort (v.begin(), v.end());

	for (int i=1; i<n; ++i){
		for (int j=i-1; j>=0; --j){
			if (v[i].incl(v[j]) && c[j]+1>c[i]){
				c[i]=c[j]+1;
				p[i]=j;
			}
		}
	}

	for (int i=0; i<n; ++i){
		if (c[i]>ans){
			ans=c[i];
			num=i;
		}
	}

	printf ("%d\n", ans);
	int t=num;
	while (t!=-1){
		printf ("%d ", v[t].n);
		t=p[t];
	}

	return 0;
}