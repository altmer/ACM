#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector < vector < bool > > A, B, T, R;
int n;

void mult_matrix (void)
{
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			int sum=0;
			for (int k=0; k<n; ++k)
				sum+=T[i][k]*A[k][j];
			R[i][j]=sum;
		}

}

void sum_matrix (void)
{
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			B[i][j]=B[i][j]+T[i][j];
}

int main (void)
{

	printf ("%d\n", nod (2808, 3384));
	printf ("%d\n", nok (2808, 3384));

#ifndef ONLINE_JUDGE
	freopen ("T1507.in", "r", stdin);
	freopen ("T1507.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize (n);
	B.resize (n);
	T.resize (n);
	R.resize (n);
	for (int i=0; i<n; ++i)
	{
		A[i].resize(n);
		B[i].resize(n);
		T[i].resize(n);
		R[i].resize(n);
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			int temp;
			scanf ("%d", &temp);
			A[i][j]=temp;
		}
	T=A;

	int k=n*(n-1);
	for (int i=2; i<=k; ++i)
	{
		mult_matrix();
		T.swap(R);
	}

	sum_matrix();
	for (int i=k; i<=n*(n+1); ++i)
	{
		mult_matrix();
		T.swap(R);
		sum_matrix();		
	}

	bool res=true;
	for (int i=0; i<n; ++i)
	{
		if (!res)
			break;
		for (int j=0; j<n; ++j)
			if (!B[i][j])
			{
				res=false;
				break;
			}
	}

	if (res)
		printf ("Yes");
	else
		printf ("No");

	return 0;
}