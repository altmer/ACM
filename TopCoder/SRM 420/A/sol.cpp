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

class SolitaireSimulation{
public:
	int periodLength(vector <int> heaps)
	{
		sort(heaps.begin(), heaps.end());
		vector <vector <int> > H;
		H.push_back(heaps);
		int beg, end;
		while(true){
			int nh=H.back().size();
			vector <int> v;
			for (int i=0; i<H.back().size(); ++i){
				if(H.back()[i]!=1){
					v.push_back(H.back()[i]-1);
				}
			}
			v.push_back(nh);
			sort(v.begin(), v.end());
			H.push_back(v);
			end=H.size()-1;
			beg=end-1;
			while (beg>=0 && H[beg]!=H[end])
				beg--;
			if(beg>=0)
				break;
		}
		return end-beg;
	}
};

//declarations
SolitaireSimulation solve;
vector <int> v;


void input (void){
	for (int i=0; i<50; ++i)
		v.push_back(50);
}

void output (void){
	cout << solve.periodLength(v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}