#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stud
{
	int T1, T2, T3;
	bool operator < (stud s)
	{
		return T1<s.T1;
	}
};

vector <stud> v;
int n;
int time, ans=0, shift;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1193.in", "r", stdin);
	freopen ("T1193.out", "w", stdout);
#endif

	scanf ("%d", &n);
	v.resize(n);

	for (int i=0; i<n; ++i)
		scanf ("%d%d%d", &v[i].T1, &v[i].T2, &v[i].T3);

	sort (v.begin(), v.end());

	time=v[0].T1;
	for (int i=0; i<v.size(); ++i)
	{
		if (time<v[i].T1)
			time=v[i].T1;
		time+=v[i].T2;
		if (time>v[i].T3)
			shift=time-v[i].T3;
		if (shift>ans)
			ans=shift;
	}

	printf ("%d", ans);

	return 0;
}