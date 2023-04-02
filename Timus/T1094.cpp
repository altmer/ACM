#include <iostream>
#include <string>
using namespace std;

char A[80];
string line;
int pos=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1094.in", "r", stdin);
	freopen ("T1094.out", "w", stdout);
#endif

	for (int i=0; i<80; ++i)
		A[i]=' ';

	getline (cin, line);
	for (int i=0; i<line.size(); ++i)
	{
		if (line[i]=='<')
			--pos;
		else if (line[i]=='>')
			++pos;
		else
			A[pos++]=line[i];
		if (pos<0)
			pos=0;
		if (pos>79)
			pos=0;
	}

	for (int i=0; i<80; ++i)	
		printf ("%c", A[i]);

	return 0;
}