#include <iostream>
#include <string>
using namespace std;

const int m=1999;
int n;
string line, buf;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1098.in", "r", stdin);
	freopen ("T1098.out", "w", stdout);
#endif

	while (getline(cin, buf))
		line+=buf;

	int L=0;
	n=line.size();
	for (int i=1; i<=n; ++i)
		L=(L+m-1)%i+1;

	switch (line[L-1])
	{
	case '?': cout << "Yes";
		break;
	case ' ': cout << "No";
		break;
	default: cout << "No comments";
	}

	return 0;
}