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

int n;
string line;
char s[10000000];
vector <string> dict(6);
bool fin, yes;

void init (void)
{
	dict[0]="eno";
	dict[1]="tuo";
	dict[2]="tuptuo";
	dict[3]="notup";
	dict[4]="ni";
	dict[5]="tupni";
}

bool may (int i, int pos)
{
	int h=pos-dict[i].size();
	for (int j=pos,k=0; j>h; --j, ++k)
	{
		if (j<0 || s[j]!=dict[i][k])
			return false;
	}
	return true;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1102.in", "r", stdin);
	freopen ("T1102.out", "w", stdout);
#endif

	init ();

	scanf ("%d\n", &n);

	for (int q=0; q<n; ++q)
	{
		fin=false;
		yes=false;
		gets(s);
		int i=0;
		while (s[i]!='\0')
			++i;

		int pos=i-1;

		while (!fin)
		{
			fin=true;
			for (int i=0; i<dict.size(); ++i)
			{
				if (may(i, pos))
				{
					pos-=dict[i].size();
					fin=false;
				}
			}
		}
		if (pos==-1)
			printf ("YES\n");
		else
			printf ("NO\n");

	}


	return 0;
}