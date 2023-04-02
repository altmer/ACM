#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

class JollyJumpers{
public:
	int high;
	map <vector<string>, int> sc;
	queue<vector <string> > q;

	bool on(int x, int y){
		return x>=0 && x<4 && y>=0 && y<4;
	}

	int maxScore(vector<string> layout)
	{
		high=0;
		q.push(layout);
		sc[layout]=0;
		while(!q.empty()){
			vector <string> cur=q.front(), nw;
			q.pop();
			for (int i=0; i<4; ++i){
				for (int j=0; j<4; ++j){
					if (cur[i][j]=='#'){
						for (int d=0; d<2; ++d){
							if (on(i+dx[d],j) && cur[i+dx[d]][j]=='#' && on(i+2*dx[d],j) && cur[i+2*dx[d]][j]=='.'){
								nw=cur;
								nw[i][j]='.';
								nw[i+dx[d]][j]='.';
								nw[i+2*dx[d]][j]='#';
								if (!sc.count(nw)){
									sc[nw]=sc[cur]+2;
									high=max(high,sc[nw]);
									q.push(nw);
								}
							}
						}
						for (int d=2; d<4; ++d){
							if (on(i,j+dy[d]) && cur[i][j+dy[d]]=='.'){
								nw=cur;
								nw[i][j]='.';
								nw[i][j+dy[d]]='#';
								if (!sc.count(nw)){
									sc[nw]=sc[cur]-1;
									q.push(nw);
								}
							}
						}
					}
				}
			}
		}
		return high;
	}
};

//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}