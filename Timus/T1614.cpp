#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n, n2;
bool fin;
vector <vector <bool> > adj;
vector <vector <int> > A;

void rec (int row, int pos){
	if (pos==n2-1)
		return;
	if (fin)
		return;
	if (pos<n2-2){
		int ch=A[row][pos-1];
		for (int i=1; i<=n2; ++i){
			if (i!=ch && !adj[ch][i] && i!=A[row][pos+2]){
				A[row][pos]=i;
				adj[ch][i]=true;
				adj[i][ch]=true;
				rec(row,pos+1);
				if(fin)
					return;
				A[row][pos]=0;
				adj[ch][i]=false;
				adj[i][ch]=false;
			}
		}
	}
	else{
		int l=A[row][pos-1];
		int r=A[row][pos+1];
		for (int i=1; i<=n2; ++i){
			if (i!=l && i!=r && !adj[l][i] && !adj[r][i]){
				A[row][pos]=i;
				adj[l][i]=true;
				adj[i][l]=true;
				adj[r][i]=true;
				adj[i][r]=true;
				//rec(row+1, 1);
				//if(fin)
				//	return;
				//A[row][pos]=0;
				//adj[l].erase(i);
				//adj[i].erase(l);
				//adj[r].erase(i);
				//adj[i].erase(r);
				fin=true;
				return;
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1614.in", "r", stdin);
	freopen ("T1614.out", "w", stdout);
#endif

	scanf ("%d", &n);
	n2=n*2;

	adj.resize(n2+1);
	A.resize(n);
	for (int i=0; i<A.size(); ++i){
		A[i].resize(n2);
		A[i][0]=i+1;
		A[i][A[i].size()-1]=i+1+n;
	}
	for (int i=0; i<adj.size(); ++i)
		adj[i].resize(n2+1);


	for (int i=0; i<n; ++i){
		fin=false;
		rec (i, 1);
	}

	//for (int i=0; i<n; ++i){
	//	int dif=i+1;
	//	int st=i+1;
	//	int cur=i+1;
	//	for (int j=0; j<n2; ++j){
	//		if (cur<=n2){
	//			printf ("%d ", cur);
	//			cur+=dif;
	//		}
	//		else{
	//			cur=--st;
	//			printf ("%d ", cur);
	//			cur+=dif;
	//		}
	//	}
	//	printf ("\n");
	//}

	for (int i=0; i<A.size(); ++i){
		for (int j=0; j<A[i].size(); ++j){
			printf ("%d ", A[i][j]);
		}
		printf ("\n");
	}

	return 0;
}