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

int A[1000][1000];
int col=1;

int main(void){
	freopen("flags.in", "r", stdin);
	freopen("flags.out", "w", stdout);

	int n;
	scanf("%d", &n);
	int tmp=0;
	for (int i=1; i<=n; ++i){
		if(i*(i-1)/2<=n){
			tmp=i;
		}
	}

	printf("%d\n", tmp);
	for (int i=1; i<=tmp; ++i){
		printf("%d ", tmp-1);
		for (int j=1; j<=tmp; ++j){
			if(i==j)continue;
			if(A[i][j]){
				printf("%d ", A[i][j]);
			}else{
				A[i][j]=A[j][i]=col++;
				printf("%d ", A[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}