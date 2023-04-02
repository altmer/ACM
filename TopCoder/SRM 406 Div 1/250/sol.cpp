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

void bt (int step, int &ans, vector <int> dogs, vector <int> v1, vector <int> v2){
	if (step==dogs.size()){
		int s1=0, s2=0, cur=0;
		int e1=v1.size()-1;
		int e2=v2.size()-1;
		for (int i=0; i<v1.size(); ++i){
			s1+=v1[i];
		}
		for (int i=0; i<v2.size(); ++i){
			s2+=v2[i];
		}
		while (e1>=0 && e2>=0){
			if (s1!=s2)
				break;
			else{
				cur++;
				s1-=v1[e1--];
				s2-=v2[e2--];
			}
		}
		if (cur>ans)
			ans=cur;
		return;
	}
	v1.push_back(dogs[step]);
	bt(step+1,ans, dogs, v1, v2);
	v1.pop_back();
	v2.push_back(dogs[step]);
	bt(step+1,ans, dogs, v1, v2);
	v2.pop_back();
}

class SymmetricPie{
public:
	int getLines(vector <int> dogs){
		sort (dogs.begin(), dogs.end());
		vector <int> v1, v2;
		int ans=0;
		bt(0,ans,dogs, v1, v2);
		return ans;
	}	
};

//declarations
int n;
vector <int> v;
SymmetricPie solve;

void input (void){
	scanf ("%d", &n);
	v.resize(n);
	for (int i=0; i<n; ++i){
		scanf ("%d", &v[i]);
	}
}

void output (void){
	cout << solve.getLines(v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}