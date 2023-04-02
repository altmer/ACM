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

const int MAX=1e+9;
int ans, cur, num=1, n, k;
vector <int> v, A, B;

void merge (int l, int mid, int r){
	int n1=mid-l+1;
	int n2=r-mid;
	for (int i=0; i<n1; ++i){
		A[i]=v[l+i];
	}
	for (int i=0; i<n2; ++i){
		B[i]=v[mid+i+1];
	}
	A[n1]=MAX;
	B[n2]=MAX;
	int q=0;
	int w=0;
	for (int k=l; k<=r; ++k){
		if (A[q]<B[w]){
			v[k]=A[q];
			++q;
		}
		else{
			cur+=n1-q;
			v[k]=B[w];
			++w;
		}
	}
}

void merge_sort (int l, int r){
	if (l<r){
		int mid=(l+r)/2;
		merge_sort (l, mid);
		merge_sort (mid+1, r);
		merge (l, mid, r);
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1090.in", "r", stdin);
	freopen ("T1090.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &k);
	v.resize(n);
	A.resize(n);
	B.resize(n);

	for (int i=0; i<k; ++i){
		cur=0;
		for (int j=0; j<n; ++j){
			scanf ("%d", &v[j]);
		}
		merge_sort (0, n-1);
		if (cur>ans){
			ans=cur;
			num=i+1;
		}
	}

	printf ("%d", num);

	return 0;
}