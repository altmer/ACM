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

int n, m, l1, c1, l2, c2, ans;
int lev=0;
bool fn, fm;
vector <int> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1302.in", "r", stdin);
	freopen ("T1302.out", "w", stdout);
#endif

	v.push_back(0);
	v.push_back(1);
	int d=3;
	int x=0;
	while (x<1e+9){
		x=v[v.size()-1]+d;
		v.push_back(x);
		d+=2;
	}

	scanf ("%d%d", &n, &m);
	int t=m;
	m=max(t, n);
	n=min(t, n);

	for (int i=1; i<v.size(); ++i){
		if (v[i]>=n && !fn){
			fn=true;
			int x=v[i-1]+1;
			if ((n-x)%2==0){
				l1=lev+1;
				c1=(n-x)/2+1;
			}
			else{
				l1=lev;
				c1=(n-x)/2+1;
			}
		}
		if (v[i]>=m && !fm){
			fm=true;
			int x=v[i-1]+1;
			if ((m-x)%2==0){
				l2=lev+1;
				c2=(m-x)/2+1;
			}
			else{
				l2=lev;
				c2=(m-x)/2+1;
			}
		}
		if (fn && fm)
			break;
		lev+=2;
	}

	if (l1!=l2){
		if (c1!=c2){
			int dif_c=abs(c2-c1);
			int dif_l=abs(l2-l1);
			dif_c-=dif_l/2;
			if (dif_l%2!=0 && l1%2==0)
				dif_c--;
			if (dif_c<0)
				dif_c=0;
			ans=dif_l+dif_c*2;
		}
		else{
			ans=abs(l2-l1);
		}
	}
	else{
		ans=abs(c2-c1)*2;
	}

	printf ("%d", ans);

	return 0;
}