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

int k, s, ans;
vector <int> v, a;

bool isprime (int x){
	for (int i=2; i<=sqrt(double(x)); ++i){
		if (x%i==0){
			return false;
		}
	}
	return true;
}

void rec (int num, int x, int step){
	a.push_back(x);
	if (ans>=10000)
		return;
	if (step==k){
		bool fin=true;
		for (int i=0; i<num; ++i){
			fin=false;
			for (int j=0; j<a.size(); ++j){
				if (a[j]%v[i]!=0){
					fin=true;
					break;
				}
			}
			if (!fin)
				break;
		}
		if (fin)
			++ans;
		a.pop_back();
		return;
	}

	x+=v[num];
	while (x<=s-(k-step-1)*v[num]){
		rec(num, x, step+1);
		x+=v[num];
	}
	if (ans>=10000)
		return;
	a.pop_back();
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1091.in", "r", stdin);
	freopen ("T1091.out", "w", stdout);
#endif

	scanf ("%d%d", &k, &s);
	for (int i=2; i<=s/k; ++i){
		if (isprime(i))
			v.push_back(i);
	}

	for (int i=0; i<v.size(); ++i){
		int t=v[i];
		while (t<=s){
			rec (i, t, 1);
			t+=v[i];
			if (ans>=10000)
				break;
		}	
		if (ans>=10000)
			break;
	}

	if (ans>10000)
		ans=10000;
	printf ("%d", ans);

	return 0;
}