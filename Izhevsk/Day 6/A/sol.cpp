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

int curans[100000];
int tail=0;
int head=0;
bool col[30000];
int x[30000], y[30000];
int resh[30000];
int numr[7];

int gcd(int a, int b){
	while(b){
		int tmp=b;
		b = a%b;
		a = tmp;
	}
	return a;
}

int main(void){
	freopen("army.in", "r", stdin);
	freopen("army.out", "w", stdout);

	int n, m;
	scanf("%d", &n);
	m=5*n;
	int t=gcd(0,1);
	for (int i=0; i<m; ++i){
		scanf("%d%d", &x[i], &y[i]);
		x[i]+=20000;
		y[i]+=20000;
		int ind = (x[i]%2)*2+(y[i]%2);
		resh[i]=ind;
		numr[ind]++;
	}
	if(n==1){
		printf("OK\n1");
		return 0;
	}
	for (int i=0; i<=3; ++i){
		if(numr[i]>=n){
			printf("OK\n");
			int cnt=0;
			for (int j=0; j<m; ++j){
				if(resh[j]==i){
					++cnt;
					printf("%d ", j+1);
				}
				if(cnt==n)
					break;
			}
			return 0;
		}
	}

	printf("IMPOSSIBLE\n");

	return 0;
}