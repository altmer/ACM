#include <iostream>
#include <string>
using namespace std;

int n, SUM = 0, num = 0, sum = 0;
bool res = false;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1190.in", "r", stdin);
	freopen ("T1190.out", "w", stdout);
#endif

	scanf("%d\n", &n);

	string s;
	bool in;
	int per = 0;
	for (int i=1; i<=n; ++i)
	{
		cin >> s >> in;
		if (!in)
		{
			++num;
			if (per==0)
				SUM=10001;
		}
		else
		{
			SUM+=per*num;
			cin >> per;
			sum+=per*(num+1);
			SUM+=per;
			num=0;
		}
	}

	SUM+=num*per;
	sum+=num;

	if (sum>10000 || SUM < 10000)
		cout << "NO";
	else 
		cout << "YES";
	return 0;
}