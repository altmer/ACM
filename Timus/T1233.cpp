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

const int N=100;
int k, m;
vector <int> cnt (N+1), kb(N+1), mb (N+1), v (N+1), t(N+1);

void set0 (vector <int> &a)
{
	for (int i=0; i<a[0]; ++i)
		a[N-i]=0;
	a[0]=0;
}

void to_big (int x, vector <int> &a)
{
	int i=N;
	while (x>0)
	{
		a[i]=x%10;
		x/=10;
		--i;
		++a[0];
	}
}

void take (int x)
{
	set0(v);
	v[0]=x;
	int len=kb[0];
	for (int i=0; i<min (x, len);++i)
	{
		v[N-x+1+i]=kb[N-len+1+i];
	}

}

void inc (vector <int> &a)
{
	int car=0;
	int i=N;
	a[i]++;
	car=a[i]/10;
	a[i]%=10;
	while (car)
	{
		--i;
		a[i]+=car;
		car=a[i]/10;
		a[i]%=10;
	}
	if (i==N-a[0])
		++a[0];
}

void dec (vector <int> &a)
{
	int car=0;
	int i=N;
	a[i]--;
	if (a[i]<0){
		car=-1;
		a[i]+=10;
	}
	while (car)
	{
		--i;
		a[i]+=car;
		if (a[i]<0){
			car=-1;
			a[i]+=10;
		}
		else
			car=0;
	}
	if (a[N-a[0]+1]==0)
		--a[0];
}

void sum (vector <int> &a, vector <int> &b)
{
	int len=max(a[0], b[0]);
	int car=0;
	for (int i=0; i<len; ++i)
	{
		a[N-i]+=b[N-i]+car;
		car=a[N-i]/10;
		a[N-i]%=10;
		if (i==len-1 && car)
			++len;
	}
	a[0]=len;
}

int cmp (vector <int> &a, vector <int> &b)
{
	int len_a=a[0];
	int len_b=b[0];

	if (len_a>len_b)
		return 1;
	else if (len_a<len_b)
		return -1;
	else
	{
		for (int i=len_a-1; i>=0; --i)
		{
			if (a[N-i]>b[N-i])
				return 1;
			else if (a[N-i]<b[N-i])
				return -1;
		}
	}
	return 0;
}

void sub (vector <int> &a, vector <int> &b)
{
	int len=a[0];
	int car=0;
	for (int i=N; i>=N-len+1; --i)
	{
		a[i]=a[i]-b[i]+car;
		if (a[i]<0){
			car=-1;
			a[i]+=10;
		}
		else
			car=0;
	}
	while (a[0] && a[N-a[0]+1]==0)
		--a[0];
}

void print (vector <int> &a)
{
	int len=a[0];
	if (len==0){
		printf ("0");
		return;
	}
	for (int i=N-len+1; i<=N; ++i)
		printf ("%d", a[i]);
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1233.in", "r", stdin);
	freopen ("T1233.out", "w", stdout);
#endif

	scanf ("%d%d", &k, &m);

	to_big (k, kb);
	to_big (m, mb);
	cnt[0]=1;
	cnt[N]=1;

	bool fin=false;
	int dig=1;
	while (!fin)
	{
		take (dig);
		
		t=v;
		
		v[N-v[0]+1]--;
		while (v[0] && v[N-v[0]+1]==0)
			--v[0];

		if (dig<kb[0])
			inc(v);

		if (dig>kb[0] && v[0]==0)
			break;			

		sum (v, cnt);

		if (dig>=kb[0])
		{
			if (cmp(cnt, mb)>0)
				break;

			int res=cmp(v, mb);
			if (dig!=1 && res>0)
			{
				fin=true;
				dec(t);
				sub(v, mb);
				sub(t, v);
				break;
			}
			else if (res==0)
			{
				if (cmp(t, kb)!=0)
					dec(t);
				fin=true;
				break;
			}
		}
		
		cnt=v;
		dig++;
	}

	if (fin)
		print(t);
	else
		printf ("0");

	return 0;
}