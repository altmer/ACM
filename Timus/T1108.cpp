#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int M=5000;
const int bas=1000000000;

class bignum{
public:
	int len;
	vector <long long> num;
	bignum(){
		len=0;
		num.assign(M+1, 0);
	};
	void operator ++ (){
		num[M]+=1;
		long long per=num[M]/bas;
		num[M]%=bas;
		int i=1;
		while (per){
			num[M-i]+=per;
			per=num[M-i]/bas;
			num[M-i]%=bas;
			i++;
		}
		i--;
		len=max(i, len);
	}
	void print (void){
		if (len==0){
			printf ("0\n");
			return;
		}
		printf ("%d", num[M-len+1]);
		for (int i=len-2; i>=0; --i){
			int t=bas/10;
			while (num[M-i]/t==0){
				printf ("0");
				t/=10;
			}
			printf ("%d", num[M-i]);
		}
		printf ("\n");
	}
};

bignum mult (bignum &v, bignum &u){
		bignum c;
		long long per=0;
		for (int i=0; i<v.len; ++i){
			per=0;
			for (int j=0; j<u.len; ++j){
				c.num[M-i-j]+=v.num[M-i]*u.num[M-j]+per;
				per=c.num[M-i-j]/bas;
				c.num[M-i-j]%=bas;
			}
			if (per){
				c.num[M-i-u.len]+=per;
			}
		}
		c.len=u.len+v.len;
		while (c.num[M-c.len]==0)
			c.len--;
		c.len++;
		return c;
}

bignum a, b;
int n;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1108.in", "r", stdin);
	freopen ("T1108.out", "w", stdout);
#endif

	a.len=1;
	a.num[M]=2;
	a.print();
	scanf ("%d", &n);

	for (int i=2; i<=n; ++i){
		b=a;
		b++;
		b.print();
		if (i<n)
			a=mult(a, b);
	}		
	
	return 0;
}