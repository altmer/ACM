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

struct room
{
	int f, n;
};

int n, m, min_ans=2000000004;
queue <room> q;
vector < vector <__int64> > A, D;
vector <vector <room> > P;
stack <int> ans;
int dx[]= {1, -1};

void init (void)
{
	A.resize(m+2);
	D.resize(m+2);
	P.resize(m+2);
	for (int i=0; i<=m+1; ++i)
	{
		A[i].resize(n+2);
		D[i].resize(n+2);
		P[i].resize(n+2);
	}
	for (int i=0; i<=m+1; ++i)
	{
		D[i][0]=-1;
		D[i][n+1]=-1;
	}
	for (int i=0; i<=n+1; ++i)
	{
		D[0][i]=-1;
		D[m+1][i]=-1;
	}
	for (int i=1; i<=m; ++i)
	{
		for (int j=1; j<=n; ++j)
			scanf ("%d", &A[i][j]);
	}
}

void solve (void)
{
	int floor = 2;
	room u;
	for (int i=1; i<=n; ++i)
		D[1][i]=A[1][i];
	while (floor<=m)
	{
		u.f=floor-1;
		for (int i=1; i<=n; ++i)
		{
			D[floor][i]=D[floor-1][i]+A[floor][i];
			u.n=i;
			P[floor][i]=u;
		}
		int it=1;
		u.f=floor;
		while (it)
		{
			it=0;
			for (int i=1; i<=n; ++i)
			{
				for (int j=0; j<2; ++j)
				{
					u.n=i+dx[j];
					if (D[u.f][u.n]!=-1 && D[floor][i]>D[u.f][u.n]+A[floor][i])
					{
						it++;
						D[floor][i]=D[u.f][u.n]+A[floor][i];
						P[floor][i]=u;
					}
				}
			}
		}
		++floor;
	}

	int min_num=2000000004, mroom;
	for (int i=1; i<=n; ++i)
	{
		if (D[m][i]<min_num)
		{
			min_num=D[m][i];
			mroom=i;
		}
	}

	u.f=m;
	u.n=mroom;

	while (u.f!=1)
	{
		ans.push(u.n);
		u=P[u.f][u.n];
	}
	ans.push(u.n);
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1029.in", "r", stdin);
	freopen ("T1029.out", "w", stdout);
#endif

	scanf ("%d%d", &m, &n);
	init();

	solve();

	while (!ans.empty())
	{
		printf ("%d\n", ans.top());
		ans.pop();
	}

	return 0;
}