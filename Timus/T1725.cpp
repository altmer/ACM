#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &k);

	if (n == 2){
		printf("0\n");
		return 0;
	}

	if(k > n /2 ) k = n - k + 1;

	printf("%d\n", n - k - 2);
	
	return 0;
}