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

unsigned long long bc[100][100];

void bin_coef(){
	bc[0][0]=1;
	for (int i=1; i<70; ++i){
		bc[i][0]=1;
		bc[i][i]=1;
		for (int j=1; j<i; ++j){
			bc[i][j]=bc[i-1][j]+bc[i-1][j-1];
		}
	}
}

unsigned long long ans;

int main(void){
	// COMMENT THIS!!!!!!!!!!!!!!!!!!!!
	/*
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	*/

	bin_coef();

	int n;
	scanf("%d", &n);

	for (int i=1; i<=n; ++i){
		ans+=bc[n][i];
	}
	cout<<ans;

	return 0;
}