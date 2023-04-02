#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int cur, pr, ans=1;
int a, b;
bool pl;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1346.in", "r", stdin);
	freopen ("T1346.out", "w", stdout);
#endif

	scanf ("%d%d", &a, &b);

	int st=a+2;

	scanf ("%d%d", &pr, &cur);
	if (cur!=pr)
	{
		pl=(cur>pr);
		pr=cur;
	}
	else
	{
		while (st++<=b)
		{
			scanf ("%d", &cur);
			if (cur!=pr)
			{
				pl=(cur>pr);
				pr=cur;
				break;
			}
		}
	}

	for (int i=st; i<=b; ++i)
	{
		scanf ("%d", &cur);
		if (pl && cur<pr)
		{
			pr=cur;
			++ans;
			while (i++<=b)
			{
				scanf ("%d", &cur);
				if (cur!=pr)
				{
					pl=(cur>pr);
					pr=cur;
					break;
				}
			}
		}
		else if (!pl && cur>pr)
		{
			pr=cur;
			++ans;
			while (i++<=b)
			{
				scanf ("%d", &cur);
				if (cur!=pr)
				{
					pl=(cur>pr);
					pr=cur;
					break;
				}
			}
		}
		else
			pr=cur;
	}

	cout << ans;

	return 0;
}