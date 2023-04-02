#include <iostream>
#include <algorithm>
#pragma comment(linker,"/STACK:65000000")
using namespace std;

long long n,l,r;
unsigned long long primes[60];
long long ans;
int q=0;

long long num(long long x){
	return r/x-l/x + (l%x==0);
}
int mas[11][5000000];
int p[11];

unsigned long long pr[60];

void rec(unsigned long long cur, int pos, int len){
	for(int i=pos;i<q;i++){
		if(cur*primes[i]<=r){
			rec(cur*primes[i], i+1, len+1);
		}
	}
	mas[len][p[len]++]=cur;
}



int main(){
	freopen("divisibility.in","r",stdin);
	freopen("divisibility.out","w",stdout);
	cin >> n >> l >> r;
	for(int i=0;i<n;i++){
		cin >> pr[i];
	}
	sort(pr, pr+n);
	primes[q]=pr[0];
	for(int i = 1;i<n;i++){
		if(pr[i]!=primes[q]){
			primes[++q]=pr[i];
		
		}
	}
	q++;

	for(int i=0;i<q;i++){
		rec(primes[i], i+1, 1);
	}
	ans=r-l+1;
	for(int i=1;i<11;i++){
		if(i%2)for(int j=0;j<p[i];j++){
			ans-=num(mas[i][j]);
		}else for(int j=0;j<p[i];j++){
			ans+=num(mas[i][j]);
		}
	}
	cout << ans;
	return 0;
}