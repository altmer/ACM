#include <iostream>
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

class FairWorkload{
public:
	int getMostWork(vector <int> folders, int workers){
		int left=*max_element(folders.begin(), folders.end());
		int right=accumulate(folders.begin(), folders.end());
		while (left<right){
			int mid=(left+right)/2;
			int cur=0;
			int numw=1;
			for (int i=0; i<folders.size(); ++i){
				cur+=folders[i];
				if (cur>mid){
					numw++;
					cur=folders[i];
				}
			}
			if(numw<workers)
				right=mid;
			else
				left=mid+1;
		}
		return left;
	}	
};

//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}