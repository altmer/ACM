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
int A [1000][1000];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1497.in", "r", stdin);
	freopen ("T1497.out", "w", stdout);
#endif

	scanf ("%d\n", &n);

	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			scanf ("%c", &A[i][j]);
			A[i][j]-='0';
		}
		scanf ("\n");
	}

	bool fin=true;
	for (int i=0; i<n; ++i){
		int cnt=0;
		for (int j=1; j<n; ++j){
			if (A[i][j]!=A[i][j-1])
				++cnt;
		}
		if (cnt>1){
			fin=false;
			break;
		}
	}

	if (fin){
		printf ("Yes");
		return 0;
	}
	fin=true;
	for (int i=0; i<n; ++i){
		int cnt=0;
		for (int j=1; j<n; ++j){
			if (A[j][i]!=A[j-1][i])
				++cnt;
		}
		if (cnt>1){
			fin=false;
			break;
		}
	}

	if (fin)
		printf ("Yes");
	else
		printf ("No");

	return 0;
}