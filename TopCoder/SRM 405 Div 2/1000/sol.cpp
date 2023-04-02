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

class IdealString{
public:
	vector <int> v;
	vector <int> split (int x){
		vector <int> q;
		q.push_back(1);
		int sum=1;
		while (sum!=x){
			bool ex=true;
			for (int k=q.back()+1; k<=x-sum; ++k){
				
			}
		}
	}
	string construct(int length){
		v=split(n);
	}
};

//declarations
int n;
IdealString solve;

void input (void){
	scanf ("%d", &n);
}

void output (void){
	cout << solve.construct(n);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}