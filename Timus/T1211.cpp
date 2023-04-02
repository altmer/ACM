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

int T, n;
int agn;
vector <int> v, p;
bool fin;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1211.in", "r", stdin);
	freopen ("T1211.out", "w", stdout);
#endif

	scanf ("%d", &T);

	for (int q=0; q<T; ++q)
	{
		int step=0;
		fin=false;
		agn=0;
		scanf ("%d", &n);
		v.resize(n);
		p.resize(n);
		fill(p.begin(), p.end(), 0);
		for (int i=0; i<n; ++i)
		{
			scanf ("%d", &v[i]);
			if (v[i]==0)
			{
				++agn;
				p[i]=-1;
			}
		}
		if (agn!=1)
		{
			printf ("NO\n");
			fin=true;
		}
		else
		{
			for (int i=0; i<n; ++i)
			{
				step++;
				if (p[i]==0)
				{
					int j=v[i]-1;;
					p[i]=step;
					while (p[j]==0)
					{
						p[j]=step;
						j=v[j]-1;
					}
					if (p[j]==step)
					{
						printf ("NO\n");
						fin=true;
						break;	
					}
				}
			}
		}
		if (!fin)
			printf ("YES\n");
	}

	return 0;
}