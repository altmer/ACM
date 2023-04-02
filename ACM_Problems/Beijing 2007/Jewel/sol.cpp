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

int n, a;
double b;

double Prob (double p)
{
	return 1.0/(1.0+exp(b*log(static_cast<double>(p-a))));
}

int main (void)
{
	freopen ("input.txt", "r", stdin);
	freopen ("trade.out", "w", stdout);

		scanf ("%d%d%lf", &n, &a, &b);
		double p=a;
		for (int i=2; i<=n; ++i){
			int pProp=static_cast <int> (p+1.0);
			double cur=p;
			while (true){
				double pExp=p+(pProp-p)*Prob(pProp);
				if (pExp<cur)
					break;
				cur=pExp;
				pProp+=1;
			}
			p=cur;
		}
		printf ("%.2lf\n", p);

	return 0;
}