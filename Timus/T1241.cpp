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

struct cut{
	int x1, y1, x2, y2;
};

vector <cut> v;
vector <vector <int> > L;
vector <bool> done, col;
vector <int> d;
int m,n,k;
int ans;
int cnt=1;
int A[101][101];

void mark_hor (int x, int y1, int y2)
{
	for (int i=y1; i<=y2; ++i){
		A[i][x]++;
		if (A[i][x]>1 && A[i][x]<1000){
			A[i][x]+=cnt*1000;
			++cnt;
		}
	}
}

void mark_ver (int y, int x1, int x2)
{
	for (int i=x1; i<=x2; ++i){
		A[y][i]++;
		if (A[y][i]>1 && A[y][i]<1000){
			A[y][i]+=cnt*1000;
			++cnt;
		}
	}
}

void mark_diag1 (int x1, int y1, int x2, int y2)
{
	for (int i=x1, j=y1; i<=x2; ++i, ++j){
		A[j][i]++;
		if (A[j][i]>1 && A[j][i]<1000){
			A[j][i]+=cnt*1000;
			++cnt;
		}
	}
}

void mark_diag2 (int x1, int y1, int x2, int y2)
{
	for (int i=x1, j=y1; i>=x2; --i, ++j){
		A[j][i]++;
		if (A[j][i]>1 && A[j][i]<1000){
			A[j][i]+=cnt*1000;
			++cnt;
		}
	}
}

void init (void)
{
	scanf ("%d%d%d", &m, &n, &k);
	m*=2;
	n*=2;
	for (int i=0; i<=m; ++i){
		A[0][i]=1;
		A[n][i]=1;
	}
	for (int i=0; i<=n; ++i){
		A[i][0]=1;
		A[i][m]=1;
	}

	v.resize(k);
	for (int i=0; i<k; ++i){
		scanf ("%d%d%d%d", &v[i].x1, &v[i].y1, &v[i].x2, &v[i].y2);
		v[i].x1*=2;
		v[i].y1*=2;
		v[i].x2*=2;
		v[i].y2*=2;
		if (v[i].x1==v[i].x2){
			mark_hor (v[i].x1, min(v[i].y1, v[i].y2), max(v[i].y1, v[i].y2));
		}
		else if (v[i].y1==v[i].y2){
			mark_ver (v[i].y1, min(v[i].x1, v[i].x2), max(v[i].x1, v[i].x2));
		}
		else{
			if (v[i].x2>v[i].x1){
				if (v[i].y2>v[i].y1){
					mark_diag1 (v[i].x1, v[i].y1, v[i].x2, v[i].y2);
				}
				else{
					mark_diag2 (v[i].x2, v[i].y2, v[i].x1, v[i].y1);
				}
			}
			else{
				if (v[i].y2>v[i].y1){
					mark_diag2 (v[i].x1, v[i].y1, v[i].x2, v[i].y2);
				}
				else{
					mark_diag1 (v[i].x2, v[i].y2, v[i].x1, v[i].y1);
				}
			}
		}
	}
	if (A[0][0]<1000){
		A[0][0]+=cnt*1000;
		++cnt;
	}
	if (A[0][m]<1000){
		A[0][m]+=cnt*1000;
		++cnt;
	}
	if (A[n][0]<1000){
		A[n][0]+=cnt*1000;
		++cnt;
	}
	if (A[n][m]<1000){
		A[n][m]+=cnt*1000;
		++cnt;
	}
}

void make_hor (int x, int y1, int y2)
{
	int cur=0;
	for (int i=y1; i<=y2; ++i){
		if (A[i][x]>1000){
			int p=A[i][x]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}
	}
}

void make_ver (int y, int x1, int x2)
{
	int cur=0;
	for (int i=x1; i<=x2; ++i){
		if (A[y][i]>1000){
			int p=A[y][i]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}
	}
}

void make_diag1 (int x1, int y1, int x2, int y2)
{
	int cur=0;
	for (int i=x1, j=y1; i<=x2; ++i, ++j){
		if (A[j][i]>1000){
			int p=A[j][i]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}
	}
}

void make_diag2 (int x1, int y1, int x2, int y2)
{
	int cur=0;
	for (int i=x1, j=y1; i>=x2; --i, ++j){
		if (A[j][i]>1000){
			int p=A[j][i]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}	
	}
}

void make_bord (void)
{
	int cur=0;
	for (int i=0; i<=n; ++i)
	{
		if (A[i][0]>1000){
			int p=A[i][0]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}	
	}
	
	cur=0;
	for (int i=0; i<=n; ++i)
	{
		if (A[i][m]>1000){
			int p=A[i][m]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}	
	}

	cur=0;
	for (int i=0; i<=m; ++i)
	{
		if (A[0][i]>1000){
			int p=A[0][i]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}	
	}

	cur=0;
	for (int i=0; i<=m; ++i)
	{
		if (A[n][i]>1000){
			int p=A[n][i]/1000;
			if (!cur){
				cur=p;
			}
			else{
				L[cur-1].push_back(p-1);
				L[p-1].push_back(cur-1);
				cur=p;
			}
		}	
	}
}

void make_graph (void)
{
	cnt--;
	L.resize(cnt);
	for (int i=0; i<k; ++i){
		if (v[i].x1==v[i].x2){
			make_hor (v[i].x1, min(v[i].y1, v[i].y2), max(v[i].y1, v[i].y2));
		}
		else if (v[i].y1==v[i].y2){
			make_ver (v[i].y1, min(v[i].x1, v[i].x2), max(v[i].x1, v[i].x2));
		}
		else{
			if (v[i].x2>v[i].x1){
				if (v[i].y2>v[i].y1){
					make_diag1 (v[i].x1, v[i].y1, v[i].x2, v[i].y2);
				}
				else{
					make_diag2 (v[i].x2, v[i].y2, v[i].x1, v[i].y1);
				}
			}
			else{
				if (v[i].y2>v[i].y1){
					make_diag2 (v[i].x1, v[i].y1, v[i].x2, v[i].y2);
				}
				else{
					make_diag1 (v[i].x2, v[i].y2, v[i].x1, v[i].y1);
				}
			}
		}
	}
	make_bord();
}

int dfs (int u)
{
	int res=0;
	for (int i=0; i<L[u].size(); ++i){
		int v=L[u][i];
		col[v]=true;
	}
	for (int i=0; i<L[u].size(); ++i){
		int v=L[u][i];
		for (int j=0; j<L[v].size(); ++j){
			int q=L[v][j];
			if (col[q])
				++res;
		}
	}
	for (int i=0; i<L[u].size(); ++i){
		int v=L[u][i];
		col[v]=false;
	}
	return res;
}

void solve (void)
{
	done.resize(L.size());
	col.resize(L.size());
	for (int i=0; i<L.size(); ++i){
		ans+=dfs(i)/2;
	}
	
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1241.in", "r", stdin);
	freopen ("T1241.out", "w", stdout);
#endif

	init ();

	make_graph();

	solve();

	printf ("%d", ans/3);


	return 0;
}