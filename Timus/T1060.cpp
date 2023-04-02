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

int n, ans=1e+9;
char G[6][6];

void init (void)
{
	for (int i=1; i<=4; ++i)
	{
		for (int j=1; j<=4; ++j)
		{
			cin >> G[i][j];
		}
	}
}

void inv (int x, int y)
{
	if (G[x][y]=='b')
		G[x][y]='w';
	else if ('w'==G[x][y])
		G[x][y]='b';
}

void rec (int step, short x, short y)
{
	if (step>ans)
		return;

	bool fin=true;
	for (short i=1; i<=4; ++i)
	{
		for (short j=1; j<=4; ++j)
		{
			if (G[i][j]!=G[1][1])
			{
				fin =false;
				break;
			}
		}
		if (!fin)
			break;
	}

	if (fin)
	{
		ans=min(step, ans);
		return;
	}
	if (x>4)
		return;
	short x2=x;
	short y2=y+1;
	if (y2>4)
	{
		x2++;
		y2=1;
	}
	rec (step, x2, y2);

	inv (x, y);
	inv(x+1, y);
	inv(x-1, y);
	inv (x, y+1);
	inv (x, y-1);
	rec (step+1, x2, y2);
	inv (x, y);
	inv(x+1, y);
	inv(x-1, y);
	inv (x, y+1);
	inv (x, y-1);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1060.in", "r", stdin);
	freopen ("T1060.out", "w", stdout);
#endif

	init ();

	rec(0, 1, 1);

	if (ans>100000)
		printf ("Impossible");
	else
		printf ("%d", ans);

	return 0;
}