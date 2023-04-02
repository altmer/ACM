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

int words[200100];
int dp[200100];
int end=0;
string word;

int main (void)
{
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    while(cin >> word){
        for (int i=0; i<word.size(); ++i){
            if(isalpha(word[i])){
                words[end]++;
            }
            else if(words[end]!=0){
                end++;
            }
        }
        if(words[end]!=0){
            end++;
        }
    }
    if(end==1){
        printf("%d\n", words[end-1]);
        return 0;
    }

    dp[0] = words[0];
    dp[1] = max(words[0],words[1]);
    dp[2] = max(words[0]+words[2], words[1]);

    for (int i=3; i<end; ++i){
        dp[i]=max(dp[i-1], max(dp[i-3],dp[i-2])+words[i]);
    }

    printf("%d\n", max(dp[end-1],dp[end-2]));

    return 0;
}