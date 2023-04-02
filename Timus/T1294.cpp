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

const double eps=0.01;
double ac, ad,  bc, bd, cd;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1294.in", "r", stdin);
	freopen ("T1294.out", "w", stdout);
#endif

	scanf ("%lf%lf%lf%lf", &ac, &ad, &bc, &bd);

	if (fabs(ac*ad-bc*bd)<eps){
		printf ("Impossible.");
		return 0;
	}

	cd= ((ac*ac+ad*ad)*bc*bd-(bc*bc+bd*bd)*ac*ad)/(bc*bd-ac*ad);
	if (cd<0){
		printf ("Impossible.");
	}
	else
	{
		cd=sqrt(cd)*1000;
		printf ("Distance is %.0lf km.", cd);
	}

	return 0;
}