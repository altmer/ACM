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

string p, s, h;

string rot (string q, int k)
{
	string t;
	t=q;
	switch (k){
		case 1: t[0]=q[1];
			t[1]=q[3];
			t[2]=q[2];
			t[3]=q[0];
			break;
		case 2: t[0]=q[2];
			t[1]=q[1];
			t[2]=q[3];
			t[3]=q[0];
			break;
		case 3: t[0]=q[3];
			t[1]=q[0];
			t[2]=q[2];
			t[3]=q[1];
			break;
	}
	return t;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1433.in", "r", stdin);
	freopen ("T1433.out", "w", stdout);
#endif

	getline (cin, p);
	getline (cin, s);

	if (p==s){
		printf ("equal");
		return 0;
	}

	for (int i=0; i<4; ++i)
	{
		if (p[i]==s[0]){
			h=rot(p, i);
			h=h.substr(1, 3);
			h+=h;
			for (int j=0; j<3; ++j){
				if (h.substr(j, 3)==s.substr(1, 3)){
					printf ("equal");
					return 0;
				}
			}
		}
	}
	
	printf ("different");

	return 0;
}