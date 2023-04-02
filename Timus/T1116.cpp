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

struct point
{
	point() : n(1000), st(false) {}
	int n;
	bool st;
};

struct segm
{
	int a, b, y;
};

const int M=70000;
vector <point> f1 (M), f2 (M);
vector <segm> f;
bool fun1, fun2, fun;
int n;
segm t;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1116.in", "r", stdin);
	freopen ("T1116.out", "w", stdout);
#endif

	scanf ("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int a, b, y;
		scanf ("%d%d%d", &a, &b, &y);
		f1[a+32000].st=true;
		f1[a+32000].n=y;
		f1[b+32000].st=false;
		f1[b+32000].n=y;
	}

	scanf ("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int a, b, y;
		scanf ("%d%d%d", &a, &b, &y);
		f2[a+32000].st=true;
		f2[a+32000].n=y;
		f2[b+32000].st=false;
		f2[b+32000].n=y;
	}

	for (int i=0; i<f1.size(); ++i)
	{
		if (f1[i].n!=1000)
		{
			if (f1[i].st)
			{
				fun1=true;
			}
			else
				fun1=false;
		}
		if (f2[i].n!=1000)
		{
			if (f2[i].st)
				fun2=true;
			else
				fun2=false;
		}

		if (f1[i].st && !fun2 && fun)
		{
			t.b=i-32000;
			f.push_back(t);
			t.a=i-32000;
			t.y=f1[i].n;
		}
		if (!fun)
		{
			if (fun1 && !fun2)
			{
				fun=true;
				t.a=i-32000;
				int j=i;
				while (f1[j].n==1000)
					--j;
				t.y=f1[j].n;
			}
		}
		else
		{
			if (!fun1 || fun2)
			{
				fun=false;
				t.b=i-32000;
				f.push_back(t);
			}
		}
	}

	printf ("%d ", f.size());
	for (int i=0; i<f.size(); ++i)
	{
		printf ("%d %d %d ", f[i].a, f[i].b, f[i].y);
	}

	return 0;
}