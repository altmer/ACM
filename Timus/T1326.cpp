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

class Edge{
public:
    int dest, cost;
    Edge(){}
    Edge(int a, int b){
        dest=a; cost=b;
    }
};

const int MAXINT = numeric_limits<int>::max();
int dist[1100000];
int best = MAXINT;
Edge E[120];
int n;
int el;
int ans=0;

void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u=q.front();
		q.pop();
        for (int j=0; j<el; ++j){
            int v=u|E[j].dest;
            if(dist[v]>dist[u]+E[j].cost){
                dist[v]=dist[u]+E[j].cost;
                q.push(v);
                if((v&ans)==ans){
                    best=min(best, dist[v]);
                }
            }
        }
    }
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

    int N;
    scanf("%d", &N);
    n = (1<<N);
    for (int i=0; i<n; ++i){
    	dist[i]=best;
    }
    
    for (int i=0; i<N; ++i){
	int tmp;
	scanf("%d", &tmp);
        E[el++] = Edge ((1<<i), tmp);
    }

    int m;
	scanf("%d", &m);

    for (int i=0; i<m; ++i){
        int cost;
        int cnt;
	scanf("%d%d", &cost, &cnt);
        int res=0;
        for (int j=0; j<cnt; ++j){
            int cur;
			scanf("%d", &cur);
            res|=(1<<(cur-1));
        }
        E[el++] = Edge(res, cost);
    }
 
    scanf("%d", &m);
    for (int i=0; i<m; ++i){
        int cur;
	scanf("%d", &cur);
        ans|=(1<<(cur-1));
    }
    dist[0] = 0;

	for (int i=0; i<n; ++i){
		if(dist[i]!=MAXINT){
			for (int j=0; j<el; ++j){
				int v=i|E[j].dest;
				if(dist[v]>dist[i]+E[j].cost){
					dist[v]=dist[i]+E[j].cost;
					if((v&ans)==ans){
						best=min(best, dist[v]);
					}
				}
			}
		}
	}

    printf("%d\n", best);


	return 0;
}