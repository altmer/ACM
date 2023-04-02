#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

string line;
char c;
int st;

bool ispal (int st, int en)
{
	if (st>=en)
		return true;
	else if (line[st]==line[en])
		return ispal(st+1, en-1);
	else
		return false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1354.in", "r", stdin);
	freopen ("T1354.out", "w", stdout);
#endif

	getline (cin, line);

	for (int i=1; i<line.size(); ++i)
	{
		if (ispal(i, line.size()-1))
		{
			st=i;
			break;
		}
	}

	cout << line;
	for (int i=st-1; i>=0; --i)
		cout << line[i];

	if (line.size()==1)
		cout << line;

	return 0;
}