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

int n, b;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1448.in", "r", stdin);
	freopen ("T1448.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &b);
	int num=(n*b)/100;
	int cur=0;
	for (int i=1; i<=n; ++i){
		if ((i*b)/100>cur){
			cur++;
			printf ("1");
		}
		else{
			printf("0");
		}
	}


	return 0;
}