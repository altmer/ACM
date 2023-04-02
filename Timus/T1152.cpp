#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n, S, ans=1e+9;
vector <int> v;
vector <bool> u;

void per (int cur, int sum)
{
	if (sum==0)
	{
		if (cur<ans)
		{
			ans=cur;
		}
		return;
	}
	else if (cur>ans)
		return;
	
	for (int i=0; i<n; ++i)
	{
		if (!u[i])
		{
			bool b=false, c=false;
			u[i]=true;
			sum-=v[i];
			if (!u[(i+1)%n])
			{
				u[(i+1)%n]=true;
				sum-=v[(i+1)%n];
				b=true;
			}
			if (!u[(i+2)%n])
			{
				u[(i+2)%n]=true;
				sum-=v[(i+2)%n];
				c=true;
			}
			cur+=sum;

			per(cur, sum);

			cur-=sum;
			sum+=v[i];
			u[i]=false;
			if (b)
			{
				u[(i+1)%n]=false;
				sum+=v[(i+1)%n];
			}

			if(c)
			{
				u[(i+2)%n]=false;
				sum+=v[(i+2)%n];
			}

		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1152.in", "r", stdin);
	freopen ("T1152.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	u.resize(n);
	for (int i=0; i<n; ++i)
	{
		scanf ("%d", &v[i]);
		S+=v[i];
	}

	per (0, S);

	printf ("%d", ans);

	return 0;
}