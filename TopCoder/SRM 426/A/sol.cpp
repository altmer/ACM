#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <limits>
#include <map>
#include <list>
#include <set>
using namespace std;

class TheLuckyString{
public:
	char cnt[255];
	int all;

	int rec(char pred, int num){
		int ret=0;
		if(num==all)
			return 1;
		for (int i='a'; i<='z'; ++i){
			if(cnt[i] && i!=pred){
				cnt[i]--;
				ret+=rec(i, num+1);
				cnt[i]++;
			}
		}
		return ret;
	}
	int count(string s){
		for (int i=0; i<256; ++i)
			cnt[i]=0;
		all=s.size();
		for (int i=0; i<s.size(); ++i){
			++cnt[s[i]];
		}
		return rec('\0',0);
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