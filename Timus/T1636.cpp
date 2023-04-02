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

long long t1, t2;
long long sht;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin >> t1 >> t2;
	for (int i=0; i<10; ++i){
		long long tmp;
		cin >> tmp;
		sht+=tmp*20L;
	}
	t2-=sht;
	if (t1<=t2){
		cout << "No chance.\n";
	}
	else{
		cout << "Dirty debug :(\n";
	}


	return 0;
}