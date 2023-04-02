#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string s;

void shift ()
{
	int i=s.size()-1;
	char t='9';
	char car;
	while (s[i]!='0')
	{
		car=s[i];
		s[i]=t;
		--i;
		t=car;
	}
	s[i]=t;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1406.in", "r", stdin);
	freopen ("T1406.out", "w", stdout);
#endif
	
	getline (cin, s);

	for (int i=s.size()-1; i>=0; --i){
		if (s[i]!='0'){
			char t=s[i]-1;
			int j=i;
			s[j]='0';
			while (j<s.size() && s[j]=='0')
				++j;
			s[j-1]=t;
			j=i-1;
			
			while (j>=0 && s[j]=='9'){
				s[j]='0';
				shift();
				--j;
			}
			if (j<0){
				printf ("-1");
				return 0;
			}
			s[j]+=1;
			cout << s;
			return 0;
		}
	}

	printf ("-1");

	return 0;
}