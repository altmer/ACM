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

long long n;
int num=1;
long long lose = 5000000000;
map <long long, int> M;
vector <vector <int> > A;
vector <bool> win, vis;
vector <long long> numb;

bool iswin(int u){
	if(vis[u])
		return win[u];
	vis[u]=true;
	for (int i=0; i<A[u].size(); ++i){
		if (!iswin(A[u][i]))
			return win[u]=true;
	}
	return win[u]=false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	A.reserve(100000);
	numb.reserve(100000);
	scanf ("%I64d", &n);
	M[lose]=0;
	M[1]=1;
	A.push_back(vector <int>());
	numb.push_back(lose);
	A.push_back(vector <int>());
	numb.push_back(1);

	for (int i=1; i<A.size(); ++i){
		long long pos = numb[i];
		for (int j=2; j<=9; ++j){
			long long tog = pos*j;
			if (tog>=n){
				A[i].push_back(0);
			}
			else{ 
				if (!M.count(tog)){
					A.push_back(vector <int>());
					numb.push_back(tog);
					A[i].push_back(A.size()-1);
					M[tog]=A.size()-1;
				}
				else{
					A[i].push_back(M[tog]);
				}
			}
		}
	}

	vis.resize(A.size());
	vis[0]=true;
	win.resize(A.size());
	win[0]=false;

	if (iswin(1)){
		printf ("Stan wins.\n");
	}
	else{
		printf ("Ollie wins.\n");
	}

	return 0;
}