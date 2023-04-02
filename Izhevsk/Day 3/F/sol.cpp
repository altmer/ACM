#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<limits>
#include<cmath>
using namespace std;

bool rec(int pl, int x, int y){
	if(pl==1){
		bool res2=true, res1=true;
		if(x-2>=0 && y-1>=0){
			res1 = rec(3-pl, x-2, y-1);
		}else if(x-2>=0 && y+1>=0){
			res2 = rec(3-pl, x-2,y+1);
		}
		return !res1 || !res2;
	}else{
		bool res2=true, res1=true;
		if(x-1>=0 && y-2>=0){
			res1 = rec(3-pl, x-1, y-2);
		}else if(x+1>=0 && y-2>=0){
			res2 = rec(3-pl, x+1,y-2);
		}
		return !res1 || !res2;
	}
}

int main(void){
	freopen("knights.in", "r", stdin);
	freopen("knights.out", "w", stdout);

	//for (int i=0; i<100; ++i){
	//	for (int j=0; j<100; ++j){
	//		if(rec(1,i,j)){
	//			cout << "1 ";
	//		}else{
	//			cout << "2 ";
	//		}
	//	}
	//	cout << endl;
	//}

	int n=-1;
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		int x=2*1000*1000*1000;
		int y=2*1000*1000*1000;
		for (int i=0; i<n; ++i){
			int cx, cy;
			scanf("%d%d", &cx, &cy);
			x=min(x,cx);
			y=min(y,cy);
		}
		if(((x+1)/3)*3<=y)
			cout << "Peter wins the game\n";
		else
			cout << "Andrew wins the game\n";
	}
	
	return 0;
}