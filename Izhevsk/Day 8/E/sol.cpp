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

int a[20],b[20],c[20],d[20];

long long gcd(long long a, long long b){
	while(b){
		long long tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}

long long abs2(long long x){
	if(x<0)return -x;
	else return x;
} 

int main(void){
	// COMMENT THIS!!!!!!!!!!!!!!!!!!!!
	/*
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	*/
	string s;
	cin >> s;
	int n,m;
	scanf("%d%d",&n,&m);
	int nna(0), nnc(0);
	bool null = false;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]!=0 )nna++;
		if(!a[i] && !b[i])null=true;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&c[i],&d[i]);
		if(c[i]!=0 )nnc++;
	}
	long long aprod(1), cprod(1); 
	if(s[0]=='i'){
		if(nna > nnc && !null){
			cout << "inf" << endl;
			return 0;
		}else if(nna == nnc && !null){
			for(int i=0;i<n;i++){
				if(a[i]){
					aprod*=a[i];
				}else aprod*=b[i];
			}
			for(int i=0;i<m;i++){
				if(c[i]){
					cprod*=c[i];
				}else cprod*=d[i];
			}
			long long tmp = gcd(abs2(aprod), abs2(cprod));
			if((aprod > 0 && cprod <0) || (aprod < 0 && cprod > 0))cout << "-";
			cout << abs2(aprod)/tmp << "/" << abs2(cprod)/tmp << endl;
			return 0;
		}else {
			cout << "0/1" << endl;
			return 0;
		}
	}else{
		int p;
		sscanf(s.c_str(),"%d", &p);
		aprod = 1;
		cprod = 1;
		for(int i=0;i<n;i++){
			aprod*=(a[i]*p+b[i]);
		}
		for(int i=0;i<m;i++){
			cprod*=(c[i]*p+d[i]);
		}
		if(null){
			cout << "0/1" << endl;
			return 0;
		}
		long long tmp = gcd(abs2(aprod), abs2(cprod));
		if((aprod > 0 && cprod <0) || (aprod < 0 && cprod > 0))cout << "-";
		cout << abs2(aprod)/tmp << "/" << abs2(cprod)/tmp << endl;
		return 0;
	}
	return 0;
}