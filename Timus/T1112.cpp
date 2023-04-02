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

struct segm
{
	int a, b;
	bool operator < (segm p)
	{
		if (a==p.a)
			return b<p.b;
		return a<p.a;
	}
};

int n, m=0, k=-1;
vector <segm> v;
vector <int> s, p;
stack <segm> ans;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1112.in", "r", stdin);
	freopen ("T1112.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	s.resize(n);
	p.resize(n);

	for (int i=0; i<n; ++i)
	{
		int x, y;
		scanf ("%d %d", &x, &y);
		v[i].a=min(x,y);
		v[i].b=max(x,y);
	}

	sort (v.begin(), v.end());

	s[0]=1;
	p[0]=-1;

	for (int i=1; i<n; ++i)
	{
		s[i]=1;
		p[i]=-1;
		for (int j=i-1; j>=0; --j)
		{
			if (v[j].b<=v[i].a && s[i]<s[j]+1)
			{
				s[i]=s[j]+1;
				p[i]=j;
			}
		}
	}

	for (int i=0; i<n; ++i)
	{
		if (s[i]>m)
		{
			m=s[i];
			k=i;
		}
	}

	while (p[k]!=-1)
	{
		ans.push(v[k]);
		k=p[k];
	}
	
	ans.push(v[k]);

	printf ("%d\n", ans.size());

	while (!ans.empty())
	{
		printf ("%d %d\n", ans.top().a, ans.top().b);
		ans.pop();
	}

	return 0;
}