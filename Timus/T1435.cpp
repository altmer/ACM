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
#pragma comment(linker, "/STACK:65777216")
using namespace std;

char nums[200100][11];
long long val[200100];
int lens[200100];
long long sum, sumt;
long long step[14];

long long strtoint(char* s){
	int len = strlen(s);
	long long ret=0;
	for (int i=0; i<len; ++i){
		ret=ret*10+s[i]-'0';
	}
	return ret;
}


int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	step[0]=1;
	for (int i=1; i<14; ++i){
		step[i]=step[i-1]*10;
	}

	gets(nums[0]);
	int n = strtoint(nums[0]);

	for (int i=0; i<n; ++i){
		gets(nums[i]);
		val[i] = strtoint(nums[i]);
		lens[i] = strlen(nums[i]);
		sum+=val[i];
	}

	gets(nums[200090]);
	sumt=strtoint(nums[200090]);

	if(sumt==sum){
		puts("Input has no error.");
		return 0;
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<lens[i]-1; ++j){
			if(j==0 && nums[i][j+1]=='0')
				continue;
			long long diff = ((nums[i][j+1])-(nums[i][j]))*step[lens[i]-j-1] + ((nums[i][j])-(nums[i][j+1]))*step[lens[i]-j-2];
			if(sum+diff==sumt){
				swap(nums[i][j],nums[i][j+1]);
				printf("Error in record #%d. Correct number is: %s.", i+1, nums[i]);
				return 0;
			}
		}
	}

	puts("Unrecoverable error.");

    return 0;
}