#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;


int main (void)
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n;
	bool first=true;
	while(cin>>n){
		if(first)first=false;
		else cout<<"\n"<<"\n";
		vector<string> s;
		s.resize(n);
		for(int i=0;i<n;i++)cin>>s[i];
		int k=s[0].length();
		string res;
		for(int i=k-1;i>=0;i--)
			for(int j=n-1;j>=0;j--)res+=s[j][i];
		while(res[res.length()-1]=='_')res.erase(res.length()-1);
		for(int i=0;i<res.length();i++){
			if(res[i]=='_')res[i]=' ';
			if(res[i]=='\\')res[i]='\n';
		}
		cout<<res << "\n";
	}
	return 0;
}