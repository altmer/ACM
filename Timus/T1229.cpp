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

vector <vector <int> > A, B;
int n, m;
int cnt=1;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1229.in", "r", stdin);
	freopen ("T1229.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	A.resize(n);
	B.resize(n);
	for (int i=0; i<n; ++i){
		A[i].resize(m);
		B[i].resize(m);
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			scanf ("%d", &A[i][j]);
		}
	}

	for (int i=0; i<n; i+=2){
		for (int j=0; j<m; j+=2){
			if (A[i][j]!=A[i][j+1] && A[i+1][j]!=A[i+1][j+1]){
				B[i][j]=cnt;
				B[i][j+1]=cnt++;
				B[i+1][j]=cnt;
				B[i+1][j+1]=cnt++;
			}
			else{
				B[i][j]=cnt;
				B[i+1][j]=cnt++;
				B[i][j+1]=cnt;
				B[i+1][j+1]=cnt++;
			}
		}
	}
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			printf ("%d ", B[i][j]);
		}
		printf ("\n");
	}


	return 0;
}