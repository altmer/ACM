#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector <int> prime;
int T, N;

bool isprime (int a)
{
	int i=0;
	if (a==1)
		return false;
	while (prime[i]<=sqrt(double(a)) && i<prime.size())
		if (!(a%prime[i++]))
			return false;
	return true;
}

bool per2 (void)
{
	int j=10000;
	while (j>=0 && prime[j]>N)
		--j;
	while (j>=0)
	{
		if (isprime(N-prime[j]))
		{
			printf ("%d %d\n", prime[j], N-prime[j]);
			return true;
		}
		--j;
	}
	return false;
}

bool per3 (void)
{
	int j=5000;
	while (j>=0 && prime[j]>N)
		--j;
	while (j>=0)
	{
		if (isprime(N-prime[j]))
		{
			printf ("%d %d\n", prime[j], N-prime[j]);
			return true;
		}
		else
		{
			int k=5000;

			while (k>=0 && prime[k]>N-prime[j])
				--k;
			while (k>=0)
			{
				if (isprime(N-prime[j]-prime[k]))
				{
					printf ("%d %d %d\n", prime[j], prime[k], N-prime[j]-prime[k]);
					return true;
				}
				--k;
			}
		}
		--j;
	}
	return false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1356.in", "r", stdin);
	freopen ("T1356.out", "w", stdout);
#endif

	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	prime.push_back(7);
	for (int i=11; i<=200000; ++i)
	{
		if (isprime(i))
			prime.push_back(i);
	}

	scanf ("%d", &T);

	for (int i=0; i<T; ++i)
	{
		scanf ("%d", &N);
		if (isprime (N))
		{
			printf ("%d\n", N);
		}
		else
		{
			bool res=false;
			res=per2();
			if (!res)
				per3();
		}
	}

	return 0;
}