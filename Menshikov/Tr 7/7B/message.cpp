#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int M=1000;
const int bas=1e+9;
const int wid=9;

class bignum{
private:
	int* num;
	int len;
public:
	bignum(){
		num = new int[M+1];
		for (int i=0; i<M+1; ++i){
			num[i]=0;
		}
		len=0;
	}
	bignum (int x){
		num= new int[M+1];
		for (int i=0; i<M+1; ++i){
			num[i]=0;
		}
		len=0;
		while (x){
			num[M-len]=x%bas;
			x/=bas;
			++len;
		}
	}
	bignum operator + (const bignum &b){
		bignum res;
		int car=0;
		int L=max(len, b.len);
		for (int i=0; i<L; ++i){			
			res.num[M-i]=num[M-i]+b.num[M-i]+car;
			car=res.num[M-i]/bas;
			res.num[M-i]%=bas;
			if (i==L-1 && car)
				++L;
		}
		res.len=L;
		return res;
	}
	friend ostream& operator << (ostream& out, bignum& a);
};

ostream& operator << (ostream& out, bignum &a){
	out.width(1);
	if (a.len==0){
		out << "0";
		return out;
	}
	out<<a.num[M-a.len+1];
	out.width(wid);
	out.fill('0');
	for (int i=a.len-2; i>=0; --i){
		out << a.num[M-i];
	}
	return out;
}

vector <bignum> v;
string s;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("message.in", "r", stdin);
	freopen ("message.out", "w", stdout);
#endif

	getline (cin, s);
	v.resize(s.size()+1);
	v[0]=bignum(1);
	v[1]=bignum(1);
	for (int i=2; i<v.size(); ++i){
		string sub=s.substr(i-2, 2);
		if (sub>="10" && sub<="33"){
			v[i]=v[i-1]+v[i-2];
		}
		else
			v[i]=v[i-1];
	}
	cout << v.back();

	return 0;
}