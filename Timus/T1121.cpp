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

int m[150][150], a[150][150];
set <int> s;
set <int> :: iterator it;
int h, w;

void fit (int x, int y)
{
	s.clear();
	int ans=1e+9;
	for (int i=max(0, x-6); i<min (h, x+6); ++i)
	{
		for (int j=max(0, y-6); j<min(w, y+6); ++j)
		{
			if (m[i][j])
			{
				int d=abs(i-x)+abs(j-y);
				if (d<6 && d<ans)
				{
					ans=d;
					s.clear();
					s.insert(m[i][j]);
				}
				else if (d==ans)
				{
					if (s.find(m[i][j])==s.end())
						s.insert(m[i][j]);
				}
			}
		}
	}
	for (it=s.begin(); it!=s.end(); ++it)
		a[x][y]=a[x][y]|*it;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1121.in", "r", stdin);
	freopen ("T1121.out", "w", stdout);
#endif

	scanf ("%d%d", &h, &w);

	for (int i=0; i<h; ++i)
	{
		for (int j=0; j<w; ++j)
		{
			scanf ("%d", &m[i][j]);
		}
	}

	for (int i=0; i<h; ++i)
	{
		for (int j=0; j<w; ++j)
		{
			if (m[i][j])
			{
				a[i][j]=-1;
			}
			else
				fit (i, j);
		}
	}

	for (int i=0; i<h; ++i)
	{
		for (int j=0; j<w; ++j)
		{
			printf ("%d ", a[i][j]);
		}
		printf ("\n");
	}

	return 0;
}