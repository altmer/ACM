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

int dx[16] = {0,  0, 1, 1,  1, -1, -1, -1,  2,  2, -2, -2, 1,  1, -1, -1};
int dy[16] = {1, -1, 1, 0, -1,  1,  0, -1,  1, -1,  1, -1, 2, -2,  2, -2};

class ChessMetric{
public:
	int n;
	bool check (int &x, int &y){
		return x>=0 && x<n && y>=0 && y<n;
	}
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
	{
		n = size;
		vector <vector <vector <long long> > > grid (size, vector <vector <long long> > (size, vector<long long> (numMoves+1, 0)));
		grid[start[0]][start[1]][0]=1;
		for (int mov = 1; mov<=numMoves; ++mov){
			for (int x=0; x<size; ++x){
				for (int y=0; y<size; ++y){
					 for (int i=0; i<16; ++i){
						int cx = x + dx[i];
						int cy = y + dy[i];
						if (check(cx,cy)){
							grid[cx][cy][mov]+=grid[x][y][mov-1];
						}
					 }	
				}
			}
		}
		return grid[end[0]][end[1]][numMoves];
	}
};

//declarations
ChessMetric solve;
vector <int> st;
vector <int> e;

void input (void){
	st.push_back(0);
	st.push_back(0);
	e.push_back(0);
	e.push_back(99);
}

void output (void){
	cout << solve.howMany(100, st, e, 50);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}