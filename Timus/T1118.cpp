#include <iostream>
#include <cmath>
using namespace std;

double cur, ans = 1000000;
int a, b, mtriv;

double triv (const int &a, bool &prime)
{
	int sum=1;
	double root = sqrt(double(a));
	for (int i=2; i<root;++i)
		if (a%i==0)
			sum+=i+a/i;
	
	if (root==int(root))
		sum+=root;
	
	if (sum==1)
		prime=true;
	return double(sum)/double(a);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1118.in", "r", stdin);
	freopen ("T1118.out", "w", stdout);
#endif

	cin >> a >> b;

	if (a==1)
		cout << "1";
	else
	{
		for (int i=b; i>=a; --i)
		{
			bool prime=false;
			cur=triv(i, prime);
			if (cur<ans)
			{
				ans=cur;
				mtriv=i;
			}
			if (prime)
				break;
		}	
		cout << mtriv;
	}

	return 0;
}