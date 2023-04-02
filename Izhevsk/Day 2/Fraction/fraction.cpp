#include <iostream>
using namespace std;

int main(){
	freopen("fraction.in","r",stdin);
	freopen("fraction.out","w",stdout);
	int n,a;
	scanf("%d%d",&n,&a);
	if(a == 0){
		printf("%d\n",n-1);
		scanf("%d\n",&a);		

	}else if(n == 0 && a == 1){
		cout << 0 << endl <<  1;
	}else {
		n++;
		printf("%d\n0 ",n);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a);
		scanf("%d\n",&a);		
	}
	return 0;
}