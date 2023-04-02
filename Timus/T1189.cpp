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

struct sum{
	int a, b;
	bool operator < (sum t){
		return a<t.a;
	}
};

vector <sum> v;
int n=302;

void rec (double step, int k, int ans){
	sum t;
	int q=k/11;
	if (!q){
		int w=n-ans;
		if (w%int(pow(10.0, step))==ans){
			t.a=w;
			t.b=ans;
			if (t.a>t.b)
				v.push_back(t);
		}
		return;
	}
	int w=ans+q*pow(10.0, step);
	int r=n-w;
	if (r/int(pow(10.0, step+1))==q && r%int(pow(10.0, step))==ans){
		t.a=r;
		t.b=w;
		if (t.a>t.b)
			v.push_back(t);
	}
	w=k%10;
	rec (step+1, k/10, ans+(w/2)*pow(10.0, step));
	rec (step+1, k/10, ans+(w/2+5)*pow(10.0, step));
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1189.in", "r", stdin);
	freopen ("T1189.out", "w", stdout);
#endif

	scanf ("%d", &n);

	rec (0, n, 0);

	sort (v.begin(), v.end());

	int red=0;
	for (int i=1; i<v.size(); ++i){
		if (v[i].a==v[i-1].a)
			red++;
	}
	printf ("%d\n", v.size()-red);
	for (int i=0; i<v.size(); ++i){
		if (i>0 && v[i].a==v[i-1].a)
			continue;
		printf ("%d + ", v[i].a);
		int t=v[i].a;
		int num=0;
		while (t){
			num++;
			t/=10;
		}
		num=pow(10.0, double(num-2));
		while (num>1 && v[i].b/num==0){
			printf ("0");
			num/=10;
		}
		printf ("%d = %d\n", v[i].b, n);
	}
	
	return 0;
}