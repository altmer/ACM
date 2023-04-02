#include <iostream>
#pragma comment (linker, "/STACK:128000000");
using namespace std;

struct Edge{
	int next, item;
	Edge() : next(-1), item(-1) {}
};

int n, num;
bool M[1000][1000];
bool trav[1000][1000];
bool col[1000];
Edge A[3000], E[60000];
int cnt=0;
bool used[1000];
int mt[3000];
pair<int,int> ans[100000];
int len=0;
int way[1000000];
int ptr=0;

void dfs(int u){
	col[u]=true;
	for (int i=0; i<n; ++i){
		if(M[u][i]){
			M[i][u]=false;
			M[u][i]=false;
			dfs(i);
			way[ptr++] = u;
		}
	}
}

bool kuhn(int u){
	if(used[u]) return false;
	used[u]=true;
	for (int i=A[u].next; i!=-1; i=E[i].next){
		int v=E[i].item;
		if(mt[v]==-1 || kuhn(mt[v])){
			mt[v]=u;
			return true;
		}
	}
	return false; 
}

int main(void){
	freopen("deep.in", "r", stdin);
	freopen("deep.out", "w", stdout);

	scanf("%d%d", &n, &num);
	if(num==0){
		cout << "Impossible\n";
		return 0;
	}

	for (int i=0; i<num; ++i){
		int fr, to;
		scanf("%d%d", &fr, &to);
		fr--; to--;
		M[fr][to]=M[to][fr]=true;
	}

	for (int i=0; i<n; ++i){
		if(!col[i]){
			ptr=0;
			dfs(i);
			for (int j=ptr-1; j>=1; --j){
				E[cnt].item=way[j-1]+n;
				E[cnt].next=A[way[j]].next;
				A[way[j]].next=cnt++;
			}
			E[cnt].item=i+n;
			E[cnt].next=A[way[0]].next;
			A[way[0]].next=cnt++;
		}
	}

	for (int i=0; i<3000; ++i){
		mt[i]=-1;
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			used[j]=false;
		}
		if(!kuhn(i)){
		}
	}

	for (int i=n; i<2*n; ++i){
		if(mt[i]!=-1){
			ans[len++]=make_pair(mt[i]+1, i-n+1);
		}
	}

	printf("%d\n", len);
	for (int i=0; i<len ; ++i){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}