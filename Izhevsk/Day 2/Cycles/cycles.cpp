#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<limits>
using namespace std;

struct Edge{
	int next, item, len;
	Edge() : next(-1), item(-1), len(0) {}
};

int n,m;
int cnt=0;
Edge A[100100];
Edge E[400200];
long long dist[100100];
bool col[100100];
int inp[100100];

bool dfs(int u){
	col[u]=true;
	for (int i=A[u].next; i!=-1; i=E[i].next){
		int v = E[i].item;
		int len = E[i].len;
		if(!col[v]){
			dist[v]=dist[u]+len;
			if(!dfs(v))
				return false;
		}else{
			if(dist[v]!=dist[u]+len){
				return false;
			}
		}
	}
	return true;
}

int main(void){
	freopen("cycles.in", "r", stdin);
	freopen("cycles.out", "w", stdout);

	cin>>n>>m;
	for (int i=0; i<n; ++i){
		dist[i]=numeric_limits<long long>::max();
	}
	for(int i=0;i<m;i++){
		int fr,to, w;
		scanf("%d %d %d",&fr,&to, &w);
		fr--; to--;
		E[cnt].next=A[fr].next;
		E[cnt].item=to;
		E[cnt].len=w;
		A[fr].next=cnt++;
		inp[to]++;
		
		E[cnt].next=A[to].next;
		E[cnt].item=fr;
		E[cnt].len=-w;
		A[to].next=cnt++;		
	}

	for (int i=0; i<n; ++i){
		if(!col[i]){
			dist[i]=0;
			if(!dfs(i)){
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

	return 0;
}