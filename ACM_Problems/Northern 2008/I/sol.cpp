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

int main(){
	freopen("important.in", "r", stdin);
	freopen("important.out","w",stdout);

	int n;
	cin>>n;
	string temp;
	getline(cin,temp);
	cout<<"Yes\n";
	for(int i=0;i<n;i++){
		char u;
		cin>>u;
		cout<<"("<<u<<" | ~"<<u<<")";
		if(i!=n-1)cout<<" & ";
		getline(cin,temp);
	}
	return 0;
}