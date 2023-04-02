#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

char G[6][6];
int C[6][6];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
bool res;
string word;

void init (void)
{
	for (int i=0; i<6; ++i)
	{
		for (int j=0; j<6; ++j)
		{
			C[i][j]=0;
			G[i][0]='.';
			G[i][5]='.';
			G[0][i]='.';
			G[5][i]='.';
		}
	}
}

void dfs (int x, int y, int step)
{
	int x2, y2;
	C[x][y]=1;
	if (res)
		return;
	if  (step==word.size())
	{
		res=true;
		return;
	}
	for (int i=0; i<4; ++i)
	{
		if (res)
			return;
		x2=x+dx[i];
		y2=y+dy[i];
		if (G[x2][y2]==word[step] && !C[x2][y2])
		{
			C[x2][y2]=1;
			dfs (x2, y2, step+1);
			C[x2][y2]=0;
		}
	}
	C[x][y]=0;
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1603.in", "r", stdin);
	freopen ("T1603.out", "w", stdout);
#endif

	for (int i=1; i<=4; ++i)
	{
		for (int j=1; j<=4; ++j)
		{
			cin >> G[i][j];
		}
	}

	scanf ("%d\n", &n);

	for (int i=0; i<n; ++i)
	{
		getline (cin, word);
		res=false;
		for (int i=1; i<=4; ++i)
		{
			for (int j=1; j<=4; ++j)
			{
				if (G[i][j]==word[0])
				{
					init();
					dfs (i, j, 1);
				}
				if (res)
					break;
			}
			if (res)
				break;
		}
		if (res)
			cout << word << ": YES\n";
		else
			cout << word << ": NO\n";
	}

	return 0;
}