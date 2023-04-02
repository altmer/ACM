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

string tra="tram";
string tro="trolleybus";
string s, word;
int tram, trol;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1612.in", "r", stdin);
	freopen ("T1612.out", "w", stdout);
#endif

	while (getline (cin, s))
	{
		for (int i=0; i<s.size(); ++i)
		{
			if (isalpha(s[i]))
				word+=s[i];
			else if (!word.empty())
			{
				if (word==tra)
					tram++;
				else if (word==tro)
					trol++;
				word.clear();
			}
		}
		if (word==tra)
			tram++;
		else if (word==tro)
			trol++;
		word.clear();
	}

	if (tram>trol)
		printf ("Tram driver");
	else if (trol>tram)
		printf ("Trolleybus driver");
	else
		printf ("Bus driver");

	return 0;
}