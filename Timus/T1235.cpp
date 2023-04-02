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

struct tree
{
	int x, y;
	bool operator < (tree t)
	{
		if (x==t.x)
			return y<t.y;
		return x<t.x;
	}
};

int n, h, w;
int l_ans, p_ans, q_ans;
vector <tree> v;

void init (void)
{
	scanf ("%d%d%d", &n, &w, &h);
	tree t;
	v.resize(n+1);
	for (int i=1; i<=n; ++i)
		scanf ("%d%d", &v[i].x, &v[i].y);
	sort (v.begin(), v.end());
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1235.in", "r", stdin);
	freopen ("T1235.out", "w", stdout);
#endif

	init ();

	for (int i=0; i<=n; ++i)
	{
		for (int j=0; j<=n; ++j)
		{
			int cl=min(w-v[i].x, h-v[j].y);
			for (int k=i+1; k<=n; ++k)
			{
				if (v[k].x>v[i].x && v[k].y>v[j].y)
					cl=min(max(v[k].x-v[i].x, v[k].y-v[j].y), cl);
			}
			if (cl>l_ans)
			{
				l_ans=cl;
				p_ans=v[i].x;
				q_ans=v[j].y;
			}
		}
	}

	printf ("%d %d %d", p_ans, q_ans, l_ans);

	return 0;
}