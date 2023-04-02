#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

int num, num2, cost;
int ans = 0;

int main (void){
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);

	scanf("%d%d%d", &num, &num2, &cost);

	num+=num2;

	while(num >= cost){
		num -= cost;
		num += 1;
		ans++;
	}

	printf("%d\n", ans);

    return 0;
}