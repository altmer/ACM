#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <functional>
using namespace std;

long long cnt=0;
long long sum=0;
long long n,m;
vector <long long> v;

int main(){
	freopen("key.in", "r", stdin);
	freopen("key.out","w",stdout);

	cin >> n >> m;

	v.resize(n);
	for (int i=0; i<n; ++i){
		cin >> v[i];
	}

	sort(v.begin(),v.end());

	for (int i=0; i<n; ++i){
		while(cnt<m && v[i]>sum+1){
			cout << sum+1L << ' ';
			sum+=sum+1L;
			cnt++;
		}
		sum+=v[i];
	}
	while(cnt<m){
		cout << sum+1L << ' ';
		cnt++;
		sum+=sum+1L;
	}

	return 0;
}