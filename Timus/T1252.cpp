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

struct stone{
	int w, n, rn;
};
vector <stone> v, s;
vector <int> c;
int n, ans, ans1, ans2;

void count_sort (void){
	for (int i=0; i<v.size(); ++i){
		c[v[i].w]++;
	}
	for (int i=1; i<c.size(); ++i){
		c[i]+=c[i-1];
	}
	for (int i=0; i<v.size(); ++i){
		s[c[v[i].w]-1].n=v[i].n;
		s[c[v[i].w]-1].rn=n-(c[v[i].w]);
		s[c[v[i].w]-1].w=v[i].w;
	}
}

int gcd (int a, int b){
	while (b){
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1252.in", "r", stdin);
	freopen ("T1252.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);
	c.resize(150000);
	s.resize(n);
	bool sor=true;
	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i].w);
		v[i].n=i;
	}

	count_sort();

	for (int i=0; i<s.size(); ++i){
		if (s[i].n!=i){
			sor=false;
			break;
		}
	}

	if (sor){
		printf ("%d", n-1);
		return 0;
	}

	sor=true;

	for (int i=0; i<s.size(); ++i){
		if (s[i].rn!=s[i].n){
			sor=false;
			break;
		}
	}
	if (sor){
		printf ("%d", n-1);
		return 0;
	}

	for (int i=0; i<s.size(); ++i){
		ans1=gcd(max(ans1,abs(s[i].n-i)) ,min(ans1, abs(s[i].n-i)));
		ans2=gcd(max(ans2,abs(s[i].rn-s[i].n)) ,min(ans2, abs(s[i].rn-s[i].n)));
	}		

	ans=max(ans1, ans2);

	printf ("%d", ans-1);

	return 0;
}