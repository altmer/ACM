#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;


int n;
int pres, npres, f, s, p;
int S[4000];
deque <int> q;
vector <vector <int> > A;

void dfs (int u)
{
	for (int v=A[u].size()-1; v>=0; --v)
		dfs (A[u][v]);
	
	printf ("%d ", S[u]);
}

void make_wing (int st, int id)
{
	// left
	int i=st;
	while (S[i]<S[id])
		++i;
	if (i!=st)
	{
		A[id].push_back(i-1);
		make_wing (st, i-1);
	}
	//right
	st=i;
	while (S[i]!=S[id])
		++i;
	if (i!=st)
	{
		A[id].push_back(i-1);
		make_wing(st, i-1);
	}	
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1136.in", "r", stdin);
	freopen ("T1136.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize (n);
	for (int j=0; j<n; ++j)
		scanf ("%d", &S[j]);
	npres=n-1;
	pres=S[npres];
	
	make_wing(0, npres);

	dfs (npres);

	return 0;
}