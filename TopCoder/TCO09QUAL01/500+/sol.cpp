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


class SquareFreeNumbers{
public:
	long long sq[1000100];
	bool free[1000100];
	int getCount(long long min, long long max){
/*		bool p[1001000];
		int primes[1000100];

        int ans=0;
        // primes
        int lim = (int)sqrt((double)max) + 1;
        int sz=0;
        
        for (int j=2; j<=lim; ++j){
            if(!p[j]){
                primes[sz++]=j;
                int num=2*j;
                while(num<=lim){
                    p[num]=true;
                    num+=j;
                }
            }
        }
        
        for(long long a=min; a<=max; ++a){
            long long cur=a;
            bool good=true;
            for (int k=0; k<sz && primes[k]*primes[k]<=cur; ++k){
                int cnt=0;
                while(cur%primes[k]==0){
                    cur/=primes[k];
                    ++cnt;
                }
                if(cnt>1){
                    good=false;
                    break;
                }
            }
            if(good)
                ++ans;
        }*/
		int sz=0;
        int ans=0;
        // primes
        int lim = (int)sqrt((double)max) + 1;
		for (long long i=2; i<=lim; ++i){
			sq[sz++]=i*i;
		}
		for (int k=0; k<sz && sq[k]<=max; ++k){
			long long first=(min/sq[k]+1L)*sq[k];
			if(min%sq[k]==0)
				free[0]=true;
			while(first<=max){
				free[first-min]=true;
				first+=sq[k];
			}
		}
		for (int j=0; j<=max-min; ++j){
			if(!free[j])
				ans++;
		}
        return ans;
    }
};

//declarations
SquareFreeNumbers solve;

void input (void){
	cout << solve.getCount(1,10);
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