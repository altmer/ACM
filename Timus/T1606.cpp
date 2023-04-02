#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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

struct Point{
	int x, y;
	int num;
	bool operator <(const Point& p) const{
		return y>p.y;
	}
};

int n;
Point arr[60000];
int ans1[60000];
int p1=0;
int ans2[60000];
int p2=0;

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i=0; i<n; ++i){
		scanf("%d%d", &arr[i].x, &arr[i].y);
		arr[i].num=i+1;
	}
	sort(arr,arr+n);

	bool more = false;
	Point cur;
	cur.y=100000;
	cur.x=0;
	cur.num=0;

	for (int i=0; i<n; ++i){
		if(more){
			Point cand=arr[i];
			int j=i+1;
			while(j<n && arr[j].y==arr[i].y){
				if(cand.x>=cur.x){
					if(arr[j].x>cand.x || arr[j].x<cur.x)
						cand=arr[j];
				}else{
					if(arr[j].x<cand.x)
						cand=arr[j];
				}
				j++;
			}
			i=j-1;
			if(cand.x<cur.x){
				ans1[p1++]=cur.num;
				cur=cand;
				more=false;
			}else if(cand.x>cur.x){
				cur=cand;
			}
		}else{
			Point cand=arr[i];
			int j=i+1;
			while(arr[j].y==arr[i].y){
				if(cand.x<=cur.x){
					if(arr[j].x<cand.x || arr[j].x>cur.x)
						cand=arr[j];
				}else{
					if(arr[j].x>cand.x)
						cand=arr[j];
				}
				j++;
			}
			i=j-1;
			if(cand.x>cur.x){
				ans1[p1++]=cur.num;
				cur=cand;
				more=true;
			}else if(cand.x<cur.x){
				cur=cand;
			}
		}
	}

	ans1[p1++]=cur.num;

	more = true;
	cur.y=100000;
	cur.x=100000;

	for (int i=0; i<n; ++i){
		if(more){
			Point cand=arr[i];
			int j=i+1;
			while(arr[j].y==arr[i].y){
				if(cand.x>=cur.x){
					if(arr[j].x>cand.x || arr[j].x<cur.x)
						cand=arr[j];
				}else{
					if(arr[j].x<cand.x)
						cand=arr[j];
				}
				j++;
			}
			i=j-1;
			if(cand.x<cur.x){
				ans2[p2++]=cur.num;
				cur=cand;
				more=false;
			}else if(cand.x>cur.x){
				cur=cand;
			}
		}else{
			Point cand=arr[i];
			int j=i+1;
			while(arr[j].y==arr[i].y){
				if(cand.x<=cur.x){
					if(arr[j].x<cand.x || arr[j].x>cur.x)
						cand=arr[j];
				}else{
					if(arr[j].x>cand.x)
						cand=arr[j];
				}
				j++;
			}
			i=j-1;
			if(cand.x>cur.x){
				ans2[p2++]=cur.num;
				cur=cand;
				more=true;
			}else if(cand.x<cur.x){
				cur=cand;
			}
		}
	}
	ans2[p2++]=cur.num;

	if(p1>p2){
		printf("%d\n", p1-1);
		for (int i=1; i<p1; ++i){
			printf ("%d ", ans1[i]);
		}
		printf("\n");
	}else{
		printf("%d\n", p2-1);
		for (int i=1; i<p2; ++i){
			printf ("%d ", ans2[i]);
		}
		printf("\n");
	}
    return 0;
}