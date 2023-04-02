#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
using namespace std;

int sut=24*60;
int maxint=numeric_limits<int>::max();
int ans=maxint;
int n;
vector <vector <int> > T;
vector <int> dist(n);

int obh (int len)
{
	for (int i=1; i<n-1; ++i){
		int minn=maxint;
		for (int j=0; j<T[i].size(); ++j){
			int rast;
			if (len<sut){
				rast=T[i][j]-(len);
			}
			else{
				rast=(T[i][j]%sut)-(len%sut);
			}
			if(rast<0) rast+=sut;
			minn=min(minn,rast);
		}
		len+=minn+dist[i];
	}
	return len;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	scanf ("%d", &n);
	
	T.resize(n);
	dist.assign(n,0);

	for (int i=0; i<n-1; ++i){
		int q, d;
		scanf ("%d%d%d", &q, &d, &dist[i]);
		for (int j=0; j<q; ++j){
			int h, m;
			scanf ("%d:%d", &h, &m);
			T[i].push_back(h*60+m+d);
		}
	}

	for (int i=0; i<T[0].size(); ++i){
		ans=min(ans, obh(T[0][i]+dist[0]));
	}

	printf ("%d\n", ans);	

	return 0;
}