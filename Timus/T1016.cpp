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

pair<int,int> dest;

class PosCube{
public:
	vector<int> sch;
	pair<int,int> loc;
	enum {FRONT, BOTTOM, RIGHT, LEFT, TOP, BACK};
	PosCube(){
		sch.assign(6, -1);
	}

	void construct(){
		string s, tok1, tok2;
		getline(cin,s);

		istringstream iss(s);
		iss >> tok1 >> tok2;

		loc=make_pair(tok1[0]-'a',tok1[1]-'1');
		dest=make_pair(tok2[0]-'a', tok2[1]-'1');

		iss >> sch[FRONT] >> sch[BACK] >> sch[TOP] >> sch[RIGHT] >> sch[BOTTOM] >> sch[LEFT];
	}
	void rotRight(){
		int tmp=sch[RIGHT];
		sch[RIGHT]=sch[TOP];
		sch[TOP]=sch[LEFT];
		sch[LEFT]=sch[BOTTOM];
		sch[BOTTOM]=tmp;
	}
	void rotLeft(){
		int tmp=sch[LEFT];
		sch[LEFT]=sch[TOP];
		sch[TOP]=sch[RIGHT];
		sch[RIGHT]=sch[BOTTOM];
		sch[BOTTOM]=tmp;
	}
	void rotFront(){
		int tmp=sch[FRONT];
		sch[FRONT]=sch[TOP];
		sch[TOP]=sch[BACK];
		sch[BACK]=sch[BOTTOM];
		sch[BOTTOM]=tmp;
	}
	void rotBack(){
		int tmp=sch[BACK];
		sch[BACK]=sch[TOP];
		sch[TOP]=sch[FRONT];
		sch[FRONT]=sch[BOTTOM];
		sch[BOTTOM]=tmp;
	}
	int getBottom(){
		return sch[BOTTOM];
	}
	void step(int dx, int dy){
		if(dx){
			if(dx>0){
				rotRight();
			}
			else{
				rotLeft();
			}
		}
		if(dy){
			if(dy>0){
				rotBack();
			}
			else{
				rotFront();
			}
		}
		loc.first+=dx;
		loc.second+=dy;
	}
	bool operator < (const PosCube& T) const{
		if(loc==T.loc)
			return sch<T.sch;
		return loc<T.loc;
	}
	bool operator == (const PosCube& T) const{
		return sch==T.sch && loc==T.loc;
	}
};

bool onBoard(int x, int y){
	return x>=0 && x<8 && y>=0 && y<8;
}

vector<pair<int,int> > A;
map<PosCube,int> M;
vector<int> dist;
vector<int > par;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cur=0;
int cans=numeric_limits<int>::max();
int cpos=-1;

void build(PosCube st){
	queue<PosCube> q;
	q.push(st);
	M[st]=cur++;
	while(!q.empty()){
		st=q.front();
		q.pop();
		int nc=M[st];
		int nd=st.getBottom();
		for (int i=0; i<4; ++i){
			int nec, ned;
			if(onBoard(st.loc.first+dx[i],st.loc.second+dy[i])){
				PosCube v(st);
				v.step(dx[i],dy[i]);
				if(!M.count(v)){
					M[v]=cur++;
					nec=cur-1;
					ned=v.getBottom();
					dist.push_back(numeric_limits<int>::max());
					par.push_back(-1);
					A.push_back(v.loc);
				}
				else{
					nec=M[v];
					ned=v.getBottom();
				}
				if(dist[nc]+ned<dist[nec]){
					dist[nec]=dist[nc]+ned;
					par[nec]=nc;
					q.push(v);
				}
			}
		}
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	PosCube st, end;
	st.construct();
	dist.push_back(st.getBottom());
	par.push_back(-1);
	A.push_back(st.loc);
	//dist[0]=st.getBottom();
	build(st);
	//bfs(0);
	end.loc=dest;
	map<PosCube,int>::iterator it=M.upper_bound(end);
	while(it!=M.end() && it->first.loc==end.loc){
		if(dist[it->second]<cans){
			cans=dist[it->second];
			cpos=it->second;
		}
		it++;
	}
	stack<pair<int,int> > ans;
	printf("%d ", cans);
	while(cpos!=-1){
		ans.push(A[cpos]);
		cpos=par[cpos];
	}
	while(!ans.empty()){
		printf("%c%c ", 'a'+ans.top().first, '1'+ans.top().second);
		ans.pop();
	}

	return 0;
}