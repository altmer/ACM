#include <iostream>
#include <string>
#include <vector>
using namespace std;

string line;
vector <bool> is (37);
vector <int> ans (37);
int n, x, y;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1179.in", "r", stdin);
	freopen ("T1179.out", "w", stdout);
#endif


	while (getline(cin, line))
	{
		for (int j=2; j<=36; ++j)
			is[j]=true;

		for (int i=0; i<line.size(); ++i)
		{
			if (isdigit(line[i]))
			{
				n=line[i]-'0';
			}
			else if (isalpha(line[i]))
			{
				n=line[i]-'A'+10;
			}
			else
				n=36;

			for (int j=2; j<=n; ++j)
				is[j]=true;

			for (int j=n+1; j<=36; ++j)
			{
				if (is[j])
				{
					is[j]=false;
					++ans[j];
				}
			}
		}
	}

	for (int i=0; i<ans.size(); ++i)
	{
		if (ans[i]>y)
		{
			x=i;
			y=ans[i];
		}
	}

	printf ("%d %d", x, y);

	return 0;
}