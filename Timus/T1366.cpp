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

const int M=1000;
const int bas=1e+9;

struct bignum{
	int len;
	vector <long long> num;
	bignum(){
		len=0;
		num.assign(M+1, 0);
	}
	void operator =(bignum t){
		len=t.len;
		num.swap(t.num);
	}
	void add (bignum &a, bignum &b){
		int l=max(a.len, b.len);
		int carry=0;
		for (int i=0; i<l; ++i){
			num[M-i]=a.num[M-i]+b.num[M-i]+carry;
			carry=num[M-i]/bas;
			num[M-i]%=bas;
			if (i==l-1 && carry)
				++l;
		}
		len=l;
	}
	void mult (int x){
		int carry=0;
		for (int i=0; i<len; ++i){
			num[M-i]=num[M-i]*x+carry;
			carry=num[M-i]/bas;
			num[M-i]%=bas;
			if (i==len-1 && carry){
				++len;
			}
		}
	}
	void print (void){
		if (len==0){
			printf ("0");
			return;
		}
		printf ("%d", num[M-len+1]);
		for (int i=len-2; i>=0; --i){
			printf ("%09d", num[M-i]);
		}
	}
};

bignum a, b, c;
int n;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1366.in", "r", stdin);
	freopen ("T1366.out", "w", stdout);
#endif

	a.num[1000]=1;
	b.num[1000]=0;
	a.len=1;
	b.len=0;

	scanf ("%d", &n);

	for (int i=2; i<=n; ++i){
		c.add(a, b);
		c.mult(i-1);
		a=b;
		b=c;
	}

	b.print();

	return 0;
}