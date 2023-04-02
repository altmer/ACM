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

int n;
int low=2;
int high=10;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	
	cin >> n;

	for (int i=0; i<n; ++i){
		int tmp;
		string s;
		cin >> tmp >> s;
		if (s=="hungry"){
			low=max(low,tmp);
		}
		else{
			high=min(high,tmp);
		}
	}
	if (low>=high){
		cout << "Inconsistent\n";
	}
	else{
		cout << high << "\n";
	}

	return 0;
}