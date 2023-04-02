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

int n, ans;
vector <int> D, C;
bool fin;

void hanoi (int n, int from, int to, int temp){
	if (fin)
		return;
	if (n>0){
		if (D[n]==to){
			ans+=pow(2.0, double(n-1));
			hanoi (n-1, temp, to, from);
		}
		else if (D[n]==temp){
			printf ("-1");
			fin=true;
		}
		else{
			hanoi(n-1, from, temp, to);
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1054.in", "r", stdin);
	freopen ("T1054.out", "w", stdout);
#endif

	scanf ("%d", &n);
	D.resize(n+1);
	C.resize(n+1);

	fin=true;
	for (int i=1; i<=n; ++i){
		scanf ("%d", &D[i]);
		C[i]=1;
		if (C[i]!=D[i])
			fin=false;
	}

	if (!fin){
		hanoi (n, 1, 2, 3);
		if (!fin){
			printf ("%d", ans);
		}
	}
	else
		printf ("0");

	return 0;
}