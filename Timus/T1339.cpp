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

int n;
vector <int> boy, girl, bl, gl, ab, go;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1339.in", "r", stdin);
	freopen ("T1339.out", "w", stdout);
#endif

	scanf ("%d", &n);
	boy.assign(n, 0);
	girl.assign(n, 0);
	bl.assign(n, 0);
	gl.assign(n, 0);
	ab.assign(n, 0);
	go.assign(n, 0);

	for (int i=0; i<n; ++i){
		scanf ("%d", &boy[i]);
		if (boy[i]!=0){
			gl[boy[i]-1]=1;
		}
	}

	for (int i=0; i<n; ++i){
		scanf ("%d", &girl[i]);
		if (girl[i]!=0){
			bl[girl[i]-1]=1;
		}
	}

	bool find=true;
	while(find){
		find=false;
	for (int i=0; i<n; ++i){
		if (bl[i]==0 && boy[i]!=0 && ab[i]==0){
			int st=i;
			while(st!=-1 && boy[st] && !ab[st]){
				ab[st]=boy[st];
				go[boy[st]-1]=1;
				st=girl[boy[st]-1]-1;
				if (st>=0){
					find=true;
					bl[st]=0;
				}
			}
		}
	}
	}

	find=true;
	while(find){
		find=false;
	for (int i=0; i<n; ++i){
		if (gl[i]==0 && girl[i]!=0 && go[i]==0){
			int st=i;
			while(st!=-1 && girl[st] && !go[st]){
				go[st]=1;
				gl[girl[st]-1]=0;
				ab[girl[st]-1]=st+1;
				st=boy[girl[st]-1]-1;
				if(st>=0){
					find=true;
					gl[st]=0;
				}
			}
		}
	}
	}

	int st=0;
	while(st <n && (go[st] || gl[st]) )
		st++;
	for (int i=0; i<n; ++i){
		if (!ab[i]){
			if (boy[i]){
				ab[i]=boy[i];
				go[boy[i]-1]=1;
			}
			else{
				ab[i]=st+1;
				go[st]=1;
				while(st<n && (go[st] || gl[st]))
					st++;
			}
		}
	}

	for (int i=0; i<n; ++i){
		printf ("%d ", ab[i]);
	}

	return 0;
}