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

string s;
int ans;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1262.in", "r", stdin);
	freopen ("T1262.out", "w", stdout);
#endif

	getline (cin, s);

	for (int i=0; i<s.size(); ++i)
	{
		if (s[i]=='1' || s[i]=='5')
			ans+=1;
		else if (s[i]=='4' || s[i]=='9')
			ans+=2;
		else{
			if (s[i]>'5')
				ans+=s[i]-'0'-4;
			else
				ans+=s[i]-'0';
		}
	}

	printf ("%d", ans);

	return 0;
}