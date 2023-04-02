#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int n;
set <string> s;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1563.in", "r", stdin);
	freopen ("T1563.out", "w", stdout);
#endif

	cin >> n;
	scanf ("\n");
	string word;
	int ans=0;
	for (int i=1; i<=n; ++i)
	{
		getline (cin, word);
		if (s.find(word)!=s.end())
			++ans;
		else s.insert(word);
	}
	
	cout << ans;
	return 0;	
}