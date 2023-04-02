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

int ntest, n;

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	scanf ("%d", &ntest);

	for (int test=0; test<ntest; ++test){
		scanf ("%d", &n);
		bool mis=true;
		int sum=0, k;
		for (int i=0; i<n; ++i){
			scanf ("%d", &k);
			sum^=k;
			if (k>1)
				mis=false;
		}
		if (mis){
			cout << ((sum==0) ? "John\n" : "Brother\n" );
		}
		else{
			cout << ((sum>0) ? "John\n" : "Brother\n" );
		}
	}
	

	return 0;
}