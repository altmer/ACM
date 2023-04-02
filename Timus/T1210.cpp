#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

vector <int> cur, prev;
int n, ans=2000000000;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1210.in", "r", stdin);
	freopen ("T1210.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	prev.push_back(0);
	for (int i=0; i<n; ++i)
	{
		char ch;
		int k;
		scanf ("%d\n", &k);
		for (int j=1; j<=k; ++j)
		{
			int u=1, len;
			cur.push_back(200000000);
			while (u)
			{
				scanf ("%d", &u);
				if (u)
				{
					scanf ("%d", &len);
					if (cur.back()>prev[u-1]+len)
						cur[cur.size()-1]=prev[u-1]+len;
				}				
			}
			scanf ("\n");
		}
		scanf ("%c\n", &ch);
		prev.swap(cur);
		cur.clear();
	}
	
	for (int i=0; i<prev.size(); ++i)
	{
		if (prev[i]<ans)
			ans=prev[i];
	}

	cout<<ans;

	return 0;
}