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

struct coord{
	long double x, y;
};

int n;
long double v, u;
queue <int> q;
vector <coord> b;
vector <long double> d;
vector <bool> color;
vector <int> p;
stack <int> ans;
vector <vector <long double> > A;

double dist (coord a, coord b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void init (void){
	scanf ("%lf%lf%d", &v, &u, &n);
	b.resize(n+2);
	d.resize(n+2);
	p.resize(n+2);
	A.resize(n+2);
	color.resize(n+2);
	A[0].resize(n+2);
	A[n+1].resize(n+2);
	for (int i=1; i<=n; ++i){
		scanf ("%lf%lf", &b[i].x, &b[i].y);
		A[i].resize(n+2);
	}

	int q=0, w=0;
	while (true){
		scanf ("%d%d", &q, &w);
		if (q!=0 && w!=0){
			double t=dist(b[q], b[w])/u;
			A[q][w]=t;
			A[w][q]=t;
		}
		else
			break;
	}

	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (i!=j && A[i][j]==0){
				double t=dist(b[i], b[j])/v;
				A[i][j]=t;
				A[j][i]=t;
			}
		}
	}

	scanf ("%lf%lf%lf%lf", &b[0].x, &b[0].y, &b[n+1].x, &b[n+1].y);

	for (int i=1; i<=n+1; ++i){
		double t=dist(b[0], b[i])/v;
		A[0][i]=t;
		A[i][0]=t;
		t=dist(b[n+1], b[i])/v;
		A[n+1][i]=t;
		A[i][n+1]=t;
	}
}

void bfs (int u){
	q.push(u);
	color[u]=true;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=0; i<=n+1; ++i){
			double t=d[u]+A[u][i];
			if (color[i]==false || d[i]>t){
				color[i]=true;
				p[i]=u;
				d[i]=t;
				q.push(i);
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1205.in", "r", stdin);
	freopen ("T1205.out", "w", stdout);
#endif

	init ();

	bfs(0);

	printf ("%.6lf\n", d[n+1]);

	int j=p[n+1];
	while (j!=0){
		ans.push(j);
		j=p[j];
	}

	printf ("%d ", ans.size());
	while (!ans.empty()){
		printf ("%d ", ans.top());
		ans.pop();
	}

	return 0;
}