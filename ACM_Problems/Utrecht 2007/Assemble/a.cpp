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

struct complect{
	bool isp;
	string name1;
	string name2;
	int cena;
	int ves;
	bool operator<(const complect &c)const{
		if(name1!=c.name1)return name1<c.name1;
		if(cena!=c.cena)return cena<c.cena;
		return ves<c.ves;
	}
};

complect v[1002];

int cnt;//Кол-во комплектующих
int sum;//Кол-во денег в кармане

int n, num, ntest;

void readNewTest();
int reshen();
//-------------------------
int main (void)
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	scanf ("%d", &ntest);

	for (int test=0; test<ntest; ++test){
		readNewTest();
		printf("%d\n",reshen());
	}

	return 0;
}
//-------------------------
void readNewTest(){
	scanf("%d%d",&cnt,&sum);
	for(int i=0;i<cnt;++i){
		cin>>v[i].name1>>v[i].name2>>v[i].cena>>v[i].ves;
		v[i].isp=false;
	}
	sort(v,v+cnt);
}
//-------------------------
int reshen(){
	v[0].isp=true;
	int cena=v[0].cena;
	int minVes=v[0].ves;
	for(int i=1;i<cnt;++i){
		if(v[i].name1!=v[i-1].name1){
			v[i].isp=true;
			minVes=min(minVes,v[i].ves);
			cena+=v[i].cena;
		}
	}
	// Собственно пытаемся улучшить существующее положение
	while(true){
		for(int i=1;i<cnt;++i){
			if(v[i-1].isp && v[i-1].ves<=minVes){
				if(v[i-1].name1==v[i].name1){
					v[i-1].isp=false;
					v[i].isp=true;
					cena-=v[i-1].cena;
					cena+=v[i].cena;
					//if(v[i].ves>minVes)
					//	tmpVes=min(tmpVes,v[i].ves);
				}else{// Не можем улучшить один из компонентов
					return minVes;
				}
			}
		}
		if(v[cnt-1].isp&&v[cnt-1].ves<=minVes)// Не можем улучшить последний из компонентов
			return minVes;
		if(cena>sum)// На это улучшение у нас нет денег
			return minVes;

		minVes=1000000001;
		for(int i=0;i<cnt;++i){
			if(v[i].isp)
				minVes=min(minVes,v[i].ves);
		}
	}
}