#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct order 
{
	int num, day, cost;
};

bool sort_day (order a, order b)
{
	if (a.day==b.day)
			return a.cost>b.cost;
	return a.day<b.day;
}

bool sort_cost (order a, order b)
{
	if (a.cost==b.cost)
			return a.day<b.day;
	return a.cost<b.cost;
}


vector <order> v, u, s, ans;
vector <bool> d;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1403.in", "r", stdin);
	freopen ("T1403.out", "w", stdout);
#endif
	scanf ("%d", &n);
	d.resize(n);
	v.resize(n);
	for (int i=0; i<n; ++i)
	{
		v[i].num=i+1;
		scanf ("%d%d", &v[i].day, &v[i].cost);
	}
	s=v;
	u=v;

	int cnt=0;
	sort (v.begin(), v.end(), sort_day);
	sort (u.begin(), u.end(), sort_cost);

	for (int i=0; i<v.size(); ++i)
	{
		if (cnt<v[i].day){
			d[v[i].num-1]=true;
			++cnt;
		}
		else{
			int j=0;
			while (j<n && d[u[j].num-1]==false)
				++j;
			if (j<n && u[j].cost<v[i].cost){
				d[v[i].num-1]=true;
				d[u[j].num-1]=false;
			}
		}
	}

	for (int i=0; i<d.size(); ++i){
		if (d[i]){
			ans.push_back(s[i]);
		}
	}

	sort (ans.begin(), ans.end(), sort_day);

	printf ("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf ("%d ", ans[i].num);




	return 0;
}