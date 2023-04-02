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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

int n;
char s1[1100], s2[1100], sym[1010][1010];
int num1[1010], num2[1010], par[1010][1010];

struct pos{
	int ptr1, ptr2;
	pos (int a=0, int b=0) : ptr1(a), ptr2(b) {}
	bool operator < (const pos& T) const{
		if (ptr1==T.ptr1){
			return ptr2<T.ptr2;
		}
		return ptr1<T.ptr1;
	}
};

string getans()
{
	string ans="";
	int k=n;
	int l=n;
	while (par[k][l]!=0){
		ans+=sym[k][l];
		if (par[k][l]<0){
			k--;
		}
		else
			l--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string bfs (pos u)
{
	queue<pos> q;
	q.push(u);
	while (!q.empty()){
		u = q.front();
		q.pop();
		int num_nol=num1[u.ptr1]+num2[u.ptr2];
		int num_ed=u.ptr1+u.ptr2 - num_nol;
		if (num_nol==n && num_ed==n){
			return getans();
		}
		if (u.ptr1<n){
			pos v(u.ptr1+1,u.ptr2);
			if (s1[v.ptr1]=='1'){
				if (abs(num_ed+1-num_nol)<=1 && par[v.ptr1][v.ptr2]==0){
					q.push(v);
					sym[v.ptr1][v.ptr2]='1';
					par[v.ptr1][v.ptr2]=-1;
				}
			}
			else{
				if (abs(num_nol+1-num_ed)<=1 && par[v.ptr1][v.ptr2]==0){
					q.push(v);
					sym[v.ptr1][v.ptr2]='1';
					par[v.ptr1][v.ptr2]=-1;
				}
			}
		}
		if (u.ptr2<n){
			pos v(u.ptr1,u.ptr2+1);
			if (s2[v.ptr2]=='1'){
				if (abs(num_ed+1-num_nol)<=1 && par[v.ptr1][v.ptr2]==0){
					q.push(v);
					sym[v.ptr1][v.ptr2]='2';
					par[v.ptr1][v.ptr2]=1;
				}
			}
			else{
				if (abs(num_nol+1-num_ed)<=1 && par[v.ptr1][v.ptr2]==0){
					q.push(v);
					sym[v.ptr1][v.ptr2]='2';
					par[v.ptr1][v.ptr2]=1;
				}
			}
		}
	}
	return "Impossible";
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1501.in", "r", stdin);
	freopen ("T1501.out", "w", stdout);
#endif

	s1[0]=0;
	s2[0]=0;
	scanf ("%d\n%s\n%s", &n, s1+1, s2+1);

	for (int i=1; i<=n; ++i){
		num1[i]=num1[i-1]+(s1[i]=='0');
	}
	for (int i=1; i<=n; ++i){
		num2[i]=num2[i-1]+(s2[i]=='0');
	}

	cout << bfs(pos()) << endl;

	return 0;
}