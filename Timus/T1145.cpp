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

int dist[1001][1001];
char lab[1001][1001];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int curdist = 0;
pair<int,int> curans;

bool on_board(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void clear(){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j)
            dist[i][j]=-1;
    }
}

void bfs (pair<int,int> st){
    curans=st;
    queue<pair<int,int> > q;
    q.push(st);
    dist[st.first][st.second]=0;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for (int i=0; i<4; ++i){
            pair<int,int> next = make_pair(cur.first+dx[i],cur.second+dy[i]);
            if(on_board(next.first,next.second) && dist[next.first][next.second]==-1 && lab[next.first][next.second]=='.'){
                dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
                if(dist[next.first][next.second]>curdist){
                    curdist = dist[next.first][next.second];
                    curans = next;
                }
                q.push(next);
            }
        }
    }
}


int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i=0; i<n; ++i)
        scanf("%s", lab[i]);

    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if(lab[i][j]=='.'){
                clear();
                bfs(make_pair(i,j));
                clear();
                bfs(curans);
                printf("%d\n", curdist);
                return 0;
            }
        }
    }

    return 0;
}