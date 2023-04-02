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

int ans=-1, len;
string s;

bool ispal (int i, int j)
{
	if (i>=j)
		return true;
	if (s[i]==s[j])
		return ispal(i+1, j-1);
	else
		return false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1297.in", "r", stdin);
	freopen ("T1297.out", "w", stdout);
#endif

	getline (cin, s);

	for (int i=0; i<s.size(); ++i)
	{
		for (int l=s.size()-i; l>len; --l)
		{
			if (ispal(i, i+l-1))
			{
				len=l;
				ans=i;
			}
		}
	}

	for (int i=ans; i<=ans+len-1; ++i)
		printf ("%c", s[i]);

	return 0;
}