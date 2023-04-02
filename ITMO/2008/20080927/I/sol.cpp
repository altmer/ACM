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

int n;
vector <int> pr;
vector <int> ans;
bool A[110][110];

bool isprime(int x)
{
	double lim=sqrt(double(x));
	for (int i=0; i<pr.size() && pr[i]<=lim; ++i){
		if(x%pr[i]==0)
			return false;
	}
	return true;
}

void genprimes()
{
	int i=2;
	while(pr.size()<150){
		if(isprime(i))
			pr.push_back(i);
		++i;
	}
}
vector <int> tmp;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);
#endif

	genprimes();
	scanf ("%d", &n);
	int lim=n/2;
	int ptr=0;
	for (int i=1; i<=n; ++i)
		A[i][i]=true;

	ans.assign(n+1, 1);

	for (int i=1; i<=n; ++i){
		tmp.clear();
		tmp.push_back(i);
		for (int j=i+1; j<=n; ++j){
			if(!A[i][j]){
				tmp.push_back(j);
			}
			if(tmp.size()==lim){
				for (int k=0; k<tmp.size(); ++k){
					ans[tmp[k]]*=pr[ptr];
				}
				ptr++;
				for (int k=0; k<tmp.size(); ++k){
					for (int q=0; q<tmp.size(); ++q){
						A[tmp[k]][tmp[q]]=true;
						A[tmp[q]][tmp[k]]=true;
					}
				}
				tmp.clear();
				tmp.push_back(i);
				if(lim!=2)
					tmp.push_back(j);
			}
		}
		if(tmp.size()>2){
			for (int k=0; k<tmp.size(); ++k){
				ans[tmp[k]]*=pr[ptr];
			}
			ptr++;
			for (int k=0; k<tmp.size(); ++k){
				for (int q=0; q<tmp.size(); ++q){
					A[tmp[k]][tmp[q]]=true;
					A[tmp[q]][tmp[k]]=true;
				}
			}
			tmp.clear();
		}
		else if (tmp.size()==2 && !A[tmp[0]][tmp[1]]){
			for (int k=0; k<tmp.size(); ++k){
				ans[tmp[k]]*=pr[ptr];
			}
			ptr++;
			for (int k=0; k<tmp.size(); ++k){
				for (int q=0; q<tmp.size(); ++q){
					A[tmp[k]][tmp[q]]=true;
					A[tmp[q]][tmp[k]]=true;
				}
			}
			tmp.clear();
		}
	}

	for (int i=1; i<ans.size(); ++i){
		cout << ans[i] << "\n";
	}

	return 0;
}