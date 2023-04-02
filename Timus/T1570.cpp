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
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

class Dish{
public:
	long long cost, wei, num;
	string name;
};

int n,m;
vector <Dish> v;
vector <vector <long long> > C, P, UD;
vector <vector <bool> > UC;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1570.in", "r", stdin);
	freopen ("T1570.out", "w", stdout);
#endif

	cin >> n >> m;
	m*=1000;
	v.resize(n);
	for (int i=0; i<n; i++){
		double tmp;
		cin >> v[i].name >> v[i].cost >> tmp;
		v[i].wei=tmp*1000.0;
		v[i].num=0;
	}

	C.assign(n, vector <long long> (m+1, -1));
	P.assign(n,vector <long long> (m+1,0));
	UD.assign(n,vector <long long> (m+1,0));
	UC.assign(n,vector <bool> (m+1,false));

	C[0][0]=0;

	for (int i=0; i<n; ++i){
		for (int j=0; j<=m; ++j){
			if(i>0 && C[i-1][j]!=-1){
				if(C[i][j]==-1 || C[i-1][j]<C[i][j] || (C[i-1][j]==C[i][j] && UD[i-1][j]>=UD[i][j] )){
					C[i][j]=C[i-1][j];
					P[i][j]=-1;
					UD[i][j]=UD[i-1][j];
					UC[i][j]=false;
				}
			}
			if(C[i][j]!=-1){
				int to=min(m,int(v[i].wei)+j);
				if(C[i][to]==-1 || C[i][j]+v[i].cost<C[i][to] || 
					(C[i][j]+v[i].cost==C[i][to] && UD[i][j]>=UD[i][to])){
						C[i][to]=C[i][j]+v[i].cost;
						P[i][to]=to-j;
						UC[i][to]=true;
						UD[i][to]=UC[i][j] ? UD[i][j] : UD[i][j]+1;
				}
			}
		}
	}

	cout << C[n-1][m] << "\n";
	int k=n-1, l=m;
	while (P[k][l]){
		if(P[k][l]>0){
			v[k].num++;
			l-=P[k][l];
		}
		else{
			k--;
		}
	}

	for (int i=0; i<n; ++i){
		if(v[i].num){
			cout << v[i].name << " " << v[i].num << "\n";
		}
	}

	return 0;
}