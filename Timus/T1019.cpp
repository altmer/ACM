#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct point
{
	char col1, col2;
	int coord;
};

list <point> L;
list <point> :: iterator it;
int n;
int a, b;
int cur1, cur2;
int ans1, ans2;
char c;
bool white;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1019.in", "r", stdin);
	freopen ("T1019.out", "w", stdout);
#endif

	point u;
	u.col1='b';
	u.col2='w';
	u.coord=0;
	L.insert(L.end(), u);
	u.coord=1000000000;
	u.col1='w';
	u.col2='b';
	L.insert(L.end(), u);

	scanf ("%d", &n);

	for (int i=0; i<n; ++i)
	{
		scanf ("%d %d %c\n", &a, &b, &c);
		u.col2=c;
		u.coord=a;
		it=L.begin();
		while (it->coord<u.coord)
			++it;
		
		--it;
		u.col1=it->col2;
		++it;
		L.insert(it, u);
		u.coord=b;
		u.col1=c;
		while (it->coord<u.coord)
		{
			it=L.erase(it);
		}
		u.col2=it->col1;
		L.insert(it, u);
	}

	for (it=L.begin(); it!=L.end(); ++it)
	{
		if (!white)
		{
			if (it->col2=='w')
			{
				cur1=it->coord;
				white=true;
			}
		}
		else
		{
			if (it->col2=='b')
			{
				cur2=it->coord;
				if (cur2-cur1>ans2-ans1)
				{
					ans2=cur2;
					ans1=cur1;
				}
				cur1=0;
				cur2=0;
				white=false;
			}
		}
	}

	printf ("%d %d", ans1, ans2);

	return 0;
}