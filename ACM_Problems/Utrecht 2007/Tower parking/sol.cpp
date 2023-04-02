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

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
	int testn;
	cin>>testn;
	for(int test=0;test<testn;test++){
		int h,l;
		int ans=0;
		cin>>h>>l;
		int m[55][55];
		int pos[55];
		int n=-1;
		for(int i=0;i<h;i++){
			pos[i]=0;
			for(int j=0;j<l;j++){
				cin>>m[i][j];
				if(m[i][j]>n)n=m[i][j];
			}
		}
		for(int car=1;car<=n;car++){
			int x,y;
			for(int i=0;i<h;i++){
				for(int j=0;j<l;j++){
					if(m[i][j]==car){
						x=i;
						y=j;
					}
				}
			}
			int dif=abs(y-pos[x]);
			dif=min(dif,abs(y+l-pos[x]));
			dif=min(dif,abs(pos[x]+l-y));
			pos[x]=y;
			ans+=dif*5;
			ans+=x*20;
		}
		cout<<ans<<endl;
	}
	return 0;
}