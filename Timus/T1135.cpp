#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string word;
int n, ans, r;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1135.in", "r", stdin);
	freopen ("T1135.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	
	while (getline (cin, word))
	{
		for (int i=0; i<word.size(); ++i)
		{
			if (word[i]=='>')
				++r;
			else if (word[i]=='<')
				ans+=r;
		}
	}

	printf ("%d", ans);

	return 0;
}