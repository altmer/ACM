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

const int M=1000;
int n, m, rem;
int num[M+1], num2[M+1], num3[M+1];

void div (int* num, int x, int& rem)
{
	int car=0;
	int todiv;
	for (int i=num[0]-1; i>=0; --i){
		todiv=car*26+num[M-i];
		num[M-i]=todiv/x;
		if (!num[M-i] &&num[M-i-1]){
			num[M-i]+=26;
			num[M-i-1]--;
		}
		car=todiv%x;
	}
	rem=car;
	while (num[0]>0 && num[M-num[0]+1]==0)
		num[0]--;
}
void inc (int* num)
{
	int car=0;
	num[M]++;
	if (num[M]>26){
		num[M]=1;
		car=1;
	}
	int i=1;
	while (car){
		num[M-i]++;
		if (num[M-i]>26){
			num[M-i]=1;
			car=1;
			++i;
		}
		else
			car=0;
	}
	if (i==num[0]+1)
		num[0]++;
}

string tostr (int* num)
{
	string res;
	for (int i=num[0]-1; i>=0; --i){
		res+=static_cast<char>(num[M-i]+'a'-1);
	}
	return res;
}

void add(int* num2, int* num)
{
	int len=max(num2[0], num[0]);
	int car=0;
	for (int i=0; i<len; ++i){
		num2[M-i]+=car+num[M-i];
		car=num2[M-i]/26;
		num2[M-i]%=26;
		if (!num2[M-i]){
			num2[M-i]+=26;
			car--;
		}
		if (i==len-1 && car)
			++len;
	}
	num2[0]=len;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1547.in", "r", stdin);
	freopen ("T1547.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	for (int i=0;i<n; ++i)
		num[M-i]=26;
	num[0]=n;

	div(num, m, rem);
	for (int i=0; i<=M; ++i){
		num3[i]=num[i];
	}
	num2[0]=1;
	num2[M]=1;
	string prev="a";
	string cur;
	for (int i=0; i<m; ++i){
		bool in=false;
		if (rem){
			inc(num3);
			in=true;
			--rem;
		}
		cur=tostr(num3);
		cout << prev << "-" << cur << "\n";
		add(num2, num);
		if (in)
			inc(num2);
		prev=tostr(num2);
		add(num3, num);
	}
	return 0;
}