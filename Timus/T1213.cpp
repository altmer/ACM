#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;

set <string> s;
string line;
int ans=-1;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1213.in", "r", stdin);
	freopen ("T1213.out", "w", stdout);
#endif

	getline (cin, line);
	s.insert(line);
	++ans;
	while (line!="#")
	{
		getline (cin, line);
		int i=0;
		string word;
		while (isalpha(line[i])||isdigit(line[i]))
			word+=line[i++]; 
		++i;
		if (s.find(word)==s.end()&&line!="#")
		{
			++ans;
			s.insert(word);
		}
		word="";
		while (i<line.size())
			word+=line[i++];
		if (s.find(word)==s.end()&&line!="#")
		{
			++ans;
			s.insert(word);
		}
	}

	cout << ans;

	return 0;
}