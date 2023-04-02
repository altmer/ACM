#include<iostream>
using namespace std;

unsigned long long a, p;

unsigned long long pow(unsigned long long a, unsigned long long step){
	unsigned long long ret=1;
	while(step){
		if(step&1){
			ret*=a;
			ret%=p;
			step--;
		}else{
			a*=a;
			a%=p;
			step>>=1;
		}
	}
	return ret;
}

int main(void){
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int i=0; i<t; ++i){
		cin >> a >> p;
		if(p==2) cout << "Yes\n";
		else{
			if(pow(a, (p-1)/2)==1) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}