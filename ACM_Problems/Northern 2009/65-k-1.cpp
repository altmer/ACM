#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#pragma comment (linker, "/STACK:65000000")

struct edge{
	int next, dest;
};

int first[100000];
edge arr[200000];
int len;
int firstBack[100000];
edge arrBack[200000];
int lenBack;
bool color[100000];
bool ans[100000];
int num[300];
bool cols[10100][30];
int n, m, k;
char s[100];
char x, y;

bool dfsY(int u){
	color[u] = true;
	ans[u] = true;

	for (int ind = first[u]; ind != -1; ind = arr[ind].next){
		int v = arr[ind].dest;

		if (color[v] && !ans[v])
			return ans[u] = false;

		if (!cols[v][num[y]])
			return ans[u] = false;

		if(!color[v]){
			bool res = dfsY(v);
			if (!res)
				return ans[u] = false;
		}
	}
	return true;
}

void dfsX (int u, bool change){
	color[u] = true;
	ans[u] = true;

	for (int ind = firstBack[u]; ind != -1; ind = arrBack[ind].next){
		int v = arrBack[ind].dest;

		if (!color[v]){
			if (!change && cols[v][num[y]] && ans[v])
				dfsX(v, change);

			if(cols[v][num[x]]){
				ans[v] = true;
				dfsX(v, true);
			}
		}
	}
}

int main(){
	freopen("kripke.in","r",stdin);
	freopen("kripke.out","w",stdout);

	for (int i = 'a'; i <= 'z'; ++i)
		num[i] = i - 'a';

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < n; ++i){
		first[i] = -1;
		firstBack[i] = -1;
		int len;
		char c;
		scanf("%d ", &len);

		for (int j = 0; j < len; ++j){
			scanf("%c ", &c);
			cols[i][num[c]] = true;
		}
		scanf("\n");
	}

	for (int i = 0; i < m; ++i){
		int a, b;
		scanf("%d%d\n", &a, &b);
		a--; b--;

		arrBack[lenBack].dest = a;
		arrBack[lenBack].next = firstBack[b];
		firstBack[b] = lenBack++;

		arr[len].dest = b;
		arr[len].next = first[a];
		first[a] = len++;
	}

	scanf("%s", s);
	x = s[2];
	y = s[7];

	for (int i = 0; i < n; ++i){
		if (!color[i] && cols[i][num[y]]){
			dfsY(i);
		}
	}

	for (int i = 0; i < n; ++i){
		color[i] = false;
	}

	for (int i = 0; i < n; ++i){
		if(ans[i]){
			dfsX(i, false);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i){
		cnt += ans[i];
	}

	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i){
		if(ans[i])
			printf("%d\n", i + 1);
	}
	
	return 0;
}