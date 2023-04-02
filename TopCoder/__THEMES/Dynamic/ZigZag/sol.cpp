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

class ZigZag{
public:
	int longestZigZag(vector <int> seq){
		vector <int> len (seq.size()), dif(seq.size());
		len[0]=1;
		for (int i=1; i<seq.size(); ++i){
			int curb=1;
			int curdif=0;
			for (int j=0; j<i; ++j){
				int diff=seq[i]-seq[j];
				if (diff && diff*dif[j]<=0 && len[j]+1>curb){
					curb=len[j]+1;
					curdif=diff;
				}
			}
			len[i]=curb;
			dif[i]=curdif;
		}
		return *max_element(len.begin(), len.end());
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