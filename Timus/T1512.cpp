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
vector <int> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1512.in", "r", stdin);
	freopen ("T1512.out", "w", stdout);
#endif

	scanf ("%d", &n);

	int rem=n%12;

	// even

	if (rem==3 || rem==9){
		for (int i=4; i<=n; i+=2)
			v.push_back(i);
		v.push_back(2);
	}
	else{
		for (int i=2; i<=n; i+=2){
			v.push_back(i);
		}
	}

	// odd

	if (rem==8){
		for (int i=1; i+2<=n; i+=4){
			v.push_back(i+2);
			v.push_back(i);
		}
	}
	else if (rem==2){
		v.push_back(3);
		v.push_back(1);
		for (int i=7; i<=n; i+=2)
			v.push_back(i);
		v.push_back(5);
	}
	else if (rem==3 || rem==9){
		for (int i=5; i<=n; i+=2){
			v.push_back(i);
		}
		v.push_back(1);
		v.push_back(3);
	}
	else{
		for (int i=1; i<=n; i+=2){
			v.push_back(i);
		}
	}

	for (int i=1; i<=n; ++i){
		printf ("%d %d\n", i, v[i-1]);
	}

	return 0;
}