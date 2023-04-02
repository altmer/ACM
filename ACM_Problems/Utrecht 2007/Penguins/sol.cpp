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

const int INF = 1000000000;

class Ice{
public:
	double x, y;
	int pen, lim;
	double dist (const Ice& t){
		return (x-t.x)*(x-t.x)+(y-t.y)*(y-t.y);
	}
};

template <typename T>
ostream& operator << (ostream& out, vector <T>& q){
	if (q.empty())
		out << -1;
	for (int i=0; i<q.size(); ++i){
		out << q[i] << " ";
	}
	out << "\n";
	return out;
}

// flow
int num;
int S, T;
vector <vector <int> > flow;
vector <vector <int> > rez;
vector <bool> vis;
vector <int> par;
// ices
vector <Ice> v (100);
int ntest;
int n;
double d;

bool find_path(){
	vis.assign(num, false);
	par.assign(num, -1);
	queue <int> q;
	q.push(S);
	vis[S]=true;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v=0; v<num; ++v){
			if (flow[u][v] && !vis[v]){
				vis[v]=true;
				par[v]=u;
				if (v==T)
					return true;
				q.push(v);
			}
		}
	}
	return false;
}

int max_flow(){
	int ans=0;
	while (find_path()){
		int cur = T;
		int res = INF;
		while (par[cur]!=-1){
			res=min(res, flow[par[cur]][cur]);
			cur = par[cur];
		}
		ans+=res;
		cur = T;
		while (par[cur]!=-1){
			flow[par[cur]][cur]-=res;
			flow[cur][par[cur]]+=res;
			cur = par[cur];
		}
	}
	return ans;
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	scanf ("%d", &ntest);
	for (int test=0; test<ntest; ++test){
		scanf ("%d%lf", &n, &d);
		d*=d;
		num = 2*n + 1;
		S = num-1;
		int all_pen=0;
		flow.assign(num, vector <int> (num, 0));
		rez.assign(num, vector <int> (num, 0));
		// limits on ices!
		for (int i=0; i<n; ++i){
			scanf ("%lf%lf%d%d", &v[i].x, &v[i].y, &v[i].pen, &v[i].lim);
			rez[2*i][2*i+1]=v[i].lim;
			all_pen+=v[i].pen;
		}
		// source!
		for (int i=0; i<n; ++i){
			rez[S][2*i]=v[i].pen;
		}
		// between ices!
		for (int i=0; i<n; ++i){
			for (int j=i+1; j<n; ++j){
				if (v[i].dist(v[j])<=d){
					rez[2*i+1][2*j]=INF;
					rez[2*j+1][2*i]=INF;
				}
			}
		}
		vector <int> ans;
		for (T=0; T<S; T+=2){
			flow = rez;
			if (max_flow()>=all_pen){
				ans.push_back(T/2);
			}
		}
		cout << ans;
	}

	return 0;
}
