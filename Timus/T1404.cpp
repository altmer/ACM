#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector <int> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1404.in", "r", stdin);
	freopen ("T1404.out", "w", stdout);
#endif

	getline (cin, s);

	for (int i=0; i<s.size(); ++i)
	{
		v.push_back(s[i]-'a');
		while (i!=0 && v[i]<v[i-1])
			v[i]+=26;
	}

	for (int i=v.size()-1; i>0; --i)
		v[i]-=v[i-1];
	v[0]-=5;
	if (v[0]<0)
		v[0]+=26;

	for (int i=0; i<v.size(); ++i)
		cout << char('a'+v[i]);

	

	return 0;
}