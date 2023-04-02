#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int n, ans=1;
vector <int> prime;
map <int, int> S;
map <int, int> ::iterator it;

bool isprime (int n)
{
	for (int j=2; j<=sqrt(double(n)); ++j)
		if (!(n%j))
			return false;
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1049.in", "r", stdin);
	freopen ("T1049.out", "w", stdout);
#endif

	for (int i=2; i<=10000; ++i)
	{
		if (isprime(i))
			prime.push_back(i);
	}

	for (int i=0; i<10; ++i)
	{
		scanf ("%d", &n);
		int j=0;
		while (prime[j]<=n)
			if (!(n%prime[j]))
			{
				++S[prime[j]];
				n/=prime[j];
			}
			else
				j++;
	}

	for (it=S.begin(); it!=S.end(); ++it)
		ans*=(it->second+1);

	printf ("%d", ans%10);

	return 0;
}