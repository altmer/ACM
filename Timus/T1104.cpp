#include <iostream>
using namespace std;

char ch;
int m=0, num=0, dig;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1104.in", "r", stdin);
	freopen ("T1104.out", "w", stdout);
#endif

	while (cin.get(ch))
	{
		dig=0;
		if (isdigit(ch))
			dig=ch-'0';
		else if (isalpha(ch))
			dig=ch-'A'+10;
		num+=dig;
		if (dig>m)
			m=dig;
	}
	if (m==0)
	{
		cout << "2";
		return 0;
	}
	else
	for (int i=m+1; i<=36; ++i)
		if (!(num%(i-1)))
		{
			cout << i;
			return 0;
		}

	cout << "No solution.";	

	return 0;
}