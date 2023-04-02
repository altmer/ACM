#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int M=1000000009;
vector <bool> P(1000);
vector <__int64> q (100), r(100);
int n, ans;

bool IsPrime (int n)
{
	for (int i=2; i<=sqrt(double(n)); ++i)
	{
		if (n%i==0)
			return false;
	}
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1586.in", "r", stdin);
	freopen ("T1586.out", "w", stdout);
#endif

	for (int i=100; i<=999; ++i)
	{
		if (IsPrime(i))
		{
			P[i]=true;
			q[i%100]++;
		}
	}

	scanf ("%d", &n);
	
	ans=143;

	for (int i=4; i<=n; ++i)
	{
		ans=0;
		for (int j=0; j<r.size(); ++j)
		{
			r[j]=0;
		}

		for (int j=11; j<=99; ++j)
		{
			if (q[j])
			{
				int t=j*10;
				if (P[t+1])
				{
					int T=(t+1)%100;
					r[T]+=q[j];
					ans+=q[j];
					r[T]%=M;
					ans%=M;
				}
				if (P[t+3])
				{
					int T=(t+3)%100;
					r[T]+=q[j];
					ans+=q[j];
					r[T]%=M;
					ans%=M;
				}
				if (P[t+7])
				{
					int T=(t+7)%100;
					r[T]+=q[j];
					ans+=q[j];
					r[T]%=M;
					ans%=M;
				}
				if (P[t+9])
				{
					int T=(t+9)%100;
					r[T]+=q[j];
					ans+=q[j];
					ans%=M;
					r[T]%=M;
				}
			}
		}
		ans%=M;
		q.swap(r);
	}

	printf ("%d", ans);

	return 0;
}