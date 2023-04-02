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
	int st, en, d;
	bool operator < (edge a)
	{
		return d<a.d;
	}
};

vector <int> color;
vector <edge> E;
vector <bool> U;
int n, m;
int c=1;
int P=0, ans=0;
bool fin;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1160.in", "r", stdin);
	freopen ("T1160.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	color.resize(n);
	E.resize(m);
	U.resize(m);

	for (int i=0; i<m; ++i)
	{
		scanf ("%d%d%d", &E[i].st, &E[i].en, &E[i].d);
		E[i].st--;
		E[i].en--;
	}

	sort (E.begin(), E.end());
	ans=E[0].d;

	for (int i=0; i<m; ++i)
	{
		if (E[i].d<=ans)
		{
			U[i]=true;
			P++;
			
			if (color[E[i].st]==0 && color[E[i].en]==0)
			{
				color[E[i].st]=c;
				color[E[i].en]=c++;
				U[i]=true;
			}
			else if (color[E[i].st]!=color[E[i].en])
			{
				U[i]=true;

				if (color[E[i].st]==0)
					color[E[i].st]=color[E[i].en];

				else if (color[E[i].en]==0)
					color[E[i].en]=color[E[i].st];

				else
				{
					int per=color[E[i].en];
					int top=color[E[i].st];
					for (int j=0; j<n; ++j)
					{
						if (color[j]==per)
							color[j]=top;
					}
				}			
			}
		}
		else
		{
			fin=true;
			for (int j=1; j<n; ++j)
			{
				if (color[j]!=color[j-1])
				{
					fin=false;
					break;
				}
			}
			if (fin)
				break;
			ans=E[i].d;

			U[i]=true;
			P++;
			
			if (color[E[i].st]==0 && color[E[i].en]==0)
			{
				color[E[i].st]=c;
				color[E[i].en]=c++;
				U[i]=true;
			}
			else if (color[E[i].st]!=color[E[i].en])
			{
				U[i]=true;

				if (color[E[i].st]==0)
					color[E[i].st]=color[E[i].en];

				else if (color[E[i].en]==0)
					color[E[i].en]=color[E[i].st];

				else
				{
					int per=color[E[i].en];
					int top=color[E[i].st];
					for (int j=0; j<n; ++j)
					{
						if (color[j]==per)
							color[j]=top;
					}
				}			
			}
		}
	}

	printf ("%d\n%d\n", ans, P);

	for (int i=0; i<m; ++i)
	{
		if (U[i])
		{
			--P;
			printf ("%d %d\n", E[i].st+1, E[i].en+1);
		}
		if (P<=0)
			break;
	}

	return 0;
}