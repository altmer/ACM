#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <ios>
using namespace std;

vector <string> v;
string word, s;
int ans = 0;

bool isless (const string &s1, const string &s2)
{
	if (s1.size()!=s2.size())
		return s1.size()<s2.size();
	return s1<s2;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1089.in", "r", stdin);
	freopen ("T1089.out", "w", stdout);
#endif


	while (cin >> word && word!="#")
		v.push_back(word);
	scanf("\n");
	int n=v.size();

	sort (v.begin(), v.end(), isless);
	int st = 0, en = 0;
	int ent = 0;
	
	while (getline (cin, word))
	{		
		bool inword=false;
		for (int i=0;i<word.size(); ++i)
		{
			for (int j=0; j<=ent; ++j)
				cout << "\n";
			ent=0;
			if (isalpha(word[i]) && !inword)
			{
				st=i;
				inword=true;
			}
			if (!isalpha(word[i]) || i==word.size()-1)
			{
				inword=false;
				if (i==word.size()-1 && isalpha(word[i]))
					en=i;
				else en=i-1;
				bool replace = false;
				int torep;
				for (int j=0; j!=n; ++j)
				{
					if (en-st+1==v[j].size())
					{
						int spell = 0;
						for (int k=0; k<v[j].size(); ++k)
						{
							if (v[j][k]!=word[st+k])
								++spell;
							if (spell>1)
								break;
						}
						if (spell==1)
						{
							replace=true;
							torep=j;
							++ans;
							break;
						}
					}
					else if (en-st+1<v[j].size() || replace) 
						break;
				}
				if (replace && st!=word.size())
					cout << v[torep];
				else 
				{
					if (st!=word.size())
					for (int l=st; l<=en; ++l)
						cout << word[l];
				}
				st=word.size();
				en=0;
				if (!isalpha(word[i])) 
					cout << word[i];	
			}
		}
		if (word.empty())
			++ent;
		else
			cout << "\n";
	}
	cout << ans;
	return 0;
}