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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

struct edge{
	int fr, to;
	edge(int a=0, int b=0):fr(a), to(b) {}
};

int A[1010][1010];
int st, n;
vector <edge> ans;
stack<int> q, res;

void euler(){
	q.push(st);
	while(!q.empty()){
		int u=q.top();
		bool found=false;
		for (int v=0; v<n; ++v){
			if(!A[u][v]){
				A[u][v]=1;
				q.push(v);
//				ans.push_back(edge(u+1,v+1));
				found=true;
				break;
			}
		}
		if(!found){
			res.push(u);
			q.pop();
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1176.in", "r", stdin);
	freopen ("T1176.out", "w", stdout);
#endif

	ans.reserve(40000);
	scanf ("%d%d", &n, &st);
	st--;

	for (int i=0; i<n; ++i){
		for (int j=0; j<n; j++){
			scanf ("%d", &A[i][j]);
			if(i==j){
				A[i][j]=1;
			}
		}
	}

	euler();
/*
	for (int i=0; i<ans.size(); ++i){
		printf ("%d %d\n", ans[i].fr,ans[i].to);
	}
	//*/

	int prev=res.top();
	res.pop();
	while(!res.empty()){
		int cur=res.top();
		res.pop();
		printf ("%d %d\n", prev+1, cur+1);
		prev=cur;
	}
	return 0;
}