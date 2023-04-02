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

int ntest, n;
vector <vector <int > > boy_pref, girl_pref;
vector <int> boy_match, girl_match;

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	scanf ("%d", &ntest);

	for (int test=0; test<ntest; ++test){
		scanf ("%d", &n);
		boy_pref.assign(n, vector <int>(n,0));
		girl_pref.assign(n, vector <int>(n,0));
		boy_match.assign(n,-1);
		girl_match.assign(n,-1);

		// input girls
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				scanf ("%d", &girl_pref[i][j]);
				girl_pref[i][j]--;
			}
		}
		// input boys
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				scanf ("%d", &boy_pref[i][j]);
				boy_pref[i][j]--;
			}
		}
		bool fin=false;
		while (!fin){
			fin=true;
			for (int i=0; i<n; ++i){
				if (girl_match[i]==-1){
					fin=false;
					for (int j=0; j<n; ++j){
						int cand_boy=girl_pref[i][j];
						if (boy_match[cand_boy]==-1){
							boy_match[cand_boy]=i;
							girl_match[i]=cand_boy;
						}
						else{
							int cand_girl=boy_match[cand_boy];
							for (int k=0; k<n; ++k){
								if (boy_pref[cand_boy][k]==i){
									boy_match[cand_boy]=i;
									girl_match[i]=cand_boy;
									girl_match[cand_girl]=-1;
									break;
								}
								else if (boy_pref[cand_boy][k]==cand_girl){
									break;
								}
							}
						}
						if (girl_match[i]!=-1)
							break;
					}
				}
			}
		}
		for (int i=0; i<n; ++i){
			printf ("%d\n", girl_match[i]+1);
		}
		if (test!=ntest-1)
			printf ("\n");
	}

	return 0;
}