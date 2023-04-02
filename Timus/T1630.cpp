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
vector<int> gr[150];
bool color[150];
vector<int> suspect;
int n,m;

void bfs(int start){
	suspect.clear();
	queue<int> q;
	color[start]=true;
	suspect.push_back(start);
	q.push(start);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=0;j<gr[u].size();j++){
			int v=gr[u][j];
			if(!color[v]){
				color[v]=true;
				suspect.push_back(v);
				q.push(v);
			}
		}
	}
}

bool full(){
	if(suspect.size()>4)return false;
	bool still=true;
	for(int i=0;still && i<suspect.size();i++){
		int u=suspect[i];
		for(int i=0;i<suspect.size();i++)
			if(suspect[i]!=u){
				bool found=false;
				for(int j=0;j<gr[u].size();j++)
					if(gr[u][j]==suspect[i])
						found=true;
				if(!found)still=false;
			}
	}
	return still;
}

bool line(){
	if(suspect.size()<3)return true;
	vector<int> step;
	for(int i=0;i<suspect.size();i++)
		step.push_back(gr[suspect[i]].size());
	sort(step.begin(),step.end());
	return step[0]==1 && step[1]==1 && step[step.size()-1]==2;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	bool res=true;
	for(int i=0;res && i<n;i++)
		if(!color[i] && gr[i].size()){
			bfs(i);
			res=full() || line();
	}
	if(res)cout<<"Luck is possible";
	else cout<<"Unlucky Petr";
	return 0;
}