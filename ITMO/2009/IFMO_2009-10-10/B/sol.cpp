#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

struct node{
	int val, next;
};

int debt[10100];
int first[10100];
bool col[10100];
node arr[1200000];
int len = 0;
int n, m;

int dfs(int u){
	col[u] = true;
	int ret = debt[u];
	for (int ind = first[u]; ind != -1; ind = arr[ind].next){
		int v = arr[ind].val;
		if(!col[v])
			ret += dfs(v);
	}
	return ret;
}

int main (void){
    freopen ("b.in", "r", stdin);
    freopen ("b.out", "w", stdout);


	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i){
		first[i] = -1;
		scanf("%d", &debt[i]);
	}

	for (int i = 0; i < m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);

		arr[len].val = b;
		arr[len].next = first[a];
		first[a] = len++;

		arr[len].val = a;
		arr[len].next = first[b];
		first[b] = len++;
	}

	for (int i = 0; i < n; ++i){
		if(!col[i]){
			if(dfs(i)!=0){
				puts("IMPOSSIBLE");
				return 0;
			}
		}
	}

	puts("POSSIBLE");

    return 0;
}