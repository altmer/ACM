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

struct coord{
	int x, y;
};

bool A[12][12];
int n, n2;
int dx[]={-2, -2, -1, -1, 1,  1,   2,  2 };
int dy[]={-1,  1, -2,  2,  -2, 2,  -1,  1};
bool fin;
int step=1;
coord ans[100];

void print_ans (void)
{
	for (int i=1; i<=n2; ++i)
		printf ("%c%d\n", 'a'+ans[i].x, ans[i].y+1);
}

void rec (int x, int y)
{
	ans[step].x=x-2;
	ans[step].y=y-2;
	int x2, y2;
	if (step==n2)
	{
		fin=true;
		print_ans();
	}	
	if (fin)
		return;
	
	A[x][y]=true;

	for (int i=0; i<8; ++i){
		x2=x+dx[i];
		y2=y+dy[i];
		if (!A[x2][y2]){
			step++;
			rec(x2, y2);
			A[x2][y2]=false;
			step--;
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1298.in", "r", stdin);
	freopen ("T1298.out", "w", stdout);
#endif

	scanf ("%d", &n);
	n2=n*n;

	for (int i=0; i<12; ++i)
	{
		A[0][i]=true;
		A[1][i]=true;
		A[i][0]=true;
		A[i][1]=true;
		A[n+2][i]=true;
		A[n+3][i]=true;
		A[i][n+2]=true;
		A[i][n+3]=true;
	}

	rec(2, 2);

	if (!fin)
		printf ("IMPOSSIBLE");

	return 0;
}