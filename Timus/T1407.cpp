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

const int M=200;
int n;
vector <int> ans (M+1), v (M+1);

void div (vector <int> &a, int &rem)
{
	int len=a[0];
	for (int i=M-len+1; i<=M; ++i)
	{
		rem=rem*10+a[i];
		a[i]=rem/2;
		rem%=2;
	}
	while (len>0 && a[M-len+1]==0)
		--len;
	a[0]=len;
}

bool div2 (int k)
{
	int rem=0;
	v=ans;
	for (int i=0; i<k; ++i)
	{
		div (v, rem);
		if (rem)
		{
			return false;
		}
	}
	return true;
}

void print (vector <int> &a)
{
	int len=a[0];
	if (!len){
		printf ("0");
		return;
	}
	for (int i=M-len+1; i<=M; ++i)
		printf ("%d", a[i]);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1407.in", "r", stdin);
	freopen ("T1407.out", "w", stdout);
#endif

	scanf ("%d", &n);

	for (int i=1; i<=n; ++i)
	{
		ans[0]++;
		ans[M-i+1]=1;
		if (!div2(i))
			ans[M-i+1]=2;
	}

	print (ans);

	return 0;
}