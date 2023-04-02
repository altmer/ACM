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
const int MXSZ=100100;
int n,m;
int ao[MXSZ],bo[MXSZ],an[MXSZ],bn[MXSZ];
int a[MXSZ],b[MXSZ];
long long d[1000100];
void destroy(){
	sort(&ao[0],&ao[n]);
	sort(&bo[0],&bo[m]);
	int i=0;
	int nn(0),mm(0);
	while(i<n){
		int cur=ao[i];
		a[nn]=cur;
		while(i<n && ao[i]==cur){
			an[nn]++;
			i++;
		}
		nn++;
	}
	n=nn;
	i=0;
	while(i<m){
		int cur=bo[i];
		b[mm]=cur;
		while(i<m && bo[i]==cur){
			bn[mm]++;
			i++;
		}
		mm++;
	}
	m=mm;
}
int main(){
	freopen("deposits.in", "r", stdin);
	freopen("deposits.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&ao[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",&bo[i]);
	destroy();
	for(int i=0;i<n;i++){
		double lim=sqrt((double)a[i]);
		int lev=(int)(lim+0.5);
		if(lev*lev==a[i]){
			d[lev]+=an[i];
			lev--;
		}
		for(int x=1;x<=lev;x++){
			if(a[i]%x==0){
				d[x]+=an[i];
				d[a[i]/x]+=an[i];
			}
		}
	}
	long long ans=0;
	for(int i=0;i<m;i++){
		ans+=d[b[i]]*(long long)bn[i];
	}
	cout<<ans;
	return 0;
}