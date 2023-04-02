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

bool A[300][300];
int ans[20000][250];
int par[300];
bool col[300];
int nums[20000];
int numans=0;
int n, m;
bool used[300][300];
int dist[300];

void addans(int fr, int to){
        int cur=fr;

        ans[numans][nums[numans]++]=cur+1;
        while(cur!=to){
            cur=par[cur];
            ans[numans][nums[numans]++]=cur+1;
        }
        numans++;
    }

    void dfs(int u){
        col[u]=true;

        for (int v = 0; v<n; ++v) if(A[u][v]){
            if(!col[v]){
                par[v]=u;
                dist[v]=dist[u]+1;
                dfs(v);
            }else if(v!=par[u] && dist[u]>dist[v] && !used[u][v]){
                addans(u, v);
                used[u][v]=used[v][u]=true;
            }
        }
    }


int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (int i=0; i<m; ++i){
        int fr, to;
        scanf("%d%d", &fr, &to);
        fr--; to--;
        A[fr][to]=A[to][fr]=true;
    }

            for (int i=0; i<n; ++i){
                if(!col[i]){
                    par[i]=-1;
                    dist[i]=0;
                    dfs(i);
                }
            }

            printf("%d\n", numans);
            for (int i=0; i<numans; ++i){
                printf("%d ", nums[i]);
                for (int j=0; j<nums[i]; ++j){
                    printf("%d ", ans[i][j]);
                }
                printf("\n");
            }


    return 0;
}