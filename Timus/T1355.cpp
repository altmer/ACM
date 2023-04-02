#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector <int> prime;
int T, a, b;

bool isprime (int a)
{
	int i=0;
	while (prime[i]<=sqrt(double(a)) && i<prime.size())
		if (!(a%prime[i++]))
			return false;
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1355.in", "r", stdin);
	freopen ("T1355.out", "w", stdout);
#endif

	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	prime.push_back(7);
	for (int i=11; i<=100000; ++i)
	{
		if (isprime(i))
			prime.push_back(i);
	}

	scanf ("%d", &T);

	for (int i=0; i<T; ++i)
	{
		scanf ("%d%d", &a, &b);
		if (a>b)
			printf ("0\n");
		else if (a==0)
			printf ("0\n");
		else if (b==0)
			printf ("2\n");
		else if (a==b)
			printf ("1\n");
		else if (b%a)
		{
			printf ("0\n");
		}
		else
		{
			int j=0;
			int ans=1;
			while (b!=a && j<prime.size())
			{
				while (j<prime.size() && b%prime[j]==0 && (((b/prime[j])%a)==0))
				{
					b/=prime[j];
					++ans;
				}
				++j;
			}
			if (b>a)
				++ans;
			printf ("%d\n", ans);
		}	
	}

	return 0;
}