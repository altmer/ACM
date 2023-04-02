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

int A[6][6];
int O[3][3];
int ans=1e+9;;
bool fin;

void rec (int step, int x, int y){
	fin=true;
	for (int i=1; i<=4; ++i){
		for (int j=1; j<=4; ++j){
			if (A[i][j]!=A[1][1]){
				fin=false;
				break;
			}
		}
		if (!fin)
			break;
	}

	if (fin){
		ans=min(ans, step);
	}


	if (x>4){
		x=1;
		++y;
	}
	if (y>4)
		return;

	rec (step, x+1, y);
	
	for (int i=0; i<3; ++i){
		for (int j=0; j<3; ++j){
			if (O[i][j]){
				int dx=i-1;
				int dy=j-1;
				A[x+dx][y+dy]^=1;
			}
		}
	}
	rec (step+1, x+1, y);

	for (int i=0; i<3; ++i){
		for (int j=0; j<3; ++j){
			if (O[i][j]){
				int dx=i-1;
				int dy=j-1;
				A[x+dx][y+dy]^=1;
			}
		}
	}
}

void init (void){
	for (int i=1; i<=4; ++i){
		for (int j=1; j<=4; ++j){
			char ch;
			scanf ("%c", &ch);
			if (ch=='B')
				A[i][j]=1;
		}
		scanf ("\n");
	}

	for (int i=0; i<3; ++i){
		for (int j=0; j<3; ++j){
			scanf ("%c", &O[i][j]);
			O[i][j]-='0';
		}
		scanf ("\n");
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1122.in", "r", stdin);
	freopen ("T1122.out", "w", stdout);
#endif


	init ();
	rec (0, 1, 1);

	if (ans>1000000)
		printf ("Impossible");
	else
		printf ("%d", ans);

	return 0;
}