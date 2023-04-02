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

string s;

int main (void)
{
	freopen ("password.in", "r", stdin);
	freopen ("password.out", "w", stdout);

	while(getline(cin, s)){
		if(s.size()<=6){
			cout << "BAD\n" ;
			continue;
		}
		int let=0, dig=0, nan=0;
		for (int i=0;i<s.size(); ++i){
			if (isalnum(s[i])){
				if (isdigit(s[i])){
					++dig;
				}
				else if (isalpha(s[i])){
					++let;
				}
			}
			else{
				++nan;
			}
		}
		cout << ((let>=2 && dig>=2 && nan>=1) ? "GOOD\n" : "BAD\n");
	}

	return 0;
}