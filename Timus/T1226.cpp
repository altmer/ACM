#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <stack>
using namespace std;

string line;
stack <char> S;

void destack(void)
{
	while (!S.empty())
	{
		cout << S.top();
		S.pop();
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1226.in", "r", stdin);
	freopen ("T1226.out", "w", stdout);
#endif

	while (getline (cin, line))
	{
		for (int i=0; i<line.size(); ++i)
		{
			if (isalpha(line[i]))
				S.push(line[i]);
			else
			{
				destack();
				cout << line[i];
			}
		}
		destack();
		cout << "\n";
	}

	return 0;
}