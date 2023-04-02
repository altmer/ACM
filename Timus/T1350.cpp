#include <iostream>
#include <set>
#include <string>
using namespace std;

set <string> s;
set <string> :: iterator iter;
string bas[100][100];
int len[100];
int n, k, m, num;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1350.in", "r", stdin);
	freopen ("T1350.out", "w", stdout);
#endif
	string word;
	cin >> n;

	for (int i=1; i<=n; ++i)
	{
		cin >> word;
		s.insert(word);
	}

	cin >> k;

	cin >> num;

	for (int i=1; i<=num; ++i)
	{
		cin >> word;
		iter=s.find(word);
		if (iter!=s.end())
			s.erase(iter);		
	}
	
	n=s.size();
	
	for (int i=0; i<k; ++i)
	{
		cin >> len[i];
		for (int j=0; j<len[i]; ++j)
			cin >> bas[i][j];
	}

	cin >> m;

	for (int i=0; i<k; ++i)
	{
		int dan = 0;
		for (int j=0; j<len[i]; ++j)
			if (s.find(bas[i][j])!=s.end())
				++dan;
		if (dan==0)
			cout << "YES\n";
		else if (dan<=n-m)
			cout << "MAYBE\n";
		else
			cout << "NO\n";
	}

	return 0;
}