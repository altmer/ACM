#include <iostream>
#include <sstream>
#include <cstdio>
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
#include <map>
#include <set>
using namespace std;

vector <int> cups, plsc, plnum, plcup;
vector <vector <bool> > plm;
int n, k;
int csc=-1;
int cans=-1;

int main (void)
{
	freopen ("greed.in", "r", stdin);
	freopen ("greed.out", "w", stdout);

	scanf ("%d%d", &n, &k);
	plnum.resize(k);
	for (int i=0; i<k-1; ++i){
		scanf ("%d", &plnum[i]);
	}

	for (int q=1; q<n; ++q){
		cups.assign(n, 1); // candies in cups
		plsc.assign(k, 0); // scores of players
		plcup.assign(k, 0); // number of cup where players stand
		plnum.back()=q; // number of our player
		plm.assign(k, vector <bool> (n, false)); // for detecting cycles
		int cand = n;
		while (cand){
			for (int i=0; i<k; ++i){ // moves
				if (plcup[i]!=-1){
					plcup[i]=(plnum[i]+plcup[i])%n;
					if (plm[i][plcup[i]]){
						plcup[i]=-1;
					}
					else{
						plm[i][plcup[i]]=true;
						plsc[i]+=cups[plcup[i]];
						cand-=cups[plcup[i]];
						cups[plcup[i]]=0;
					}
				}
			}
		}
		if (plsc[k-1]>csc){
			csc=plsc[k-1];
			cans=q;
		}
	}

	printf ("%d\n", cans);

	return 0;
}