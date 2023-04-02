#include <iostream>
#include <string>
using namespace std;

const int M=100;
int A[M];
int k;

void multshort (int mul)
{
	int i=1;
	int carry=0;
	while (i<=A[0])
	{
		carry+=mul*A[M-i];
		A[M-i]=carry%10;
		carry/=10;
		if (i==A[0] && carry)
			++A[0];
		++i;
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1206.in", "r", stdin);
	freopen ("T1206.out", "w", stdout);
#endif

	A[0]=2;
	A[M-1]=6;
	A[M-2]=3;
	cin >> k;
	for (int i=1; i<=k-1; ++i)
		multshort (55);

	for (int i=A[0]; i>0; --i)
		printf ("%d", A[M-i]);

	return 0;
}