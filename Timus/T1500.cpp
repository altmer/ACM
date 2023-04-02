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

int n, m, k;
int A[32][32];
bool col[32];
int ans=numeric_limits<int>::max(), res=-1;

bool dfs(int u, int obt){
    col[u]=true;
    if(u==1)
        return true;
    for (int v=0; v<n; ++v){
        if(A[u][v]&obt && !col[v]){
            if(dfs(v, obt))
                return true;
        }
    }
    return false;
}

void rec(int step, int obt, int num){
    if(step==k){
        for (int i=0; i<n; ++i)
            col[i]=false;
        if(dfs(0, obt)){
            if(num<ans){
                ans=num;
                res=obt;
            }
        }
        return;
    }
    rec(step+1, obt+(1<<step), num+1);
    rec(step+1, obt, num);
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    scanf("%d%d%d", &k, &n, &m);
    for (int i=0; i<m; ++i){
        int fr, to, cat;
        scanf("%d%d%d", &fr, &to, &cat);
        if(!(A[fr][to]&(1<<cat))){
            A[fr][to]+=(1<<(cat));
            A[to][fr]+=(1<<(cat));
        }
    }

    rec(0, 0, 0);
    printf("%d\n", ans);
    int cnt=0;
    while(res>0){
        if(res&1)
            printf("%d ", cnt);
        cnt++;
        res>>=1;
    }

    return 0;
}