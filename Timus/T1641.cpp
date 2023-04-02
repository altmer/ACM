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


int kab[200];
bool d[200];
bool A[200][200];
int n, k, m;
int dej=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	cin >> n >> k >> m;

	for (int i=0; i<n; ++i){
		kab[i]=(i%k)+1;
		cout << kab[i] << endl;
	}
	for (int i=0; i<m; ++i){

		for (int j=0; j<n; ++j){
			if (d[j] && dej<n)
				continue;
			for (int p=0; p<n; ++p){
				if (n-dej>(m-i) && d[p] && dej<n){
					continue;
				}
				if (kab[p]!=kab[j] && !A[p][j]){
					dej+=!d[j]+!d[p];
					d[j]=d[p]=true;
					A[p][j]=A[j][p]=true;
					cout << j+1 << ' ' << p+1 << endl;
					goto endf;
				}
			}
		}
		endf:	;
	}

	if (dej<n){
		n=0;
		cout << 1/n;
	}

	return 0;
}