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

long long n;

long long num1 (long long x){
	long long dig[20];
	long long cnt=0;
	long long t=x;
	int i=0;
	while (t){
		dig[i++]=t%10;
		t/=10;
	}
	long long cur;
	long long y=1;
	long long y2=10;
	for (int j=0; j<i; ++j){
		cur=x/y2+1;
		if (dig[j]==0){
			cur--;
			cnt+=cur*y;
		}
		else if (dig[j]==1){
			cur*=y;
			if (j>0){
				cur-=(y-x%y-1);
			}
			cnt+=cur;
		}
		else{
			cnt+=cur*y;
		}
		y2*=10;
		y*=10;
	}
	
	return cnt;
}

long long bs(long long L, long long R){
	R*=R;
	while (L<=R){
		long long mid=(L+R)/2;
		long long res=num1(mid);
		if (res==n){
			return mid;
		}
		else if (res<n){
			L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	return -1;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1564.in", "r", stdin);
	freopen ("T1564.out", "w", stdout);
#endif

	cin >> n; 
	long long p=num1(524638269999999991);
	long long ans=bs(0, 1e+9+1);

	if (ans==-1 || n==0){
		printf ("Petr lies");
	}
	else{
		while (num1(ans)==n)
			--ans;
		++ans;
		cout << ans;
	}

/*	int d=0;
	for (int i=1; i<=1199999; ++i){
		int u=i;
		while (u){
			if (u%10==1)
				++d;
			u/=10;
		}
	}
*/

	return 0;
}