#include <iostream>
#include <cmath>
using namespace std;

int A[10];
double x, y;
char ch;
const double diag = sqrt(2.0)/(2.0);

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1413.in", "r", stdin);
	freopen ("T1413.out", "w", stdout);
#endif

	while (cin.get(ch) && ch!='0')
		++A[ch-'0'];
	
	y=(A[8]-A[2])+diag*(A[9]-A[1])+diag*(A[7]-A[3]);
	x=(A[6]-A[4])+diag*(A[9]-A[1])+diag*(A[3]-A[7]);

	printf ("%.10lf %.10lf", x, y);

	return 0;
}