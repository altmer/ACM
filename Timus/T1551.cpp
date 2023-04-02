#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int n, m=0, ans=0;
map <string, int> pref; 
string name, word;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1551.in", "r", stdin);
	freopen ("T1551.out", "w", stdout);
#endif

	scanf ("%d", &n);

	int num=pow(2.0, n);

	for (int i=0; i<num; ++i)
	{
		cin >> name >> word;
		pref[word]++;
		if (pref[word]>m)
			m=pref[word];
	}

	while (m<=num/2)
	{
		++ans;
		num/=2;
	}

	cout << ans;

	return 0;
}