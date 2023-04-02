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

struct coord{
int x,y;
};

coord mas[110000];
long long mindist[110000];
int w[110000];

long long dif(coord a, coord b){
	long long dx,dy;
	dx=a.x-b.x;
	dy=a.y-b.y;
	if(dx<0)dx=-dx;
	if(dy<0)dy=-dy;
	return dx+dy;
}

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
	int testn;
	cin>>testn;
	for(int test=0;test<testn;test++){
		int n,c;
		cin>>c>>n;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&mas[i].x,&mas[i].y,&w[i]);
			mindist[i]=1000000000;
			mindist[i]*=1000000000;
		}
		for(int i=0;i<n;i++){
			long long dist=0;
			if(i>0)dist=mindist[i-1];
			int j=i,curw=0;
			coord start,prev;
			prev.x=0;
			prev.y=0;
			start=prev;
			while(curw<c && j<n){
				curw+=w[j];
				dist+=dif(prev,mas[j]);
				if(curw<=c)mindist[j]=min(mindist[j],dist+dif(mas[j],start));
				prev=mas[j];
				j++;
			}
		}
		cout<<mindist[n-1]<<endl;
		if(test!=testn-1)cout<<endl;
	}
	return 0;
}