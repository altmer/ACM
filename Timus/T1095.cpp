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

int c[10];
char g[40];
int n, ost;
int t[24] = {1234, 1243, 1324, 1342, 1423, 1432,  2134, 2143, 2314, 2341, 2413, 2431, 3124, 3142, 3214, 3241, 3412, 3421, 4123, 4132, 4213, 4231, 4312, 4321};

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1095.in", "r", stdin);
	freopen ("T1095.out", "w", stdout);
#endif

	scanf ("%d", &n);

	for (int i=0; i<n; ++i){
		ost=0;
		for (int j=0; j<10; ++j)
			c[j]=0;
		scanf ("%s", g);
		for (int j=0; j<strlen(g); ++j)
			c[g[j]-'0']++;
		c[1]--;
		c[2]--;
		c[3]--;
		c[4]--;
		for (int j=1; j<10; ++j){
			for (int k=0; k<c[j]; ++k){
				ost=(ost*10+j)%7;
			}
		}
		bool fin=false;
		for (int j=0; j<24; ++j){
			int ost2=ost;
			int p=t[j];
			ost2=(ost2*10+p/1000)%7;
			p%=1000;
			ost2=(ost2*10+p/100)%7;
			p%=100;
			ost2=(ost2*10+p/10)%7;
			p%=10;
			ost2=(ost2*10+p)%7;
			if (ost2==0){
				fin=true;
				for (int l=1; l<10; ++l){
					for (int k=0; k<c[l]; ++k){
						printf ("%d", l);
					}
				}
				printf ("%d", t[j]);
				break;
			}
		}
		if (!fin)
			printf ("0\n");
		else{
			for (int j=0; j<c[0]; ++j)
				printf ("0");
			printf ("\n");
		}
	}

	return 0;
}