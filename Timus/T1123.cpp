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

string line;
bool up;
int l, r;

void cmp_mid (void)
{
	int s=line.size();
	if (s%2==0)
	{
		int lm=s/2-1;
		int rm=s/2;
		if (line[lm]>line[rm])
		{
			line[rm]=line[lm];
			up=true;
		}
		else if (line[lm]<line[rm])
		{
			line[lm]+=1;
			line[rm]=line[lm];
			up=true;
		}
		l=lm-1;
		r=rm+1;
	}
	else
	{
		l=s/2-1;
		r=s/2+1;
	}
}

void inc_mid (void)
{
	int s=line.size();
	if (s%2==0)
	{
		int lm=s/2-1;
		int rm=s/2;

		while (line[lm]=='9')
		{
			line[lm]='0';
			line[rm]='0';
			lm--;
			rm++;
		}

		line[lm]+=1;
		line[rm]+=1;
	}
	else
	{
		int lm=s/2;
		int rm=s/2;

		while (line[lm]=='9')
		{
			line[lm]='0';
			line[rm]='0';
			lm--;
			rm++;
		}

		if (lm!=rm)
		{
			line[lm]+=1;
			line[rm]+=1;
		}
		else
			line[lm]+=1;
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1123.in", "r", stdin);
	freopen ("T1123.out", "w", stdout);
#endif

	getline (cin, line);

	cmp_mid();

	while (l>=0)
	{
		if (line[l]>line[r])
		{
			line[r]=line[l];
			up=true;
		}
		else if (line[l]<line[r])
		{
			if (!up)
			{
				inc_mid();
				up=true;
				line[r]=line[l];
			}
			else
			{
				line[r]=line[l];
			}				
		}
		l--;
		r++;
	}

	cout << line;

	return 0;
}