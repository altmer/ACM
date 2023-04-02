#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class ContiguousCacheEasy{
public:
	int bytesRead(int n, int k, vector <int> A){
		k--;
		int st=0;
		int end=k;
		int ans=0;
		for (int i=0; i<A.size(); ++i){
			if (A[i]>end){
				ans+=min(A[i]-end, k+1);
				end=A[i];
				st=end-k;
			}
			else if (A[i]<st){
				ans+=min(st-A[i], k+1);
				st=A[i];
				end=st+k;
			}
		}
		return ans;
	}	
};

//declarations
ContiguousCacheEasy solve ;
int n, k;
vector <int> v;

void input (void){
	scanf ("%d%d", &n, &k);
	v.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i]);
	}
}

void output (void){
	cout << solve.bytesRead(n, k, v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}