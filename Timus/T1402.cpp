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

const int M=1000;
int n;
vector <int> ans(M+1),v(M+1);

void set1 (vector <int> &a)
{
	for (int i=1; i<M; ++i)
		a[i]=0;
	a[0]=1;
	a[M]=1;
}

void mult (vector <int> &a, int x)
{
	int len=a[0];
	int car=0;
	for (int i=M; i>=M-len+1; --i)
	{
		a[i]=a[i]*x+car;
		car=a[i]/10;
		a[i]%=10;
		if (i==M-len+1 && car)
			++len;
	}
	a[0]=len;
}

void add (vector <int> &a, vector <int> &b)
{
	int len=max(a[0], b[0]);
	int car=0;
	for (int i=M; i>=M-len+1; --i)
	{
		a[i]+=b[i]+car;
		car=a[i]/10;
		a[i]%=10;
		if (i==M-len+1 && car)
			++len;
	}
	a[0]=len;
}

void print (vector <int> &a)
{
	int len=a[0];
	if (len==0)
	{
		printf ("0");
		return;
	}
	for (int i=M-len+1; i<=M; ++i)
		printf ("%d", a[i]);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1402.in", "r", stdin);
	freopen ("T1402.out", "w", stdout);
#endif

	scanf ("%d", &n);

	for (int i=2; i<=n; ++i)
	{
		set1(v);
		for (int j=n-i+1; j<=n; ++j)
			mult (v, j);
		add (ans, v);
	}

	print (ans);

	return 0;
}