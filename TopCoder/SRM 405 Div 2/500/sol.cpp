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

struct dir{
	string name;
	int lev, par;
	vector <int> child;
	bool operator < (dir t){
		if (lev==t.lev){
			return name<t.name;
		}
		return lev<t.lev;
	}
};

class RelativePath{
public:
	vector <dir> v;
	vector <int> dist, from;
	int find_name (int num, string name){
		for (int i=0; i<v[num].child.size(); ++i){
			if (v[v[num].child[i]].name==name){
				return v[num].child[i];
			}
		}
		return -1;
	}
	void bfs (int u){
		queue <int> q;
		dist.resize(v.size());
		from.resize(v.size());
		dist[u]=1;
		from[u]=-1;
		q.push(u);
		while (!q.empty()){
			u=q.front();
			q.pop();
			for (int i=0; i<v[u].child.size(); ++i){
				int w=v[u].child[i];
				if (dist[w]==0 || dist[w]>dist[u]+1){
					q.push(w);
					dist[w]=dist[u]+1;
					from[w]=u;
				}
			}
			int w=v[u].par;
			if (dist[w]==0 || dist[w]>dist[u]+1){
				q.push(w);
				dist[w]=dist[u]+1;
				from[w]=u;
			}
		}
	}
	string makeRelative(string path, string cur){
		string line="";
		v.clear();
		dir t;
		int d1, d2;
		int start, dest;
		d1=0;
		d2=0;
		t.name="ROOT";
		t.lev=-1;
		t.par=0;
		v.push_back(t);
		//analyze path
		int pos=1;
		while (pos<path.size()){
			int end=pos;
			while (end<path.size() && isalpha(path[end])){
				++end;
			}
			string name=path.substr(pos, end-pos);
			pos=end+1;
			d2=find_name(d1, name);
			if (d2<0){
				dir t;
				t.name=name;
				t.lev=v[d1].lev+1;
				v.push_back(t);
				d2=v.size()-1;
				v[d1].child.push_back(d2);
				v[d2].par=d1;
			}
			d1=d2;
		}
		dest=d2;
		d1=0;
		d2=0;
		pos=1;
		while (pos<cur.size()){
			int end=pos;
			while (end<cur.size() && isalpha(cur[end])){
				++end;
			}
			string name=cur.substr(pos, end-pos);
			pos=end+1;
			d2=find_name(d1, name);
			if (d2<0){
				dir t;
				t.name=name;
				t.lev=v[d1].lev+1;
				v.push_back(t);
				d2=v.size()-1;
				v[d1].child.push_back(d2);
				v[d2].par=d1;
			}
			d1=d2;
		}
		start=d2;
		bfs(start);
		stack <int> ans;
		int p=dest;
		ans.push(p);
		p=from[p];
		while (from[p]!=-1){
			ans.push(p);
			p=from[p];
		}
		int prev=start;
		int step=ans.top();
		while (!ans.empty()){
			step=ans.top();
			ans.pop();
			if (v[step].lev<v[prev].lev){
				line+="../";
			}
			else{
				line+=v[step].name;
				if (!ans.empty())
					line+="/";
			}
			prev=step;
		}
		return line;
	}
};

//declarations
int n;
RelativePath solve;
string k1, k2;

void input (void){
	getline(cin, k1);
	getline (cin, k2);
}

void output (void){
	cout << solve.makeRelative(k1, k2);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}