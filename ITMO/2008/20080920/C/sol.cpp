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
#include <set>
using namespace std;
int n;
struct st{
	int x,y,num;
	bool n,e,s,w;
	st():x(0),y(0),num(0),n(0),e(0),s(0),w(0){ }
};
st mas[265000];
int bestst=-1;
int bestfin=-1;
int mind=1000000000;
char bestdir;
bool cmp1(st a, st b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	else return a.x<b.x;
}
bool cmp2(st a, st b){
	if(a.y==b.y){
		return a.x<b.x;
	}
	else return a.y<b.y;
}
void process1(){
	for(int i=1;i<n;i++){
		if(mas[i-1].x==mas[i].x){
			int dif=mas[i].y-mas[i-1].y;
			bool ok=false;
			if(dif>0 && !mas[i-1].n){
				ok=true;
			}
			else if(dif<0 && !mas[i-1].s){
				ok=true;
			}
			if(dif<0)
				dif=-dif;
			if(ok){
				int minnum=min(mas[i-1].num,mas[i].num);
				int maxnum=max(mas[i-1].num,mas[i].num);
				if(dif<mind || (dif==mind && (bestst>minnum || bestst==minnum && bestfin<maxnum))){
					st strt,fin;
					if(minnum==mas[i].num){
						strt=mas[i];
						fin=mas[i-1];
					}
					else {
						strt=mas[i-1];
						fin=mas[i];
					}
					if(strt.y-fin.y>0)
						bestdir='S';
					else bestdir='N';
					bestst=minnum;
					bestfin=maxnum;
					mind=dif;
				}
			}
		}
	}
}
void process2(){
	for(int i=1;i<n;i++){
		if(mas[i-1].y==mas[i].y){
			int dif=mas[i].x-mas[i-1].x;
			bool ok=false;
			char dir;
			if(dif>0 && !mas[i-1].e){
				ok=true;
			}
			else if(dif<0 && !mas[i-1].w){
				ok=true;
			}
			if(dif<0)
				dif=-dif;
			if(ok){
				int minnum=min(mas[i-1].num,mas[i].num);
				int maxnum=max(mas[i-1].num,mas[i].num);
				if(dif<mind || (dif==mind && (bestst>minnum || bestst==minnum && bestfin<maxnum))){
					st strt,fin;
					if(minnum==mas[i].num){
						strt=mas[i];
						fin=mas[i-1];
					}
					else {
						strt=mas[i-1];
						fin=mas[i];
					}
					if(strt.x-fin.x>0)
						bestdir='W';
					else bestdir='E';
					bestst=minnum;
					bestfin=maxnum;
					mind=dif;
				}
			}
		}
	}
}
int main (void)
{
	freopen ("c.in", "r", stdin);
	//freopen ("c.out", "w", stdout);
	scanf("%d\n",&n);
	int x(0),y(0);
	for(int i=1;i<=n;i++){
		char c;
		scanf("%c",&c);
		if(c=='N'){
			mas[i].num=i;
			++y;
			mas[i].x=x;
			mas[i].y=y;
			mas[i-1].n=true;
			mas[i].s=true;
		}
		else if(c=='S'){
			mas[i].num=i;
			--y;
			mas[i].x=x;
			mas[i].y=y;
			mas[i-1].s=true;
			mas[i].n=true;
		}
		else if(c=='E'){
			mas[i].num=i;
			++x;
			mas[i].x=x;
			mas[i].y=y;
			mas[i-1].e=true;
			mas[i].w=true;
		}
		else {
			mas[i].num=i;
			--x;
			mas[i].x=x;
			mas[i].y=y;
			mas[i-1].w=true;
			mas[i].e=true;
		}
	}
	n++;
	sort(&mas[0],&mas[n],cmp1);
	process1();
	sort(&mas[0],&mas[n],cmp2);
	process2();
	cout<<mind<<" "<<bestst<<" "<<bestfin<<" "<<bestdir<<endl;
	return 0;
}