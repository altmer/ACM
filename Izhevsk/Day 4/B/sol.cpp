#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<limits>
#include<cmath>
using namespace std;

int main(void){
	freopen("beautifulgraph.in", "r", stdin);
	freopen("beautifulgraph.out", "w", stdout);
	int n;
	cin>>n;
	if(n==1)cout<<"1 0";
	else if(n==2)cout<<"2 1\n1 2";
	else if(n==3)cout<<"3 3\n1 2\n2 3\n1 3";
	else {
		cout<<n<<" "<<(n-2)*2<<endl;
		for(int i=3;i<=n;i++)
			cout<<i<<" "<<1<<endl<<i<<" "<<2<<endl;
	}
	return 0;
}