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

int n;

int main(){
	freopen("holes.in", "r", stdin);
	freopen("holes.out","w",stdout);

	cin>>n;
	if(n==0){
		cout<<1<<endl;
		return 0;
	}
	if (n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n%2){
		cout<<4;
		--n;
	}

	for (int i=0;i<n/2; ++i){
		cout<<8;
	}
	cout<<endl;

	return 0;
}