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

__int64 n, m, x, y, ans;
vector <int> p;
vector <int> num(60000);

bool isprime (int x){
	for (int i=2; i<=sqrt(double(x)); ++i){
		if (x%i==0)
			return false;
	}
	return true;
}

void gen_prime (void){
	for (int i=2; i<=60000; ++i){
		if (isprime(i))
			p.push_back(i);
	}
}

int F (__int64 x, __int64 k){
	__int64 t=0;
	__int64 u=x/k;
	while (u){
		t+=u;
		u/=k;
	}
	return t;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1055.in", "r", stdin);
	freopen ("T1055.out", "w", stdout);
#endif

	cin >> n >> m;

	if (m>=n){
		printf ("0");
		return 0;
	}

	gen_prime();

	int j=0;
	while (p[j]<=n){
		int t=F(n, p[j])-F(m, p[j])-F(n-m, p[j]);
		if (t>0)
			++ans;
		j++;
	}

	cout << ans;
	
	return 0;
}