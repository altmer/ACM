#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

int mas [1001000];
int n;
int minmax=numeric_limits<int>::max();
int maxmin=numeric_limits<int>::min();

int main (void){
	freopen ("extremum.in", "r", stdin);
	freopen ("extremum.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; ++i){
		scanf("%d", &mas[i]);
		if(i>1){
			if(mas[i-1]<mas[i] && mas[i-1]<mas[i-2]){
				maxmin=max(maxmin,mas[i-1]);
			}
			else if(mas[i-1]>mas[i] && mas[i-1]>mas[i-2]){
				minmax=min(minmax,mas[i-1]);
			}
		}
	}

	if(minmax==numeric_limits<int>::max()){
		printf("No local maximums\n");
	}
	else{
		printf("%d\n", minmax);
	}
	if(maxmin==numeric_limits<int>::min()){
		printf("No local minimums\n");
	}
	else{
		printf("%d\n", maxmin);
	}

	return 0;
}