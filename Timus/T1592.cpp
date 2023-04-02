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

struct watch{
	int time, num, ans;
	watch(){
		time=num=ans=0;
	}
};

const int day=43200;
vector <int> v;
vector <watch> A;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1592.in", "r", stdin);
	freopen ("T1592.out", "w", stdout);
#endif

	// O(n)
	scanf ("%d", &n);
	v.resize(n);
	for (int i=0; i<n; ++i){
		int a, b, c;
		scanf ("%d:%d:%d", &a, &b, &c);
		if (a==12)
			a=0;
		v[i]=c+b*60+a*3600;
	}

	// O(n*log(n))
	sort(v.begin(), v.end());
	// O(n)
	int cnt=1;
	watch t;
	for (int i=1; i<v.size(); ++i){
		if (v[i]==v[i-1])
			++cnt;
		else{
			t.time=v[i-1];
			t.num=cnt;
			A.push_back(t);
			cnt=1;
		}
	}
	t.time=v.back();
	t.num=cnt;
	A.push_back(t);

	// O(n)

	for (int i=1; i<A.size(); ++i){
		A[0].ans+=(A[0].time-A[i].time+day)*A[i].num;
	}
	int ans=A[0].ans;
	int w=A[0].time;

	// O(n)

	for (int i=1; i<A.size(); ++i){
		A[i].ans=A[i-1].ans-(A[i-1].time-A[i].time+day)*A[i].num+(n-A[i].num)*(A[i].time-A[i-1].time);
		if (A[i].ans<ans){
			ans=A[i].ans;
			w=A[i].time;
		}
	}

	int r=w/3600;
	w%=3600;
	if (!r)
		r=12;
	printf ("%d:", r);

	r=w/60;
	w%=60;
	printf("%02d:", r);
	printf("%02d", w);

	return 0;
}