#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
struct point
{
	int x, y;
};
const int vis=1;
const int treas=2;
const int up=2;
const int down=3;
const int l=1;
const int r=0;
int n, m;
int A[102][102];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int way=r;
bool count;
int ans=0;
point pos;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1377.in", "r", stdin);
	freopen ("T1377.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);

	for (int i=0; i<=m+1; ++i)
	{
		A[n+1][i]=vis;
		A[0][i]=vis;
	}

	for (int i=0; i<=n+1; ++i)
	{
		A[i][0]=vis;
		A[i][m+1]=vis;
	}
	
	for (int i=0; i<2; ++i)
	{
		int u, v;
		scanf ("%d%d", &u, &v);
		A[u][v]=treas;
	}

	pos.x=1;
	pos.y=1;
	if (A[pos.x][pos.y]==treas)
		count=true;
	A[pos.x][pos.y]=vis;
	while (true)
	{
	switch (way)
	{
	case r: 
		if (A[pos.x+dx[r]][pos.y+dy[r]]==treas)
		{
			if (!count)
			{
				count=true;
				pos.x+=dx[r];
				pos.y+=dy[r];
				A[pos.x][pos.y]=vis;
			}
			else
			{
				printf ("%d", ans+1);
				return 0;
			}
		}
		else if (A[pos.x+dx[r]][pos.y+dy[r]]==vis)
		{
			way=down;
		}
		else
		{
			pos.x+=dx[r];
			pos.y+=dy[r];
			A[pos.x][pos.y]=vis;
			if (count)
				++ans;
		}
		break;
	case l:
		if (A[pos.x+dx[l]][pos.y+dy[l]]==treas)
		{
			if (!count)
			{
				count=true;
				pos.x+=dx[l];
				pos.y+=dy[l];
				A[pos.x][pos.y]=vis;
			}
			else
			{
				printf ("%d", ans+1);
				return 0;
			}
		}
		else if (A[pos.x+dx[l]][pos.y+dy[l]]==vis)
		{
			way=up;
		}
		else
		{
			pos.x+=dx[l];
			pos.y+=dy[l];
			A[pos.x][pos.y]=vis;
			if (count)
				++ans;
		}
		break;
	case up: 
		if (A[pos.x+dx[up]][pos.y+dy[up]]==treas)
		{
			if (!count)
			{
				count=true;
				pos.x+=dx[up];
				pos.y+=dy[up];
				A[pos.x][pos.y]=vis;
			}
			else
			{
				printf ("%d", ans+1);
				return 0;
			}
		}
		else if (A[pos.x+dx[up]][pos.y+dy[up]]==vis)
		{
			way=r;
		}
		else
		{
			pos.x+=dx[up];
			pos.y+=dy[up];
			A[pos.x][pos.y]=vis;
			if (count)
				++ans;
		}
		break;
	case down: 
		if (A[pos.x+dx[down]][pos.y+dy[down]]==treas)
		{
			if (!count)
			{
				count=true;
				pos.x+=dx[down];
				pos.y+=dy[down];
				A[pos.x][pos.y]=vis;
			}
			else
			{
				printf ("%d", ans+1);
				return 0;
			}
		}
		else if (A[pos.x+dx[down]][pos.y+dy[down]]==vis)
		{
			way=l;
		}
		else
		{
			pos.x+=dx[down];
			pos.y+=dy[down];
			A[pos.x][pos.y]=vis;
			if (count)
				++ans;
		}
		break;

	}
}
	return 0;
}