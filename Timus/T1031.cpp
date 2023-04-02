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

struct edge 
{
	int dest, cost;
};

int L1, L2, L3, C1, C2, C3;
int n;
int st, en;
vector <int> s;
vector <int> d;

void input (void)
{
	scanf ("%d%d%d%d%d%d", &L1, &L2, &L3, &C1, &C2, &C3);
	scanf ("%d", &n);
	s.resize(n);
	d.resize(n);
	scanf ("%d%d", &st, &en);
	st--;
	en--;
	for (int i=1; i<n; ++i)
	{
		scanf ("%d", &s[i]);
	}
}

void solve (void)
{
	if (st>en)
	{
		int t=en;
		en=st;
		st=t;
	}
	for (int i=st; i<en; ++i)
	{
		int j=i+1;
		while (j<=en)
		{
			int t=s[j]-s[i];
			if (t<=L1)
			{
				if (d[j]==0 || d[i]+C1<d[j])
				{
					d[j]=d[i]+C1;
				}
			}
			else if (t<=L2)
			{
				if (d[j]==0 || d[i]+C2<d[j])
				{
					d[j]=d[i]+C2;
				}
			}
			else if (t<=L3)
			{
				if (d[j]==0 || d[i]+C3<d[j])
				{
					d[j]=d[i]+C3;
				}
			}
			else
			{
				break;
			}
			++j;
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1031.in", "r", stdin);
	freopen ("T1031.out", "w", stdout);
#endif

	input();

	solve ();

	printf ("%d", d[en]);

	return 0;
}