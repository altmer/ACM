#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;

const int maxn=10000;
int A[maxn], n;

void mult (int x)
{
	int carry = 0;
	for (int i=maxn-1; i>=maxn-A[0]; --i)
	{
		A[i]=A[i]*x+carry;
		carry=A[i]/10;
		A[i]%=10;
		if (i==maxn-A[0] && carry)
			++A[0];
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1222.in", "r", stdin);
	freopen ("T1222.out", "w", stdout);
#endif

	scanf ("%d", &n);

	switch (n)
	{
	case 0: printf ("0");
		return 0;
	case 1: printf ("1");
		return 0;
	}

	A[maxn-1]=1;
	A[0]=1;

	if (!(n%3))
	{
		for (int i=0; i<n/3; ++i)
			mult(3);
	}
	else if (n%3==1)
	{
		for (int i=0; i<n/3-1; ++i)
			mult (3);
		mult (4);
	}

	else
	{
		for (int i=0; i<n/3; ++i)
			mult (3);
		mult (2);
	}

	for (int i=maxn-A[0]; i<maxn; ++i)
		printf ("%d", A[i]);

	return 0;
}