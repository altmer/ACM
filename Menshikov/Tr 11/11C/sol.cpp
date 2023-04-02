#include <iostream>
#include <sstream>
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
const long long bas=1000000000;
const int width=9;

class CBigInteger{
private:
	long long num[M+1];
	int len;
public:
	CBigInteger();						// пустой конструктор
	CBigInteger(const long long& x);	// инициализация числом
	CBigInteger(const string& s);		// инициализация строкой
	//арифметика
	friend  CBigInteger operator + (const CBigInteger& a, const CBigInteger& b);
	friend  CBigInteger operator - (const CBigInteger& a, const CBigInteger& b);
	friend  CBigInteger operator * (const CBigInteger& a, const CBigInteger& b);
	friend  CBigInteger operator / (const CBigInteger& a, const CBigInteger& b);
	// ввод-вывод
	friend ostream& operator << (ostream& out, CBigInteger& a);
};

CBigInteger::CBigInteger() : len(0)
{
	memset(num, 0, sizeof(num));
}

CBigInteger::CBigInteger(const long long &x) :len(0)
{
	long long t=x;
	memset (num, 0, sizeof(num));
	while (t){
		num[M-len++]=t%bas;
		t/=bas;
	}
}

CBigInteger::CBigInteger(const string& s) : len(0)
{
	memset (num, 0, sizeof(num));
	string tmp;

	int pos=0;
	int st=0;
	while (pos<s.size()&&isdigit(s[pos++]));
	tmp+=s.substr(st, pos-st);
	
	long long res=0;
	long long mult=1;
	for (int i=tmp.size()-1; i>=0; --i){
		res+=(tmp[i]-'0')*mult;
		mult*=10;
		if (res>bas){
			num[M-len]=res%bas;
			++len;
			res/=bas;
			mult=10;
		}
	}
	while (res){
		num[M-len]=res%bas;
		++len;
		res/=bas;
	}
}

 CBigInteger operator + (const CBigInteger& a,const  CBigInteger& b)
{
	CBigInteger tmp;
	int L=max(a.len, b.len);
	int car=0;
	for (int i=0; i<L; ++i){
		tmp.num[M-i]=a.num[M-i]+b.num[M-i]+car;
		car=tmp.num[M-i]/bas;
		tmp.num[M-i]%=bas;
		if (i==L-1 && car)
			++L;
	}
	tmp.len=L;
	return tmp;
}

 CBigInteger operator - (const CBigInteger& a, const CBigInteger& b)
{
	CBigInteger tmp;
	int L=max(a.len, b.len);
	int car=0;
	for (int i=0; i<L; ++i){
		tmp.num[M-i]=a.num[M-i]-b.num[M-i]+car;
		if (tmp.num[M-i]<0){
			tmp.num[M-i]+=bas;
			car=-1;
		}
		else{
			car=0;
		}
	}
	while (L>0 && tmp.num[M-L+1]==0)
		--L;
	tmp.len=L;
	return tmp;
}

CBigInteger operator * (const CBigInteger& a, const CBigInteger& b)
{
	CBigInteger tmp;
	int car=0;
	for (int i=0; i<=a.len; ++i){
		car=0;
		for (int j=0; j<=b.len; ++j){
			tmp.num[M-i-j]+=a.num[M-i]*b.num[M-j]+car;
			car=tmp.num[M-i-j]/bas;
			tmp.num[M-i-j]%=bas;
		}
	}
	tmp.len=a.len+b.len;
	while (tmp.len>0 && tmp.num[M-tmp.len+1]==0)
		--tmp.len;
	return tmp;
}

CBigInteger operator / (const CBigInteger& a, const CBigInteger& b)
{
	CBigInteger tmp;
	int car=0;

	
	tmp.len=a.len+b.len;
	while (tmp.len>0 && tmp.num[M-tmp.len+1]==0)
		--tmp.len;
	return tmp;
}

ostream& operator << (ostream& out, CBigInteger& a)
{
	if (a.len==0){
		out<<"0";
		return out;
	}
	out.width(0);
	out << a.num[M-a.len+1];
	out.width(width);
	out.fill('0');
	for (int i=a.len-1; i>0; --i){
		out << a.num[M-i+1];
	}
	return out;
}

long long P[70][70], A[70][70];
string s;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("palindr.in", "r", stdin);
	freopen ("palindr.out", "w", stdout);
#endif

	getline (cin, s);
	for (int len=1; len<=s.size(); ++len){
		for (int i=0; i<=static_cast<int>(s.size())-len; ++i){
			int j=i+len-1;
			P[i][j]=len;
			if (j>0){
				A[i][j]=A[i][j-1]+A[i+1][j]-A[i+1][j-1];
			}
			if (i!=j && s[i]==s[j]){
				A[i][j]=A[i][j]+1;
				if (len>2){
					A[i][j]=A[i][j]+P[i+1][j-1];
				}
			}
			P[i][j]=P[i][j]+A[i][j];
		}
	}

	cout << P[0][s.size()-1] << endl;

	CBigInteger a1("1234567891234"), a2("9876543219876");
	CBigInteger a3=a1*a2;

	return 0;
}