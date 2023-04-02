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

int A[10000];
int n, x, c, cnt;
bool inter;
vector <int> ans, ans2;

int BS (int x)
{
  int p, q, i, L;

  p = 0;   /* Left border of the search  */
  q = n-1; /* Right border of the search */
  L = 0;   /* Comparison counter         */
  while (p <= q) {
    i = (p + q) / 2;
    ++L;
    if (A[i] == x) {
      return L;
    }
    if (x < A[i])
      q = i - 1;
    else
      p = i + 1;
  }
  return 0;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1064.in", "r", stdin);
	freopen ("T1064.out", "w", stdout);
#endif

	scanf ("%d%d", &x, &c);

	for (n=1; n<=10000; ++n){
		A[n-1]=cnt++;
		if (BS(x)==c)
			ans.push_back(n);
	}

	for (int i=0; i<ans.size(); ++i){
		if (!inter){
			inter=true;
			ans2.push_back (ans[i]);
		}
		else{
			if (ans[i]-ans[i-1]!=1 ){
				ans2.push_back(ans[i-1]);
				ans2.push_back(ans[i]);
			}
		}
	}

	if (ans2.size()%2!=0){
		ans2.push_back(ans[ans.size()-1]);
	}

	printf ("%d\n", ans2.size()/2);
	for (int i=0; i<ans2.size(); i+=2){
		printf ("%d %d\n", ans2[i], ans2[i+1]);
	}

	return 0;
}