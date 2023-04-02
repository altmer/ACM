#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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

int n;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int> >q;
int mas[100];
int A[12][12];
bool B[12][12];
int ptr=0;

bool on_board(int x, int y){
	return x>=0 && x<n && y>=0 && y<n;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf("%d", &n);

	for (int i=0;i<n*n;++i){
		scanf("%d", &mas[i]);
	}

	sort(mas,mas+n*n,greater<int>());
	q.push(make_pair(n/2,n/2));
	B[q.front().first][q.front().second]=true;
	while(ptr<n*n && !q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		A[u.first][u.second]=mas[ptr++];
		for (int i=0; i<4; ++i){
			pair<int,int> v(u.first+dx[i],u.second+dy[i]);
			if(on_board(v.first,v.second)&& !B[v.first][v.second]){
				B[v.first][v.second]=true;
				q.push(v);
			}
		}
	}
	for (int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}