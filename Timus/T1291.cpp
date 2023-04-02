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

int gcd (int a, int b){
	while (b){
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}

struct drob{
	int x, y;
	void sok (void){
		int t=gcd(abs(x), abs(y));
		x/=t;
		y/=t;
	}
};

vector <vector <int> > A;
vector <int> s;
vector <drob> v;
queue <int> q;
int n;

void bfs (int u){
	q.push(u);
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<A[u].size(); ++i){
			int t=A[u][i];
			if (v[t].y==0){
				q.push(t);
				v[t].x=-v[u].x*s[u];
				v[t].y=v[u].y*s[t];
				v[t].sok();
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1291.in", "r", stdin);
	freopen ("T1291.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize(n);
	s.resize(n);
	v.resize(n);

	for (int i=0; i<n; ++i){
		int t;
		scanf ("%d%d", &s[i], &t);
		while (t!=0){
			A[i].push_back(t-1);
			scanf ("%d", &t);
		}
	}

	int w, e;
	scanf ("%d%d", &w, &e);

	v[w-1].x=e;
	v[w-1].y=1;

	bfs (w-1);

	for (int i=0; i<n; ++i){
		if (!v[i].y)
			v[i].y=1;
		printf ("%d/%d\n", v[i].x, v[i].y);
	}
	
	return 0;
}