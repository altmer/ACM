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

struct node{
	int pl, par, res;
};

vector <node> T;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1282.in", "r", stdin);
	freopen ("T1282.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	T.resize(n);
	T[0].par=-1;
	T[0].pl=1;
	T[0].res=-1;

	for (int i=1; i<n; ++i){
		char ch;
		scanf ("%c", &ch);
		if (ch=='N'){
			scanf ("%d\n", &T[i].par);
			T[i].par--;
			T[i].pl=3-T[T[i].par].pl;
			if (T[i].pl==1)
				T[i].res=-1;
			else
				T[i].res=1;
		}
		else{
			scanf ("%d %d\n",&T[i].par, &T[i].res);
			T[i].par--;
			T[i].pl=3-T[T[i].par].pl;
		}
	}

	for (int i=n-1; i>=1; --i){
		if (T[T[i].par].pl==1){
			T[T[i].par].res=max(T[T[i].par].res, T[i].res);
		}
		else{
			T[T[i].par].res=min(T[T[i].par].res, T[i].res);
		}
	}

	if (T[0].res==1){
		printf ("+1");
	}
	else{
		printf ("%d", T[0].res);
	}

	return 0;
}