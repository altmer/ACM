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
	double x, y, z, r, num;
	bool intersect (vert t){
		return sqrt ( (x-t.x)*(x-t.x) + (y-t.y)*(y-t.y) + (z-t.z)*(z-t.z))<r+t.r;
	}

	bool operator < (vert t){
		if (x==t.x){
			if (y==t.y)
				return z<t.z;
			return y<t.y;
		}
		return x<t.x;
	}	
};

int cnt, n;
vector <vector <int> > A, arch;
vector <vert> p;
vector <bool> col;


void dfs (int u){
	col[u]=true;
	arch[cnt].push_back(u);
	for (int i=0; i<A[u].size(); ++i){
		if (!col[A[u][i]])
			dfs (A[u][i]);
	}

}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1392.in", "r", stdin);
	freopen ("T1392.out", "w", stdout);
#endif

	scanf ("%d", &n);

	A.resize(n);
	arch.resize(n);
	p.resize(n);
	col.resize(n);

	for (int i=0; i<n; ++i){
		scanf ("%lf%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z, &p[i].r);
		p[i].num=i;
	}

	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			if (p[i].intersect(p[j])){
				A[i].push_back(j);
				A[j].push_back(i);
			}
		}

	}

	for (int i=0; i<n; ++i){
		if (!col[i]){
			dfs(i);
			sort (arch[cnt].begin(), arch[cnt].end());
			++cnt;
		}
	}
	
	int i=0;

	while (i<n && !arch[i].empty()){
		for (int j=0; j<arch[i].size()-1; ++j){
			printf ("%d, ", arch[i][j]);
		}
		printf ("%d\n", arch[i][arch[i].size()-1]);
		++i;
	}
		
	return 0;
}