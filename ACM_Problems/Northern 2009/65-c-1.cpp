#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct segm{
	int l, r;
	bool operator <(const segm& T){
		return l < T.l || l==T.l && r > T.r;
	}
};

struct circle{
	int x, y, r;
};

segm arr[100000];
int len;
circle cir[10000];
int n;
int h, w;
int ans = 0;
double eps=1e-8;

void fun(int cx){
	for (int i = 0; i < n; ++i){
		int h=cir[i].x-cx;
		if(h<0)h=-h;
		if(h>cir[i].r)
			continue;
		int a=int(sqrt((double)(cir[i].r*cir[i].r-h*h))+0.5);
		int x1=cir[i].y-a;
		int x2=cir[i].y+a;
		int x;
		for(x=x1-2;x<=x1+2 && sqrt( (double) ( (cir[i].x-cx)*(cir[i].x-cx)+(cir[i].y-x)*(cir[i].y-x) ) ) 
																								> cir[i].r + eps ;x++);
		segm ns;
		ns.l=x;
		for(x=x2+2;x>=x2-2 && sqrt((double)((cir[i].x-cx)*(cir[i].x-cx)+(cir[i].y-x)*(cir[i].y-x)))>cir[i].r+eps;x--);
		ns.r=x;
		if (ns.r >= 0 && ns.l < 0)
			ns.l = 0;
		if (ns.r >= w && ns.l <= w - 1)
			ns.r = w - 1;

		arr[len++]=ns;
	}
}

int main(){
	freopen("circles.in","r",stdin);
	freopen("circles.out","w",stdout);

	scanf("%d%d%d", &w, &h, &n);

	for (int i = 0; i < n; ++i){
		scanf("%d%d%d", &cir[i].y, &cir[i].x, &cir[i].r);
	}

	for (int i = 0; i < h; ++i){
		len = 0;

		fun(i);

		if(!len) continue;

		sort(arr, arr + len);

		int curleft = arr[0].l;
		int curright = arr[0].r;
		for (int j = 1; j < len; ++j){
			if (arr[j].l > curright){
				ans += curright - curleft + 1;
				curleft = arr[j].l;
				curright = arr[j].r;
			}else{
				curright = max(curright, arr[j].r);
			}
		}

		ans += curright - curleft + 1;
	}

	printf("%d\n", w * h - ans);

	return 0;
}