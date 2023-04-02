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

string s1;
string s2;
string s3;
string fst;
string snd;
string ans;


int main(void){
	freopen("rebus.out", "w", stdout);
	fst = "AABC";
	snd = "AABB";
	ans = "DBCB";

	for(int i=1;i<=1000;i++){
		int x = i;
		s1=fst;
		s2=snd;
		s3=ans;
		s1+="C";	
		s2+="C";	
		s3+="C";
		while(x){
			if(x&1){
				s1+="C";	
				s2+="C";	
				s3+="C";	
			}else{
				s1+="C";	
				s2+="A";	
				s3+="A";	
			}
			x/=2;
		}
		cout << s1 << fst << "+" << s2 << snd << "=" << s3 << ans << endl;
	}


	return 0;
}