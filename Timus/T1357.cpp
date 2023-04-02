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
#pragma comment(linker, "/STACK:16777216")
using namespace std;

double C = 4190.0;
double m = 0.2;
double Tb = 20.0;
double P=400.0;
double eps=1e-10;

int num=0;
int n;

class teapot{
public:
	double wat;
	double T;
	double ct;
	teapot() : wat(0), T(0), ct(0) {}
	double boil(){
		double ddT=100.0-T;
		double dt=(wat*C*ddT)/(P);
		return ct+dt;
	}
	void run(double time){
		if(wat<=eps){
			ct=time;
			return;
		}
		double dt=time-ct;
		double ddT=(P*dt)/(wat*C);
		T+=ddT;
		ct=time;
	}
	void add (){
		T = (wat*T+m*Tb)/(wat+m);
		wat+=m;
		++num;
	}
	void print(double time){
		ct=time;
		int tmp=ceil(time);
		for (int i=0; i<num; ++i){
			printf ("%02d:%02d:%02d\n", (tmp/3600)%24, (tmp%3600)/60, tmp%60);
		}
//		ct=tmp;
		num=0;
		T=0;
		wat=0;
	}
};

teapot solve;
int q;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1357.in", "r", stdin);
	freopen ("T1357.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	for (int i=0; i<n; ++i){
		int a, b, w;
		scanf ("%d:%d:%d\n", &a, &b, &w);
		double time=a*3600+b*60+w;
		bool fin=false;
		while(!fin){
			if(time+eps>solve.boil() || fabs(solve.boil()-time)<=eps){
				solve.print(solve.boil());
				fin=true;
				while(fabs(solve.wat-1.0)>eps && q ){
					fin=false;
					solve.add();
					q--;
				}
			}
			else
				fin=true;
		}
		solve.run(time);
		if(fabs(solve.wat-1.0)<=eps){
			q++;
		}
		else{
			solve.add();
		}
	}
	
	solve.print(solve.boil());
	while(q){
		solve.add();
		q--;
		if(fabs(solve.wat-1)<=eps){
			solve.print(solve.boil());
		}
	}
	solve.print(solve.boil());

	return 0;
}