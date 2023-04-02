#include <iostream>
#include <string>
using namespace std;

const int M=55;
int A[M], ans;
string line;

void divshort (int divisor, int &rem)
{
	int i;
	rem=0;
    for (int i=M-A[0]; i<=M-1; ++i)
	{
		rem=rem*10+A[i];
		A[i]=rem/divisor;
		rem=rem%divisor;
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1243.in", "r", stdin);
	freopen ("T1243.out", "w", stdout);
#endif

	getline (cin, line);

	for (int i=line.size()-1; i>=0; --i)
		A[M-line.size()+i]=line[i]-'0';
	A[0]=line.size();

	divshort (7, ans);
	printf ("%d", ans);

	return 0;
}