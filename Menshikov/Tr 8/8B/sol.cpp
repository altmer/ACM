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
const int w=9;

class bignum{
private:
	int num[M+1];
	int len;
public:
	bignum();
	~bignum();
	bignum operator +(const bignum& x);
	bignum& operator = (int x);
	friend ostream& operator << (ostream& out, bignum& x);
};

bignum::bignum(){
	memset(num, 0, sizeof(num));
	len=0;
}
bignum::~bignum(){
}
bignum bignum::operator +(const bignum& x){
	int L=max(len, x.len);
	int car=0;
	bignum t;
	for (int i=0; i<L; ++i){
		t.num[M-i]=num[M-i]+x.num[M-i]+car;
		car=t.num[M-i]/bas;
		t.num[M-i]%=bas;
		if (i==L-1 && car)
			L++;
	}
	t.len=L;
	return t;
}
bignum& bignum::operator = (int x){
	while (x){
		num[M-len]=x%bas;
		x/=bas;
		len++;
	}
	return *this;
}

ostream& operator << (ostream& out, bignum& x){
	if (x.len==0){
		out << "0";
		return out;
	}
	out.width(1);
	out<<x.num[M-x.len+1];
	out.width(w);
	out.fill('0');
	for (int i=x.len-2; i>=0; --i){
		out<<x.num[M-i];
	}
	return out;
}


map <char, int> but, numb;
vector <vector <bignum> > A;
vector <int> pres;
int n;
string s;

void init (void){
	but['A']=1;
	numb['A']=1;
	but['B']=1;
	numb['B']=2;
	but['C']=1;
	numb['C']=3;
	but['D']=2;
	numb['D']=1;
	but['E']=2;
	numb['E']=2;
	but['F']=2;
	numb['F']=3;
	but['G']=3;
	numb['G']=1;
	but['H']=3;
	numb['H']=2;
	but['I']=3;
	numb['I']=3;
	but['J']=4;
	numb['J']=1;
	but['K']=4;
	numb['K']=2;
	but['L']=4;
	numb['L']=3;
	but['M']=5;
	numb['M']=1;
	but['N']=5;
	numb['N']=2;
	but['O']=5;
	numb['O']=3;
	but['P']=6;
	numb['P']=1;
	but['Q']=6;
	numb['Q']=2;
	but['R']=6;
	numb['R']=3;
	but['S']=6;
	numb['S']=4;
	but['T']=7;
	numb['T']=1;
	but['U']=7;
	numb['U']=2;
	but['V']=7;
	numb['V']=3;
	but['W']=8;
	numb['W']=1;
	but['X']=8;
	numb['X']=2;
	but['Y']=8;
	numb['Y']=3;
	but['Z']=8;
	numb['Z']=4;
}


int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("sms.in", "r", stdin);
	freopen ("sms.out", "w", stdout);
#endif

	init();

	scanf ("%d\n", &n);
	getline (cin, s);
	for (int i=0; i<s.size(); ++i){
		for (int j=0; j<numb[s[i]]; ++j){
			pres.push_back(but[s[i]]);
		}
	}
	A.resize(pres.size()+1);
	for (int i=0; i<A.size(); ++i){
		A[i].resize(n+1);
	}
	A[0][0]=1;
	for (int i=1;i<A.size(); ++i){
		for (int j=1; j<A[i].size(); ++j){
			A[i][j]=A[i-1][j-1];
			if (i-1>0 && pres[i-2]==pres[i-1]){
				A[i][j]=A[i][j]+A[i-2][j-1];
				if (i-2>0 && pres[i-3]==pres[i-1]){
					A[i][j]=A[i][j]+A[i-3][j-1];
					if (i-3>0 && (pres[i-1]==6 || pres[i-1]==8) && pres[i-4]==pres[i-1]){
						A[i][j]=A[i][j]+A[i-4][j-1];
					}
				}
			}
		}
	}

	cout << A[pres.size()][n];

	return 0;
}