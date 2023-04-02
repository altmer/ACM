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

enum wh{RIGHT, LEFT, DOWN, UP};

class SpiralWalking{
public:
	int totalPoints(vector <string> l){
		int way=RIGHT;
		int step=1, bor=l.size()*l[0].size();
		int i=0, j=0;
		int res=l[0][0]-'0';
		int last=res;
		l[0][0]='v';
		while (true){
			switch (way){
				case RIGHT: 
					if (j+1<l[i].size() && l[i][j+1]!='v'){
						last=l[i][j+1]-'0';
						res+=last;
						l[i][j+1]='v';
						j++;
						step++;
					}
					else{
						way=DOWN;
						if (step==bor){
							last=0;
							return res;
						}
						res-=last;
						last=0;
					}
					break;
				case DOWN:
					if (i+1<l.size() && l[i+1][j]!='v'){
						last=l[i+1][j]-'0';
						res+=last;
						l[i+1][j]='v';
						i++;
						step++;
					}
					else{
						way=LEFT;
						if (step==bor){
							last=0;
							return res;
						}
						res-=last;
						last=0;
					}
					break;
				case LEFT: 
					if (j-1>=0 && l[i][j-1]!='v'){
						last=l[i][j-1]-'0';
						res+=last;
						l[i][j-1]='v';
						step++;
						j--;
					}
					else{
						way=UP;
						if (step==bor){
							last=0;
							return res;
						}
						res-=last;
						last=0;
					}
					break;
				case UP:
					if (i-1>=0 && l[i-1][j]!='v'){
						last=l[i-1][j]-'0';
						res+=last;
						l[i-1][j]='v';
						step++;
						i--;
					}
					else{
						way=RIGHT;
						if (step==bor){
							last=0;
							return res;
						}
						res-=last;
						last=0;
					}
					break;
			}
		}
	return res;
	}	
};

//declarations
int n;
string s;
vector <string> q;
SpiralWalking solve;

void input (void){
	scanf ("%d\n", &n);
	for (int i=0; i<n; ++i){
		getline (cin, s);
		q.push_back(s);
	}
}

void output (void){
	cout << solve.totalPoints(q);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}