#include <iostream>
#include <map>
#include <string>
using namespace std;

map <char, int> count;
map <char, int> ::iterator it;
string line;
int n, m, p;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1164.in", "r", stdin);
	freopen ("T1164.out", "w", stdout);
#endif

	scanf ("%d%d%d\n", &n, &m, &p);

	for (int i=0; i<n; ++i)
	{
		getline (cin, line);
		for (int j=0; j<line.size(); ++j)
			count[line[j]]++;		
	}

	for (int i = 0; i<p; ++i)
	{
		getline (cin, line);
		for (int j=0; j<line.size(); ++j)
			count[line[j]]--;
	}

	for (it=count.begin(); it!=count.end(); ++it)
		while (it->second--)
			printf ("%c", it->first);

	return 0;
}