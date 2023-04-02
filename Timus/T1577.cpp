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

struct s{
    short int x, y;
    s(const int& a=-1, const int& b=-1) : x(a), y(b) {}
};

const int INF = numeric_limits<short int>::max();
const int MOD = 1000*1000*1000+7;
s q[4000001];
int qh=0, qt=0;
short int dist[2003][2003];
int num[2003][2003];
char str1[2005], str2[2005];

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    scanf("%s%s", str1+1, str2+1);
    num[0][0]=0;
    int n1 = strlen(str1+1);
    int n2 = strlen(str2+1);

    for (int i=0; i<=n1; ++i){
        for (int j=0; j<=n2; ++j){
            dist[i][j]=INF;
        }
    }

    dist[0][0]=0;
    num[0][0]=1;

    q[qt++] = s(0, 0);

    while(qt!=qh){
        s& u = q[qh++];
        if(u.x<n1 && u.y<n2 && str1[u.x+1]==str2[u.y+1]){
            if(dist[u.x][u.y]+1<dist[u.x+1][u.y+1]){
                dist[u.x+1][u.y+1]=dist[u.x][u.y]+1;
                num[u.x+1][u.y+1]=num[u.x][u.y];
                q[qt++]=s(u.x+1, u.y+1);
            }else if (dist[u.x][u.y]+1==dist[u.x+1][u.y+1]){
                num[u.x+1][u.y+1]=(num[u.x+1][u.y+1]+num[u.x][u.y])%MOD;
            }
        }else{
            if(u.x<n1){
                if(dist[u.x][u.y]+1<dist[u.x+1][u.y]){
                    dist[u.x+1][u.y]=dist[u.x][u.y]+1;
                    num[u.x+1][u.y]=num[u.x][u.y];
                    q[qt++]=s(u.x+1, u.y);
                }else if (dist[u.x][u.y]+1==dist[u.x+1][u.y]){
                    num[u.x+1][u.y]=(num[u.x+1][u.y]+num[u.x][u.y])%MOD;
                }
            }
            if(u.y<n2){
                if(dist[u.x][u.y]+1<dist[u.x][u.y+1]){
                    dist[u.x][u.y+1]=dist[u.x][u.y]+1;
                    num[u.x][u.y+1]=num[u.x][u.y];
                    q[qt++]=s(u.x, u.y+1);
                }else if (dist[u.x][u.y]+1==dist[u.x][u.y+1]){
                    num[u.x][u.y+1]=(num[u.x][u.y+1]+num[u.x][u.y])%MOD;
                }
            }
        }
    }

    printf("%d", num[n1][n2]);

    return 0;
}