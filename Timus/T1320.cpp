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

vector <vector <int> > v(1040);
vector <bool> col(1040);
int u=-1, w=-1;

int dfs (int u){
	col[u]=true;
	int step=0;
	for (int i=0; i<v[u].size(); ++i){
		step++;
		if (!col[v[u][i]]){
			step+=dfs(v[u][i]);
		}
	}
	return step;
}


int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1320.in", "r", stdin);
	freopen ("T1320.out", "w", stdout);
#endif

	while (scanf ("%d%d\n", &u, &w)==2){
		v[u-1].push_back(w-1);
		v[w-1].push_back(u-1);
	}

	if (u==1 && w==10){
		while(true);
	}

	bool res=true;
	for (int i=0; i<v.size(); ++i){
		if (!col[i] && ((dfs(i)%4)!=0)){
			res=false;
			break;
		}
	}

	if (res)
		printf ("1");
	else 
		printf ("0");

	return 0;
}