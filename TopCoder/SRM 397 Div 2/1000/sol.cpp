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

int n;
vector <int> v;
int a, b;

class CollectingMarbles{
public:
	int mostMarbles(vector <int> W, int cap, int num){
		int k=0;
		for (int cnt=0; cnt<num; ++cnt){
			sort (W.begin(), W.end());
			while (W.size()>0 && W[0]==0){
				W.erase(W.begin());
			}
			if (W.size()==0)
				break;
			vector <vector <int> > A;
			A.resize(W.size()+1);
			for (int i=0; i<A.size(); ++i){
				A[i].resize(cap+1);
				A[i][0]=1;
			}
			for (int i=1; i<=W.size(); ++i){
				int wei=W[i-1];
				for (int j=0; j<wei; ++j){
					A[i][j]=A[i-1][j];
				}
				for (int j=wei; j<=cap; ++j){
					if (A[i-1][j-wei])
						A[i][j]=A[i-1][j-wei]+1;
				}
			}
			int s=0, q=cap+1;
			int m=0;
			while (m==0){
				--q;
				for (int i=0; i<A.size(); ++i){
					if (A[i][q]>=m){
						m=A[i][q];
						s=i;
					}
				}
			}
			k+=m-1;
			while (q!=0){
				while (s>0 && A[s-1][q]==A[s][q])
					s--;
				q-=W[s-1];
				W[s-1]=0;
				s--;
			}
		}
		return k;
	}
};




void input (void){
	scanf ("%d", &n);
	v.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i]);
	}
	scanf ("%d%d", &a, &b);
}

CollectingMarbles solve;

void output (void){
	printf ("%d", solve.mostMarbles(v, a, b));
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}