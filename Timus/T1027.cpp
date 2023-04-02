#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

string line;
stack <char> s;
int i;
bool aryth, comm, err;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1027.in", "r", stdin);
	freopen ("T1027.out", "w", stdout);
#endif

	printf ("%20d", i);

	while (getline (cin, line) && !err)
	{
		for (int i=0; i<line.size(); ++i)
		{
			if (comm)
			{
				if (line[i]=='*' && i+1<line.size() && line[i+1]==')')
				{
					++i;
					comm=false;
				}
			}

			else if (aryth)
			{
				if (line[i]=='(')
				{
					if (i+1<line.size() && line[i+1]=='*')
					{
						++i;
						comm=true;
					}
					else
					{
						s.push(line[i]);
					}
				}
				else if (line[i]==')')
				{
					if (!s.empty())
					{
						s.pop();
						if (s.empty())
							aryth=false;
					}
					else
					{
						err=true;
					}
				}
				else if (!isdigit(line[i]) && line[i]!='+'&& line[i]!='-'&& line[i]!='*'&& line[i]!='/'&& line[i]!='=')
				{
					err=true;
				}
			}

			else 
			{
				if (line[i]=='(')
				{
					if (i+1<line.size() && line[i+1]=='*')
					{
						comm=true;
						++i;
					}
					else
					{
						aryth=true;
						s.push(line[i]);
					}
				}
				else if (line[i]==')')
				{
					err=true;
				}
			}
		}
	}

	if (comm|| aryth)
		err=true;

	if (err )
		printf ("NO");
	else
		printf ("YES");

	return 0;
}