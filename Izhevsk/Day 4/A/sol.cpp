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
#include<cmath>
using namespace std;

const int INF = 1000*1000*1000;

struct Node{
	int next, item;
	int res;
	Node() : next(-1), item(-1), res(INF){}
};

Node table[999983];
Node E[4000000];
int cnt=0;
bool A[15][15];
int col[15];
int pop[20];

int n;
int hashCurrent(const int& pl){
	int ret=0;
	for (int i=0; i<n; ++i){
		ret+=col[i];
		ret<<=2;
	}
	ret<<=1;
	ret+=pl;
	return ret;
}
int put(int& code){
	int ind = code%999983;
	E[cnt].item = code;
	E[cnt].next = table[ind].next;
	table[ind].next = cnt++;
	return cnt-1;
}
int findres(int& code){
	int ind = code%999983;
	for (int i=table[ind].next; i!=-1; i=E[i].next){
		if(E[i].item==code)
			return E[i].res;
	}
	return INF;
}

int rec(int pl, int sost, bool flagA, bool flagB){
	int res=INF;
	if((res=findres(sost))!=INF)
		return res;
	int ind = put(sost);

	int indep[15];
	int sz=0;
	for (int i=0; i<n; ++i){
		if(col[i]==0){
			indep[sz++]=i;
		}
	}



	if(flagA && flagB){
		res=0;
		for (int i=0; i<n; ++i){
			if(col[i]==1){
				res+=pop[i];
			}else if(col[i]==2){
				res-=pop[i];
			}
		}
		return E[ind].res=res;
	}

	int mask = 1<<sz;
	bool found=false;
	for (int i=1;i<mask;i++){
		int j=i;
		int arr[15];
		bool used[15];
		for (int q=0; q<15; ++q)
			used[q]=false;
		int size=0;
		int res1=0; // sum for A
		int res2=0; // sum for C & B
		int k=0;
		while(j){
			if(j&1){
				arr[size++]=indep[k];
			}
			j>>=1;
			k++;
		}
		for (int q=0; q<size; ++q){
			int c = arr[q];
			res2 += pop[c];
			for (int w=0; w<n; ++w){
				if(A[c][w] && col[w]==pl+1 && !used[w]){
					res1+=pop[w];
					used[w]=true;
				}
				if(A[c][w] && col[w]==3-(pl+1) && !used[w]){
					res2+=pop[w];
					used[w]=true;
				}
			}
		}

		if(res1>res2){
			found=true;
			for (int q=0; q<size; ++q){
				col[arr[q]]=pl+1;
			}
			int curres = rec(1-pl, hashCurrent(pl),flagA,flagB);
			if(res==INF)
				res=curres;
			if(pl==0){
				res = max(res,curres);
			}else{
				res = min(res,curres);
			}
			for (int q=0; q<size; ++q){
				col[arr[q]]=0;
			}
		}
	}

	if(!found){
		if(pl==0){
			flagA=true;
		}else{
			flagB=true;
		}
		int curres = rec(1-pl, hashCurrent(pl),flagA,flagB);
		if(res==INF)
			res=curres;
		if(pl==0){
			res = max(res,curres);
		}else{
			res = min(res,curres);
		}
	}

	return E[ind].res=res;
}

int main(void){
	freopen("battle.in", "r", stdin);
	freopen("battle.out", "w", stdout);
	int s, t;
	scanf("%d%d%d\n", &n,&s, &t);
	--s; --t;
	char str[20];
	for (int i=0; i<n; ++i){
		scanf("%s", str);
		for (int j=0; j<n; ++j){
			if(str[j]=='1')
				A[i][j]=true;
		}
	}
	col[s]=1;
	col[t]=2;
	for (int i=0; i<n; ++i){
		scanf("%d", &pop[i]);
	}

	cout << rec(0,hashCurrent(0),0,0);
	
	return 0;
}