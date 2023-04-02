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
int A[3000];
pair<int,int> B[3000];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; ++i){
		cin >> A[i];
	}

	for (int i=0; i<n; ++i){
		int k=A[i]-1;
		B[k].first=B[k].second=1;
		for (int j=0; j<n; ++j){
			if (i!=j){
				int bef=A[j]-A[i];
				int now=j-i;
				if (bef*now>0){
					B[k].second++;
				}
				else if (bef<0){
					// nothing
				}
				else if (now<0){
					B[k].first++;
					B[k].second++;
				}
			}
		}
	}

	for (int i=0; i<n; ++i){
		cout << B[i].first << ' ' << B[i].second << endl;
	}

	return 0;
}