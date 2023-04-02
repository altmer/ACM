#include <iostream>
using namespace std;

int n;
bool ans[200000];
int num_can[200000];
int can[200000];
char s[100];
int cnt = 0;

int main(){
	freopen("bureau.in","r",stdin);
	freopen("bureau.out","w",stdout);
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i){
		int a = 0;
		scanf("%s", s);
		if(s[0] == 'c')
			scanf("%d\n", &a);
		num_can[i] = a - 1;		
	}

	for (int i = n - 1; i >= 0; --i){
		if (can[i] > 0){
			ans[i] = false;
		}else{
			ans[i] = true;
			cnt++;
			if (num_can[i] != -1)
				can[num_can[i]]++;
		}
	}

	printf("%d\n", cnt);

	for (int i = 0; i < n; ++i)
		if(ans[i])
			printf("%d ", i + 1);

	return 0;
}