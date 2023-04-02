#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int eur=1;
const int jap=2;
int n, m;
int ans=1e+9, num, cur;
char let[2] = {'E', 'J'};
vector <vector <int> > v;
vector <int> prot;
vector <bool> col, done;
deque <int> q1, q2;

void dfs (int u){
	done[u]=true;
	for (int i=0; i<v[u].size(); ++i){
		if (prot[v[u][i]]==prot[u] && !done[v[u][i]])
			dfs(v[u][i]);
	}
}

void bfs (int u){
	q1.push_back(u);
	while (!q1.empty() || !q2.empty()){
		if (q1.empty() && !q2.empty()){
			cur++;
			q1.swap(q2);
		}
		u=q1.front();
		q1.pop_front();
		col[u]=true;
		for (int i=0; i<v[u].size(); ++i){
			int k=v[u][i];
			if (!col[k]){
				col[k]=true;
				if (prot[k]==prot[u])
					q1.push_back(k);
				else
					q2.push_back(k);
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1544.in", "r", stdin);
	freopen ("T1544.out", "w", stdout);
#endif

	scanf ("%d%d\n", &n, &m);

	v.resize(n);
	prot.resize(n);
	col.resize(n);
	done.resize(n);

	for (int i=0; i<n; ++i){
		char ch;
		scanf ("%c ", &ch);
		if (ch=='E')
			prot[i]=eur;
		else
			prot[i]=jap;
	}

	for (int i=0; i<m; ++i){
		int a, b;
		scanf ("%d%d", &a, &b);
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}

	for (int i=0; i<n; ++i){
		if (!done[i]){
			for (int j=0; j<col.size(); ++j)
				col[j]=false;
			dfs (i);
			cur=0;
			bfs(i);
			if (cur<ans){
				ans=cur;
				num=i;
			}
		}
	}

	printf ("%d\n", ans);

	int t;
	if (prot[num]==eur)
		t=0;
	else
		t=1;

	for (int i=0; i<ans; ++i){
		t=!t;
		printf ("%d %c\n", num+1, let[t]);
	}

	return 0;
}