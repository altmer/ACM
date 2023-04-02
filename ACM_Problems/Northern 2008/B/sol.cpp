#include <iostream>
#include <algorithm>
using namespace std;

int h,w,n;
int tree[550000];


void ins(int pos){
	while(pos>0){
		pos=pos/2;
		tree[pos]=max(tree[pos*2],tree[pos*2+1]);
	}	
}

void fnd(int x, int pos){
	if(pos>262143){
		int k=pos-262143;
		if(k>h)printf("-1\n");
		else{
		printf("%d\n",pos-262143);
		tree[pos]-=x;
		ins(pos);
		}
	}else {
		int t=pos*2;
		if(tree[t]>=x)fnd(x, t);
		else fnd(x,t+1);
	}
}

int main(){
	freopen ("billboard.in","r",stdin);
	freopen ("billboard.out","w",stdout);
	cin  >> h >> w >> n;
	for(int i=0;i<550000;i++){
		tree[i]=w;
	}
	int tmp;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tree[1]>=tmp)fnd(tmp, 1);
		else printf("-1\n");
	}
	return 0;
}