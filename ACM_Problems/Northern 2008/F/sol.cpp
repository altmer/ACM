#include <iostream>
#include <algorithm>
using namespace std;

long long mas[100100];
int n;

int main(){
	freopen ("fenwick.in","r",stdin);
	freopen ("fenwick.out","w",stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; ++i){
		scanf("%I64d", &mas[i]);
		long long sum=0;
		for (int j=1; (i&j)==0; j<<=1){
			sum+=mas[i-j];
		}
		mas[i-1]-=sum;
	}

	for (int i=1; i<=n; ++i){
		printf("%I64d ",mas[i]);
	}

	return 0;
}