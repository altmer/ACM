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

class RockStar{
public:
	int getNumSongs(int ff, int fs, int sf, int ss){
		int ans=ff;
		if (fs){
			ans++;
			fs--;
			ans+=ss;
			int t=min(fs, sf);
			ans+=2*t;
			fs-=t;
			sf-=t;
			if (sf)
				ans++;
		}
		else if (!ans){
			ans+=ss;
			if (sf)
				ans++;
		}
		return ans;
	}
};

//declarations
RockStar solve;

void input (void){
}

void output (void){
	cout << solve.getNumSongs(1, 2, 1, 1);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}