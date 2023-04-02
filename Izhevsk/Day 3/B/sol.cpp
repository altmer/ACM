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
bool state[100000];
char per[5][2][4];
int main(void){
	freopen("beavers.in", "r", stdin);
	freopen("beavers.out", "w", stdout);
	for(int i=0;i<5;i++)for(int j=0;j<2;j++)scanf("%s", per[i][j]);

	int mood=0;
	bool happy=false;
	int ind=50000;
	int cnt=0;
	while(!happy && ind>0 && ind<100000){
		++cnt;
		int ostate=state[ind];;
		int omood=mood;
		state[ind]=per[mood][state[ind]][0]-'0';
		if(per[omood][ostate][1]=='L')ind--;
		else ind++;
		if(per[omood][ostate][2]=='H')happy=true;
		if(cnt>50000000)
			break;
		mood=per[omood][ostate][2]-'A';
	}
	if(happy)cout<<"happy beaver";
	else cout<<"unhappy beaver";
	return 0;
}