#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <queue>
using namespace std;
string s;
bool color[4200];
int dist[4200],parent[4200];
bool p[4200][4200];
int n;
void fill_table(){
	for(int len=1;len<=n;len++)
		for(int l=0;l+len<=n;l++){
			int r=l+len-1;
			if(len==1)p[l][r]=true;
			else if(len==2 && s[l]==s[r])p[l][r]=true;
			else if(s[l]==s[r])p[l][r]=p[l+1][r-1];
		}
}

void bfs(){
	queue<int> q;
	color[0]=true;
	dist[0]=0;
	parent[0]=-1;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u!=n){
			for(int i=u+1;i<=n;i++)
				if(p[u][i-1]){
					int v=i;
					if(!color[v]){
						color[v]=true;
						dist[v]=dist[u]+1;
						parent[v]=u;
						q.push(v);
					}
				}
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin>>s;
	n=s.length();
	fill_table();
	bfs();
	int cur=n;
	vector<int> ans;
	while(cur!=-1){
		ans.push_back(cur);
		cur=parent[cur];
	}
	int j=ans.size()-2;
	cout<<dist[n]<<endl;
	for(int i=0;i<n;i++){
		if(i!=ans[j])cout<<s[i];
		else {
			cout<<" "<<s[i];
			j--;
		}
	}
	return 0;
}