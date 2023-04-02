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

class para{
public:
	char a,b;
	bool operator< (const para &t){
		if(a==t.a)return b<t.b;
		else return a<t.a;
	}
	bool operator== (const para &t)const{
		return a==t.a && b==t.b;
	}
	para(char x, char y):a(x),b(y){ }
};
int n;
vector<para> v1;
vector<para> v2;
int main(){
	freopen("enchanted.in", "r", stdin);
	freopen("enchanted.out","w",stdout);

	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;

	int n=a1.length();
	for(int i=0;i<n;i++){
		v1.push_back(para(a1[i],a2[n-1-i]));
		v2.push_back(para(b1[i],b2[n-1-i]));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(v1==v2)cout<<"Yes";
	else cout<<"No";
	return 0;
}