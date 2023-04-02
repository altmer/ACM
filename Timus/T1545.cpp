#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector <string> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1545.in", "r", stdin);
	freopen ("T1545.out", "w", stdout);
#endif

	cin >> n;
	scanf (

	string word;
	for (int i=1; i<=n; ++i)
	{
		getline (cin, word);
		v.push_back(word);
	}

	char s;
	cin >> s;
	sort (v.begin(), v.end());

	for (int i=0; i<v.size(); ++i)
		if (v[i][0]==s)
			cout << v[i] << endl;
		else if(v[i][0]>s)
			break;

	return 0;
}