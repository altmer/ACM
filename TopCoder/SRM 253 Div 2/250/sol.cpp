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

class ObjectPacking{
public:
	int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength){
		int ans=-1;
		for (int i=0; i<boxWidth.size(); ++i){
			if ( (objWidth<=boxWidth[i]&&objLength<=boxLength[i]) || (objLength<=boxWidth[i]&&objWidth<=boxLength[i]) ){
				if (ans<0 || boxWidth[i]*boxLength[i]<ans){
					ans=boxWidth[i]*boxLength[i];
				}
			}
		}
		return ans;
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