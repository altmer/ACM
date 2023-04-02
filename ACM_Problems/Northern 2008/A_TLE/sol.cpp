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

map <long long, bool> T;
long long ONE=1;
long long tw24=ONE<<24;
long long tw16=ONE<<16;
long long tw8=ONE<<8;
int res;
long long netw(long long ip, long long mask){
	return (mask<<33) + ((ip>>(32-mask)) & ((ONE<<mask)-1));
}

int ex(long long ip, long long mask){
	for (long long i=mask; i>=0; --i){
		long long pref=netw(ip,i);
		if(T.count(pref)){
			return res=(int)T[pref];
		}
	}
	return -1;
}

int n;
long long ip, mask, val1, val2,val3,val4;
char str1[30], str2[30], str3[30];
long long nums[5];

int main(){
	freopen("access.in", "r", stdin);
	freopen("access.out","w",stdout);

	scanf("%d", &n);
	bool allow;
	for (int i=0; i<n; ++i){
		scanf("%s%s%s", str1,str2,str3);
		allow=(str1[0]=='a');
		int len=strlen(str3);
		int end=0;
		nums[0]=nums[1]=nums[2]=nums[3]=nums[4]=0;
		for (int j=0; j<len; ++j){
			if(isdigit(str3[j])){
				nums[end]=nums[end]*10+(str3[j]-'0');
			}
			else{
				end++;
			}		
		}
		
		ip=nums[0]*(tw24)+nums[1]*(tw16)+nums[2]*(tw8)+nums[3];
		if(end==4)
			mask=nums[4];
		else
			mask=32;

		if(ex(ip,mask)==-1){
			T[netw(ip,mask)]=allow;
		}
	}

	scanf("%d", &n);
	mask=32;
	for (int i=0; i<n; ++i){
		allow=true;
		scanf("%I64d.%I64d.%I64d.%I64d", &val1,&val2,&val3,&val4);
		ip=val1*(tw24)+val2*(tw16)+val3*(tw8)+val4;
		if(ex(ip,mask)!=-1){
			allow=res;
		}
		if(allow){
			printf("A");
		}
		else{
			printf("D");
		}
	}

	return 0;
}