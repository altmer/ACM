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

vector <int > kmp;
char x[250000], y[250000];
int n;

void pre_kmp (void){
	int i=0, j=kmp[0]=-1;
	while (i<n){
		while (j>-1 && x[i]!=x[j])
			j=kmp[j];
		i++;
		j++;
		if (x[i]==x[j])
			kmp[i]=kmp[j];
		else
			kmp[i]=j;
	}
}

int kmp_work (void){
	int i=0, j=0;
	pre_kmp();
	while (j<2*n){
		while (i>-1 && x[i]!=y[j%n])
			i=kmp[i];
		i++;
		j++;
		if (i>=n){
			return j-i;
		}
	}
	return -1;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1423.in", "r", stdin);
	freopen ("T1423.out", "w", stdout);
#endif

	scanf ("%d%s%s", &n, y, x);
	kmp.resize(n+1);

	int res=kmp_work();

	if (res<=0)
		printf ("%d", res);
	else 
		printf ("%d", n-res);


	return 0;
}