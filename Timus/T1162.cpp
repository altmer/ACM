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

struct edge{
	int dest;
	double rate, com;
};

vector <vector <edge> > A;
vector <double> dist;
int st, n, m;
double val;

bool bellman_ford (void){
	bool ch=false;
	for (int k=0; k<n; ++k){
		ch=false;
		for (int u=0; u<n; ++u){
			if (dist[u]!=0){
				for (int i=0; i<A[u].size(); ++i){
					int v=A[u][i].dest;
					double p=(dist[u]-A[u][i].com)*A[u][i].rate;
					if (p>dist[v]){
						ch=true;
						dist[v]=p;
					}
				}
			}
		}
	}
	return ch;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1162.in", "r", stdin);
	freopen ("T1162.out", "w", stdout);
#endif

	scanf ("%d%d%d%lf", &n, &m, &st, &val);
	A.resize(n);
	dist.resize(n);
	st--;
	dist[st]=val;
	for (int i=0; i<m; ++i){
		int q, b;
		double rab, cab, rba, cba;
		edge t;
		scanf ("%d%d%lf%lf%lf%lf", &q, &b, &rab, &cab, &rba, &cba);
		t.dest=b-1;
		t.com=cab;
		t.rate=rab;
		A[q-1].push_back(t);
		t.dest=q-1;
		t.com=cba;
		t.rate=rba;
		A[b-1].push_back(t);
	}

	bool res=bellman_ford();
	if (res)
		printf ("YES");
	else
		printf ("NO");
	
	return 0;
}