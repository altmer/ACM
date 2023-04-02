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
using namespace std;

class TheStringGame{
public:
	map<string, int> match;
	vector<string> bmatch;
	vector<vector<int> > G;
	vector<int> fin, dist, D;
	vector<bool> winning, draw;
	enum{UNDETER, FIRST, DRAW, SECOND};

	void make_graph(string s){
		int cnt=0;

		match[s]=cnt++;
		G.push_back(vector<int>());
		bmatch.push_back(s);
		fin.push_back(UNDETER);
		dist.push_back(1000000);
		D.push_back(1000000);
		winning.push_back(false);
		draw.push_back(false);

		queue<int>q;
		q.push(cnt-1);
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			string curs=bmatch[cur];
			bool move=false;
			for (int i=0; i<curs.size(); ++i){
				if(curs[i]=='X'){
					move=true;
					curs[i]='L';
					if(!match.count(curs)){
						match[curs]=cnt++;
						G.push_back(vector<int>());
						bmatch.push_back(curs);
						fin.push_back(UNDETER);
						dist.push_back(1000000);
						winning.push_back(false);
						draw.push_back(false);
						D.push_back(1000000);

						G[cur].push_back(cnt-1);
						if(curs.find("LOL")==-1){
							q.push(cnt-1);
						}
						else{
							winning[cnt-1]=true;
						}
					}
					else{
						G[cur].push_back(match[curs]);
					}
					curs[i]='O';
					if(!match.count(curs)){
						match[curs]=cnt++;
						G.push_back(vector<int>());
						bmatch.push_back(curs);
						fin.push_back(UNDETER);
						dist.push_back(1000000);
						winning.push_back(false);
						draw.push_back(false);
						D.push_back(1000000);

						G[cur].push_back(cnt-1);
						if(curs.find("LOL")==-1){
							q.push(cnt-1);
						}
						else{
							winning[cnt-1]=true;
						}
					}
					else{
						G[cur].push_back(match[curs]);
					}
					curs[i]='X';
				}
			}
			if(!move){
				draw[cur]=true;
			}
		}
	}

	pair<int,int> searchgame (int pos, bool first){
		if(fin[pos]){
			return make_pair(fin[pos], dist[pos]);
		}
		if(winning[pos]){
			return make_pair(fin[pos]= first ? SECOND : FIRST, D[pos]=dist[pos]);
		}
		if(draw[pos]){
			return make_pair(fin[pos]= DRAW, D[pos]=dist[pos]);
		}
		pair<int,int> curres(first ? 1000 : -1000, -1);
		pair<int,int> tmp;
		for (int i=0; i<G[pos].size(); ++i){
			int wh=G[pos][i];
			if(!fin[wh]){
				dist[wh]=dist[pos]+1;
				tmp=searchgame(wh,!first);
				if(first){
					if(tmp.first<curres.first){
						curres=tmp;
					}
					else if (tmp.first==curres.first){ 
						if((tmp.first==FIRST && tmp.second<curres.second) || (tmp.first==SECOND && tmp.second>curres.second)){
							curres=tmp;
						}
					}
				}
				else{
					if(tmp.first>curres.first){
						curres=tmp;
					}
					else if (tmp.first==curres.first){ 
						if((tmp.first==SECOND && tmp.second<curres.second) || (tmp.first==FIRST && tmp.second>curres.second)){
							curres=tmp;
						}
					}
				}
			}
			else{
				tmp.first=fin[wh];
				tmp.second=D[wh]+dist[wh]-dist[pos]-1;
				if(first){
					if(tmp.first<curres.first){
						curres=tmp;
					}
					else if (tmp.first==curres.first){ 
						if((tmp.first==FIRST && tmp.second<curres.second) || (tmp.first==SECOND && tmp.second>curres.second)){
							curres=tmp;
						}
					}
				}
				else{
					if(tmp.first>curres.first){
						curres=tmp;
					}
					else if (tmp.first==curres.first){ 
						if((tmp.first==SECOND && tmp.second<curres.second) || (tmp.first==FIRST && tmp.second>curres.second)){
							curres=tmp;
						}
					}
				}
			}
		}
		fin[pos]=curres.first;
		D[pos]=curres.second;
		return curres;
	}

	string winner(string s){
		make_graph(s);
		dist[0]=0;
		pair<int, int> res = searchgame(0, true);
		ostringstream oss;
		oss<< ((res.first==FIRST) ? ("John ") : ((res.first==DRAW) ? "Draw" : "Brus "));
		if(res.first!=DRAW){
			oss<<res.second;
		}
		return oss.str();
	}
};

//declarations
TheStringGame solve;

void input (void){
}

void output (void){
	cout << solve.winner("LXXLXXL");
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}