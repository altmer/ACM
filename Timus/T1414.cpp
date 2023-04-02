#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

set <string> s;
set <string>::iterator it, itb, ite;
string line, tmp;
int k1, k2;

bool pref (const string& s1, const string& s2)
{
	k1=s1.size(); k2=s2.size();
	if (k1>k2)
		return false;
	for (int i=0; i<k1; ++i){
		if (s1[i]!=s2[i])
			return false;
	}
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1414.in", "r", stdin);
	freopen ("T1414.out", "w", stdout);
#endif
	s.insert("sun");

	while (getline(cin, line)){
		if (line[0]=='+'){
			s.insert(line.substr(1));
		}
		else{
			tmp=line.substr(1);
			cout << tmp <<"\n";
			itb=s.lower_bound(tmp);
			int cnt=0;
			for (it=itb; it!=s.end() && cnt<20; ++it){
				if (pref(tmp, *it)){
					cout << "  " << *it << "\n";
					++cnt;
				}
				else{
					break;
				}
			}
		}
	}

	return 0;
}