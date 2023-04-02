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

int dx[]={1, -1, 0,  0};
int dy[]={0,  0, 1, -1};

class CubeNets{
public:
	vector <vector <bool> > col;
	vector <string> f2;
	void dfs(int x, int y){
		col[x][y]=true;
		for (int i=0; i<4; ++i){
			int cx=x+dx[i];
			int cy=y+dy[i];
			if (cx>=0 && cx<col.size() && cy>=0 && cy<col[0].size() && !col[cx][cy] && f2[cx][cy]=='#'){
				dfs(cx, cy);
			}
		}
	}
	
	string isCubeNet(vector <string> f)
	{
		f2=f;
		col.assign(f.size(), vector <bool> (f[0].size(), false));
		bool res=true;
		for (int i=0; i<f.size(); ++i){
			bool fin=false;
			for (int j=0; j<f[i].size(); ++j){
				if (f[i][j]=='#'){
					dfs(i,j);
					fin=true;
					break;
				}
			}
			if (fin)
				break;
		}
		for (int i=0; i<f.size(); ++i){
			for (int j=0; j<f[i].size(); ++j){
				if (f[i][j]=='#' && !col[i][j]){
					res=false;
					break;
				}
			}
		}
		//
		//
		for (int k=0; k<6; ++k){
			// horiz
			bool find=false;
			for (int i=0; i<f.size(); ++i){
				int cn=0;
				pair<int, int> pos;
				for (int j=0; j<f[i].size(); ++j){
					if (f[i][j]=='#'){
						++cn;
						pos=make_pair(i,j);
					}
				}
				if (cn==1){
					int nei=0;
					for (int p=0; p<4; ++p){
						int cx=pos.first+dx[p];
						int cy=pos.second+dy[p];
						if (cx>=0 && cx<f.size() && cy>=0 && cy<f[cx].size() && f[cx][cy]=='#'){
							++nei;
						}
					}
					if (nei<=1){
						f[pos.first][pos.second]='.';
						find=true;
					}
				}
				if (find)
					break;
			}
			if (find)
				continue;
			for (int i=0; i<f[0].size(); ++i){
				int cn=0;
				pair<int, int> pos;
				for (int j=0; j<f.size(); ++j){
					if (f[j][i]=='#'){
						++cn;
						pos=make_pair(j,i);
					}
				}
				if (cn==1){
					int nei=0;
					for (int p=0; p<4; ++p){
						int cx=pos.first+dx[p];
						int cy=pos.second+dy[p];
						if (cx>=0 && cx<f.size() && cy>=0 && cy<f[cx].size() && f[cx][cy]=='#'){
							++nei;
						}
					}
					if (nei<=1){
						f[pos.first][pos.second]='.';
						find=true;
					}
				}
				if(find)
					break;
			}
			if (!find){
				res=false;
				break;
			}
		}
		return res ? "YES" : "NO";
	}
};

//declarations
vector <string> v;
CubeNets solve;

void input (void){
v.push_back("..#.");
v.push_back("####");
v.push_back("..#.");
ostringstream oss;
oss<< 1;
string s=oss.str();
oss.str("");
}

void output (void){
	cout << solve.isCubeNet(v);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}