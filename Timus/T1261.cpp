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

const int M=1000;
int a[M+1], b[M+1];
int n, res;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1261.in", "r", stdin);
	freopen ("T1261.out", "w", stdout);
#endif

	scanf ("%d", &n);

	int t=n;
	while (t){
		++a[0];
		a[M-a[0]+1]=t%3;
		t/=3;
	}

	bool per=false;
	b[0]=a[0];
	for (int i=0; i<a[0]; ++i){
		if (a[M-i]==0){
			if (per){
				per=false;
				b[M-i]=1;
			}
			else
				b[M-i]=0;
		}
		else if (a[M-i]==1){
			if (per)
				b[M-i]=0;
			else
				b[M-i]=1;
		}
		else{
			if (per)
				b[M-i]=0;
			else{
				per=true;
				b[M-i]=0;
			}
		}
	}

	if (per){
		b[0]++;
		b[M-b[0]+1]=1;
	}
	else{
		per=true;
		for (int i=b[0]-1; i>=0; --i){
			if (b[M-i]>a[M-i]){
				per=false;
				break;
			}
			else if (b[M-i]<a[M-i]){
				break;
			}
		}
		if (per){
			b[0]++;
			b[M-b[0]+1]=1;
		}
	}

	int mult=1;
	for (int i=0; i<b[0]; ++i){
		res+=b[M-i]*mult;
		mult*=3;
	}

	printf ("%d %d", res, res-n);

	return 0;
}