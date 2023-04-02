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

class NumericalSequence{
public:
	int makePalindrome(vector <int> v){
		deque <int> q (v.begin(), v.end());
		int res=0;
		while (!q.empty()){
			if (q.front()==q.back()){
				q.pop_back();
				if (!q.empty())
					q.pop_front();
			}
			else if (q.front()<q.back()){
				res++;
				int u=q.front();
				q.pop_front();
				u+=q.front();
				q.pop_front();
				q.push_front(u);
			}			
			else{
				res++;
				int u=q.back();
				q.pop_back();
				u+=q.back();
				q.pop_back();
				q.push_back(u);
			}
		}
		return res;
	}
};

//declarations
NumericalSequence solve;
int n;
vector <int> v;

void input (void){
	scanf ("%d", &n);
	v.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i]);
	}
}

void output (void){
	cout << solve.makePalindrome(v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}