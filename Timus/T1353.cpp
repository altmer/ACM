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
int num [82];
int ans[81]={10, 45, 165, 495, 1287, 3003, 6435, 12870, 24310, 43749, 75501, 125565, 202005, 315315, 478731, 708444, 1023660, 1446445, 2001285, 2714319, 3612231, 4720815, 6063255, 7658190, 9517662, 11645073, 14033305, 16663185, 19502505, 22505751, 25614639, 28759500, 31861500, 34835625, 37594305, 40051495, 42126975, 43750575, 44865975, 45433800, 45433800, 44865975, 43750575, 42126975, 40051495, 37594305, 34835625, 31861500, 28759500, 25614639, 22505751, 19502505, 16663185, 14033305, 11645073, 9517662, 7658190, 6063255, 4720815, 3612231, 2714319, 2001285, 1446445, 1023660, 708444, 478731, 315315, 202005, 125565, 75501, 43749, 24310, 12870, 6435, 3003, 1287, 495, 165, 45, 9, 1};

int sum_digit (int x)
{
	int sum=0;
	while (x>0)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;	
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1353.in", "r", stdin);
	freopen ("T1353.out", "w", stdout);
#endif
	
/*	for (int i=1; i<=1e+9; ++i){
		int res=sum_digit(i);
		if (res<=81)
			++num[res];
	}

	for (int i=1; i<=81; ++i){
		printf ("%d, ", num[i]);
	}*/

	scanf ("%d", &n);

	printf ("%d", ans[n-1]);


	return 0;
}

