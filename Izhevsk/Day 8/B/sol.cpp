#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<limits>
#include<cmath>
using namespace std;

bool A[110][110];
int deg[110];
int n,m;

void del(int ind){
	for (int i=0; i<n; ++i){
		if(A[ind][i]){
			deg[ind]--;
			deg[i]--;
			A[ind][i]=A[i][ind]=false;
		}
	}
}

int main(void){
	// COMMENT THIS!!!!!!!!!!!!!!!!!!!!
	/*
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	*/

	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i){
		int fr, to;
		scanf("%d%d", &fr, &to);
		fr--; to--;
		A[fr][to]=A[to][fr]=true;
		deg[fr]++;
		deg[to]++;
	}

	bool fin=false;
	int ans=0;
	while(!fin){
		fin=true;
		int cur = 1000*1000*1000;
		int curind=-1;
		for (int i=0; i<n; ++i){
			if(deg[i] && deg[i]<cur){
				fin=false;
				cur=deg[i];
				curind=i;
			}
		}
		if(!fin){
			for (int i=0; i<n; ++i){
				if(A[curind][i]){
					++ans;
					del(i);
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}