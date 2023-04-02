#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <functional>
using namespace std;

int n,r,c;
int ans=1000000000;
vector<vector<char> > A;

int main(){
	freopen("class.in", "r", stdin);
	freopen("class.out","w",stdout);

	cin >> n >> r >> c;
	A.assign(r,vector<char>(c,'.'));

	n--;
	A[0][0]='#';
	int x=1,y=1;
	while(n && x<r && y<c){
		A[x][0]='#';
		n--;
		if(n){
			A[0][y]='#';
			n--;
		}
		x++; y++;
	}

	if(n){
		for (int i=0; i<r; ++i){
			for (int j=0; j<c; ++j){
				if(n && A[i][j]=='.'){
					A[i][j]='#';
					n--;
				}
			}
		}
	}

	int maxx=0;
	for (int i=0; i<r; ++i){
		int cnt=0;
		for (int j=0;j<c;++j){
			if(A[i][j]=='#'){
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}

	ans=min(maxx,ans);

	maxx=0;
	for (int i=0; i<c; ++i){
		int cnt=0;
		for (int j=0;j<r;++j){
			if(A[j][i]=='#'){
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	ans=min(maxx,ans);
	printf("%d\n", ans);
	for (int i=0; i<r; ++i){
		for (int j=0;j<c; ++j){
			printf("%c", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}