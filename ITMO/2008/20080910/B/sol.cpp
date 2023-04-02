#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

int DPH = 360/12;
int DPM = 360/30;
int DPHPM = 360/(12*30);
int minut, hour;
int deg1, deg2;

int main (void)
{
	freopen ("clock.in", "r", stdin);
	freopen ("clock.out", "w", stdout);

	scanf ("%d%d", &deg1, &deg2);

	// min - deg1, hour - deg2
	if (deg1%DPM==0){
		minut=deg1/DPM;
		if ((deg2-minut*DPHPM)%DPH==0){
			hour=(deg2-minut*DPHPM)/DPH;
			printf ("%02d:%02d", hour, minut*2);
			return 0;
		}
	}
	// min - deg2, hour - deg1
	if (deg2%DPM==0){
		minut=deg2/DPM;
		if ((deg1-minut*DPHPM)%DPH==0){
			hour=(deg1-minut*DPHPM)/DPH;
			printf ("%02d:%02d", hour,minut*2);
			return 0;
		}
	}

	printf ("No solution");

	return 0;
}