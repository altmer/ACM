#include <iostream>
#include <string>
using namespace std;
char ch;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1219.in", "r", stdin);
	freopen ("T1219.out", "w", stdout);
#endif

	for (int i=1; i<=333333; ++i)
	{
		ch='a'+(i/676)%26;
		printf ("%c", ch);
		ch='a'+(i/26)%26;
		printf ("%c", ch);
		ch='a'+i%26;
		printf ("%c", ch);
	}

	printf ("z");

	return 0;
}