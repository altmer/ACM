#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> v;
string word, buf;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1496.in", "r", stdin);
	freopen ("T1496.out", "w", stdout);
#endif

	cin >> n;
	while (cin >> word)
		v.push_back(word);

	sort (v.begin(), v.end());
	bool spam=false;
	for (int i=0; i<n;++i)
	{
		if (spam)
		{
			if (v[i]!=buf || i==n-1)
			{
				cout << buf << endl;
				buf.clear();
				spam=false;
				if (i!=n-1 && v[i+1]==v[i])
				{	
					spam=true;
					buf=v[i];
				}
			}
		}
		else if (i!=n-1 && v[i+1]==v[i])
		{
			spam=true;
			buf=v[i];
		}
	}
	
	return 0;
}