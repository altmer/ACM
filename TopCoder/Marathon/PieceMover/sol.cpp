#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <list>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;
	ifstream fin("input.txt");
	ofstream fout ("output.txt");

enum PATH {NORTH, SOUTH, WEST, EAST};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dxx[8]={1,1,1,-1,-1,-1,0,0};
int dyy[8]={-1,1,0,-1,1,0,-1,1};

class Piece
{
public:
	int locX, locY;
	int destX, destY;
	int color, ord,dist;
	int gr;
	Piece():locX(0),locY(0),destX(-1),destY(-1),color(0), ord(-1),dist(0),gr(-1){}
	Piece(int x, int y, int col) :locX(x),locY(y),destX(-1),destY(-1),color(col), ord(-1),dist(0),gr(-1){}
};
class cmp
{
public:
	bool operator () (Piece* const& t1,Piece* const& t2){
		if (t1->color==t2->color){
			if (t1->ord==t2->ord)
				return t1->dist<t2->dist;
			return t1->ord<t2->ord;
		}
		return t1->color<t2->color;
	}
};
class PieceMover
{
public:
	int n;
	vector <vector <int> > plan;
	vector <vector <Piece> > base;
	vector <vector <Piece*> > grid;
	vector <string> ans;
	multiset<Piece*, cmp> q;
	ostringstream oss;

	void outplan()
	{
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				fout<< plan[i][j];
			}
			fout<<endl;
		}

		fout<<endl;
	}
	void outgrid()
	{
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				if (grid[i][j]==NULL)
					fout<<0;
				else
					fout<<grid[i][j]->color+1;
			}
			fout<<endl;
		}

		fout<<endl;
	}

	bool check_bord(const int& x, const int& y)
	{
		return x>=0 && x<n && y>=0 && y<n;
	}
	bool strong_check_bord(const int& x, const int& y)
	{
		return x>0 && x<n-1 && y>0 && y<n-1;
	}	
	void getInput (vector <string>& board)
	{
		// input
		for (int i=0; i<n; ++i){
			for (int j=0; j<n; ++j){
				if (board[i][j]!='0'){
					int col=board[i][j]-'0'-1;
					base[col].push_back(Piece(i,j,col));
					int l=base[col].size()-1;
					grid[i][j]=&base[col][l];
				}
			}
		}
	}

	void findCenter (int col, int& cx, int& cy)
	{
		int bestx=-1;
		int besty=-1;
		int bestdist=1e+9;
		for (int i=1; i<n-1; ++i){
			for (int j=1; j<n-1; ++j){
				if (!plan[i][j]){
					int cur=0;
					for (int k=0; k<base[col].size(); ++k){
						cur+=abs(base[col][k].locX-i)+abs(base[col][k].locY-j);
					}
					if (cur<bestdist){
						bestx=i;
						besty=j;
						bestdist=cur;
					}
				}
			}
		}
		cx=bestx;
		cy=besty;
	}

	void stepX (Piece& p, int ddx){
		grid[p.locX+ddx][p.locY]=&p;
		grid[p.locX][p.locY]=NULL;
		if (ddx>0)
			oss << p.locX << " " << p.locY << " " << "SOUTH";
		else
			oss << p.locX << " " << p.locY << " " << "NORTH";
		p.locX+=ddx;
		ans.push_back(oss.str());
		oss.str("");
	}

	void stepY (Piece& p, int ddy){
		grid[p.locX][p.locY+ddy]=&p;
		grid[p.locX][p.locY]=NULL;
		if (ddy>0)
			oss << p.locX << " " << p.locY << " " << "EAST";
		else
			oss << p.locX << " " << p.locY << " " << "WEST";
		p.locY+=ddy;
		ans.push_back(oss.str());
		oss.str("");
	}

	void getPlan()
	{
		for (int col=0; col<base.size(); ++col){
			if (!base[col].empty()){
				int cx, cy;
				findCenter(col, cx, cy);
				// assignment
				list <pair <int, int> > cand, cand2;
				list <pair <int, int> >::iterator it;
				cand.push_back(make_pair(cx,cy));
				int ass=0;
				int toass=base[col].size();
				while (ass<toass){
					int cur=1e+9;
					int from=-1;
					list <pair <int, int> >::iterator wher=cand.end();
					//searching
					for (int i=0; i<toass; ++i){
						if(base[col][i].destX==-1){
							for (it=cand.begin(); it!=cand.end(); ++it){
								int tmp=abs(base[col][i].locX-it->first)+abs(base[col][i].locY-it->second);
								if (tmp<cur){
									cur=tmp;
									from=i;
									wher=it;
								}
							}
						}
					}
					//assigning
					++ass;
					base[col][from].destX=wher->first;
					base[col][from].destY=wher->second;
					base[col][from].ord=abs(base[col][from].destX-cx)+abs(base[col][from].destY-cy);
					base[col][from].dist=abs(base[col][from].destX-base[col][from].locX)+abs(base[col][from].destY-base[col][from].locY);
					plan[wher->first][wher->second]=col+1;
					// candidates
					for (int i=0; i<4; ++i){
						int x=wher->first+dx[i];
						int y=wher->second+dy[i];
						if (strong_check_bord(x,y) &&!plan[x][y]){
							plan[x][y]=-1;
							cand2.push_back(make_pair(x,y));
						}
					}
					cand.erase(wher);
					if (cand.empty())
						cand.swap(cand2);
				}
			}
			for (int i=0; i<n; ++i){
				for (int j=0; j<n; ++j){
					if (plan[i][j]==-1)
						plan[i][j]=0;
				}
			}
		}
	}

	void movePiece(Piece& p, int fx, int fy)
	{
		if (p.destX==p.locX  && p.destY==p.locY)
			return;
		bool fin=false;
		int ddx=p.locX-fx;
		int ddy=p.locY-fy;
			// can I... ?
		if (ddx && check_bord(p.locX+ddx, p.locY)&&grid[p.locX+ddx][p.locY]==NULL){
			// move it!
			stepX(p, ddx);
			fin=true;
		}
		if (!fin && ddy && check_bord(p.locX, p.locY+ddy)&&grid[p.locX][p.locY+ddy]==NULL){
			// move it!
			stepY(p,ddy);
			fin=true;
		}
		if(!fin && ddx && check_bord(p.locX+ddx, p.locY)){
			if ((grid[p.locX+ddx][p.locY]->destX-grid[p.locX+ddx][p.locY]->locX)*ddx>0 
				|| grid[p.locX+ddx][p.locY]->destY-grid[p.locX+ddx][p.locY]->locY!=0){
				movePiece(*grid[p.locX+ddx][p.locY], p.locX,p.locY);
				if (grid[p.locX+ddx][p.locY]==NULL){
					stepX(p,ddx);
					fin=true;
				}
			}
		}
		if (!fin && ddy && check_bord(p.locX, p.locY+ddy)){
			if ((grid[p.locX][p.locY+ddy]->destY-grid[p.locX][p.locY+ddy]->locY)*ddy>0 
				|| grid[p.locX][p.locY+ddy]->destX-grid[p.locX][p.locY+ddy]->locX!=0){
				movePiece(*grid[p.locX][p.locY+ddy],p.locX,p.locY);
				if (grid[p.locX][p.locY+ddy]==NULL){
					stepY(p, ddy);
					fin=true;
				}
			}
		}
		// end of movePiece
	}

	void move (Piece& p)
	{
		for (int i=0; i<4; ++i){
			if (check_bord(p.locX+dx[i],p.locY+dy[i]) && grid[p.locX+dx[i]][p.locY+dy[i]]!=NULL){
				movePiece(*grid[p.locX+dx[i]][p.locY+dy[i]], p.locX,p.locY);
			}
		}
		//where to go?
		int ddx=p.destX-p.locX;
		int ddy=p.destY-p.locY;
		// destination occupied
		if (grid[p.destX][p.destY]!=NULL){
			Piece* ptr=grid[p.destX][p.destY];
				int xx=-1, yy=-1;
				for (int i=0; i<4; ++i){
					if (check_bord(p.destX+dx[i],p.destY+dy[i]) && grid[p.destX+dx[i]][p.destY+dy[i]]==NULL){
						if (xx==-1 || dx[i]*ddx<=0 || dy[i]*ddy<=0){
							xx=dx[i];
							yy=dy[i];
						}
					}
				}
				if (xx==-1 && yy==-1){
					p.ord++;
					q.insert(&p);
				}
				else if (xx){
					stepX(*ptr, xx);
				}
				else if (yy){
					stepY(*ptr,yy);
				}
		}
		// брысь!

		for (int i=0; i<4; ++i){
			if (check_bord(p.destX+dx[i],p.destY+dy[i]) && grid[p.destX+dx[i]][p.destY+dy[i]]!=NULL){
				movePiece(*grid[p.destX+dx[i]][p.destY+dy[i]], p.destX,p.destY);
			}
		}
		//bfs
		vector <vector <bool> > vis(n,vector<bool>(n,false));
		vector <vector <pair <int, int> > > par (n, vector <pair<int,int> >(n,make_pair(-1,-1)));
		queue <pair <int, int> > que;
		pair <int, int> u=make_pair(p.locX,p.locY);
		vis[u.first][u.second]=true;
		que.push(u);
		
		while (!que.empty()){
			u=que.front();
			if (u.first==p.destX && u.second==p.destY)
				break;
			que.pop();
			for (int i=0; i<4; ++i){
				if (check_bord(u.first+dx[i],u.second+dy[i])&&grid[u.first+dx[i]][u.second+dy[i]]==NULL && !vis[u.first+dx[i]][u.second+dy[i]]){
					vis[u.first+dx[i]][u.second+dy[i]]=true;
					par[u.first+dx[i]][u.second+dy[i]]=u;
					que.push(make_pair(u.first+dx[i],u.second+dy[i]));
				}
			}
		}

		if (vis[p.destX][p.destY]){
			pair <int, int> cur(p.destX,p.destY);			
			stack <pair <int, int> > parents;
			while (cur.first!=-1){
				parents.push(cur);
				cur=par[cur.first][cur.second];
			}
			parents.pop();
			while (!parents.empty()){
				cur=parents.top();
				parents.pop();
				if (cur.first!=p.locX)
					stepX(p, cur.first-p.locX);
				else if (cur.second!=p.locY){
					stepY(p,cur.second-p.locY);
				}
			}
		}
	}

	void moveOut(Piece& p)
	{
		vector <vector <bool> > vis(n,vector<bool>(n,false));
		vector <vector <pair <int, int> > > par (n, vector <pair<int,int> >(n,make_pair(-1,-1)));
		queue <pair <int, int> > que;
		pair <int, int> u=make_pair(p.locX,p.locY);
		vis[u.first][u.second]=true;
		que.push(u);
		while (!que.empty()){
			u=que.front();
			bool br=true;
			if (plan[u.first][u.second]==p.color+1){
				for (int i=0; i<8; ++i){
					if (check_bord(u.first+dxx[i],u.second+dyy[i]) && (plan[u.first+dxx[i]][u.second+dyy[i]]!=0 && plan[u.first+dxx[i]][u.second+dyy[i]]!=p.color+1)){
						br=false;
						break;
					}
				}			
				if (br)
					break;
			}
			if (plan[u.first][u.second]==0){
				br=true;
				for (int i=0; i<8; ++i){
					if (check_bord(u.first+dxx[i],u.second+dyy[i]) && (plan[u.first+dxx[i]][u.second+dyy[i]]!=0 && plan[u.first+dxx[i]][u.second+dyy[i]]!=p.color+1)){
						br=false;
						break;
					}
				}
				if (br)
					break;
			}
			que.pop();
			for (int i=0; i<4; ++i){
				if (check_bord(u.first+dx[i],u.second+dy[i])&&grid[u.first+dx[i]][u.second+dy[i]]==NULL && !vis[u.first+dx[i]][u.second+dy[i]]){
					vis[u.first+dx[i]][u.second+dy[i]]=true;
					par[u.first+dx[i]][u.second+dy[i]]=u;
					que.push(make_pair(u.first+dx[i],u.second+dy[i]));
				}
			}
		}

			pair <int, int> cur(u);
			stack <pair <int, int> > parents;
			while (cur.first!=-1){
				parents.push(cur);
				cur=par[cur.first][cur.second];
			}
			parents.pop();
			while (!parents.empty()){
				cur=parents.top();
				parents.pop();
				if (cur.first!=p.locX)
					stepX(p, cur.first-p.locX);
				else if (cur.second!=p.locY){
					stepY(p,cur.second-p.locY);
				}
			}
	}

	void lastMove (Piece& p)
	{
		pair <int, int> cur;			
		stack <pair <int, int> > parents;
		vector <vector <bool> > vis(n,vector<bool>(n,false));
		vector <vector <pair <int, int> > > par (n, vector <pair<int,int> >(n,make_pair(-1,-1)));
		queue <pair <int, int> > que;
		pair <int, int> u=make_pair(p.locX,p.locY);
		vis[u.first][u.second]=true;
		que.push(u);
		
		while (!que.empty()){
			u=que.front();
			bool br=false;
			if (strong_check_bord(u.first,u.second)){
				for (int i=0; i<4; ++i){
					int xx=u.first+dx[i];
					int yy=u.second+dy[i];
					if ( check_bord(xx, yy) && grid[xx][yy]!=NULL && grid[xx][yy]->color==p.color && grid[xx][yy]->destX==grid[xx][yy]->locX && grid[xx][yy]->destY==grid[xx][yy]->locY){
						br=true;
						break;
					}
				}
			}
			if (br)
				break;
			que.pop();
			for (int i=0; i<4; ++i){
				if (check_bord(u.first+dx[i],u.second+dy[i])&&grid[u.first+dx[i]][u.second+dy[i]]==NULL && !vis[u.first+dx[i]][u.second+dy[i]]){
					vis[u.first+dx[i]][u.second+dy[i]]=true;
					par[u.first+dx[i]][u.second+dy[i]]=u;
					que.push(make_pair(u.first+dx[i],u.second+dy[i]));
				}
			}
		}
		cur=u;
		p.destX=cur.first;
		p.destY=cur.second;
		while (cur.first!=-1){
			parents.push(cur);
			cur=par[cur.first][cur.second];
		}
		parents.pop();
		while (!parents.empty()){
			cur=parents.top();
			parents.pop();
			if (cur.first!=p.locX)
				stepX(p, cur.first-p.locX);
			else if (cur.second!=p.locY){
				stepY(p,cur.second-p.locY);
			}
		}	
	}

	void dfs (Piece& p)
	{
		for (int i=0; i<4; ++i){
			int xx=p.locX+dx[i];
			int yy=p.locY+dy[i];
			if (check_bord(xx,yy) && grid[xx][yy]!=NULL && grid[xx][yy]->color==p.color && grid[xx][yy]->gr==-1){
				grid[xx][yy]->gr=p.gr;
				dfs(*grid[xx][yy]);
			}
		}
	}

	vector <string> getMoves(vector <string> board)
	{
		n=board.size();
		base.resize(10);
		for (int i=0; i<base.size(); ++i){
			base[i].reserve(10000);
		}
		plan.assign(n, vector<int>(n, 0));
		grid.assign(n, vector<Piece*>(n));

		getInput(board);

		getPlan();

		// cleaning grid
		for (int i=0; i<10; ++i){
			for (int j=0; j<base[i].size(); ++j){
				if (plan[base[i][j].locX][base[i][j].locY] && plan[base[i][j].locX][base[i][j].locY]!=base[i][j].color+1)
					moveOut(base[i][j]);
			}
		}

		for (int i=0; i<10; ++i){
			for (int j=0; j<base[i].size(); ++j){
				if (base[i][j].destX!=base[i][j].locX||base[i][j].destY!=base[i][j].locY)
					q.insert(&base[i][j]);
			}
		}
		while (!q.empty()){
			Piece* ptr=*q.begin();
			q.erase(q.begin());
			move(*ptr);
		}

		///////////////
		//outgrid();
		////////////////

		//check
		bool end=false;
		for (int i=0; i<10; ++i){
			int cgr=0;
			int rgr=-1;
			int rnum=-1;
			vector <int> v(4000);
			if (!base[i].empty()){
				for (int j=0; j<base[i].size(); ++j){
					if (base[i][j].destX==base[i][j].locX && base[i][j].destY==base[i][j].locY && base[i][j].gr==-1){
						base[i][j].gr=++cgr;
						dfs (base[i][j]);
					}
					if (base[i][j].gr!=-1)
						v[base[i][j].gr]++;
				}
				for (int j=1; j<=cgr; ++j){
					if (rgr<v[j]){
						rgr=v[j];
						rnum=j;
					}
				}
				for (int j=0; j<base[i].size(); ++j){
					if (base[i][j].gr!=rnum){
						base[i][j].destX=-1;
					}
				}
			}

		}

		while (!end){
			end=true;
			for (int i=0; i<10; ++i){
				for (int j=0; j<base[i].size(); ++j){
					if (base[i][j].destX!=base[i][j].locX||base[i][j].destY!=base[i][j].locY){
						end=false;
						base[i][j].ord=abs(n/2-base[i][j].locX)+abs(n/2-base[i][j].locY);
						base[i][j].dist=-1;
						base[i][j].destX=-1;
						base[i][j].destY=-1;
						q.insert(&base[i][j]);
					}
				}
			}
			while (!q.empty()){
				Piece* ptr=*q.begin();
				q.erase(q.begin());
				lastMove(*ptr);
			}
		}
		/////////////
		//outgrid();
		///////////////

		return ans;
	}
};

PieceMover solve;
vector <string> inp;
string s;

int main (void)
{
	getline (cin, s);
	inp.push_back(s);
	for (int i=1; i<inp[0].size(); ++i){
		getline (cin, s);
		inp.push_back(s);
	}
/*	for (int i=0; i<inp.size(); ++i){
		fout << inp[i]<<endl;
	}*/
	inp=solve.getMoves(inp);

	for (int i=0; i<inp.size(); ++i){
		cout << inp[i] << endl;
	}
	
	return 0;
}