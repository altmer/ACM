#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
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

vector<bitset<30> > prev, next;
vector<bool> prevb, nextb;
bitset<30> ans;
bool good=false;
int len=-1;

inline bool cmp(bitset<30>& a, bitset<30>& b){
    for (int i=0; i<30; ++i){
        if(a[i]^b[i])
            return b[i];
    }
    return false;
}

int main (void)
{
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    if(n<=2){
        printf("%d", n);
        return 0;
    }

    prev.resize(n);
    next.resize(n);
    prevb.resize(n);
    nextb.resize(n);

    prev[1][0]=false;
    prev[2][0]=true;
    prevb[1]=true;
    prevb[2]=true;

    for (int i=1; i<30; ++i){
        for (int j=0; j<n; ++j){
            if(prevb[j]){
                int k  = (j*10+1)%n;
                bitset<30> val = prev[j];
                val[i]=false;
                if(!nextb[k] || cmp(val,next[k])){
                    nextb[k]=true;
                    next[k] = val;
                }
                if(k==0 && (!good || cmp(next[k],ans))){
                    ans=next[k];
                    good=true;
                    len=i;
                }
                
                k  = (j*10+2)%n;
                val=prev[j];
                val[i]=true;
                if(!nextb[k] || cmp(val,next[k])){
                    nextb[k]=true;
                    next[k] = val;
                }
                if(k==0 && (!good || cmp(next[k],ans))){
                    ans=next[k];
                    good=true;
                    len=i;
                }
            }
        }
        if(good)
            break;
        for (int j=0; j<n; ++j){
            prev[j]=next[j];
            prevb[j]=nextb[j];
            next[j]=0;
            nextb[j]=false;
        }
    }

    if(!good){
        cout << "Impossible\n";
    }
    else{
        for (int i=0; i<=len; ++i){
            if(ans[i]){
                printf("2");
            }
            else
                printf("1");
        }
        printf("\n");
    }

    return 0;
}