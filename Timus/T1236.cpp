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


string s;
vector <int> M1, M2, K;
int N;

void rec_key (int byt)
{
	byt*=8;
	for (int i=0; i<8; ++i)
	{
		K[byt+i]=M1[byt+i]^M2[byt+i];
	}
}

void decod (int byt_key, int byt_M1)
{
	byt_key*=8;
	byt_M1*=8;
	for (int i=0; i<8; ++i)
	{
		M1[byt_M1+i]=M1[byt_M1+i]^K[byt_key+i];
	}
}

void print_key (void)
{
	for (int byt=0;byt<N; ++byt)
	{
		int tmp=0;
		int mul=128;
		for (int i=8*byt; i<8*(byt+1); ++i)
		{
			tmp+=K[i]*mul;
			mul/=2;
		}
		int A=tmp/16;
		int B=tmp%16;
		if (A>9)
			printf ("%c", 'A'+A-10);
		else
			printf ("%d", A);
		if (B>9)
			printf ("%c", 'A'+B-10);
		else
			printf ("%d", B);
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1236.in", "r", stdin);
	freopen ("T1236.out", "w", stdout);
#endif

	getline (cin, s);
	N=(s.size()+2)/2;
	M1.resize(8*N);
	M2.resize(8*N);
	K.resize(8*N);
	M1[2]=1;// space decoded
	// translation of first message
	int byt=8;
	for (int i=0;i<s.size();i+=2){
		int tmp;

		if (isalpha(s[i]))
			tmp=(s[i]-'A'+10)*16;
		else
			tmp=(s[i]-'0')*16;

		if (isalpha(s[i+1]))
			tmp+=s[i+1]-'A'+10;
		else
			tmp+=s[i+1]-'0';

		int div=128;
		for (int k=0; k<8; ++k){
			M1[byt+k]=tmp/div;
			tmp%=div;
			div/=2;
		}
		byt+=8;
	}
	// translation of second message
	getline (cin, s);
	byt=0;
	for (int i=0;i<s.size();i+=2){
		int tmp;

		if (isalpha(s[i]))
			tmp=(s[i]-'A'+10)*16;
		else
			tmp=(s[i]-'0')*16;

		if (isalpha(s[i+1]))
			tmp+=s[i+1]-'A'+10;
		else
			tmp+=s[i+1]-'0';

		int div=128;
		for (int k=0; k<8; ++k){
			M2[byt+k]=tmp/div;
			tmp%=div;
			div/=2;
		}
		byt+=8;
	}
	//solve
	rec_key (0);
	for (int i=1; i<N; ++i)
	{
		decod (i-1, i);
		rec_key(i);
	}
	//print
	print_key();

	return 0;
}