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

stack <int> s;
int n;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1494.in", "r", stdin);
	freopen ("T1494.out", "w", stdout);
#endif
	
	scanf ("%d", &n);

	int beg=1;
	for (int i=0; i<n; ++i){
		int cur;
		scanf ("%d", &cur);
		for (int j=beg; j<=cur; ++j){
			s.push(j);
		}
		beg=max(beg, cur+1);
		if (s.top()==cur)
			s.pop();
	}

	if (s.empty())
		printf ("Not a proof");
	else
		printf ("Cheater");
	
	return 0;
}