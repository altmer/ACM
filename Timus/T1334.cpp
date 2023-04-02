#include <iostream>
#include <string>;
using namespace std;

int const empty=0, black=1, white=2, sent = 6;
int A[10][10];
int dx[] = { 1, 1, -1, -1};
int dy[] = {-1, 1,  1, -1};
int step = 0;
string word;
bool res = false;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1334.in", "r", stdin);
	freopen ("T1334.out", "w", stdout);
#endif
	int color;
	for (int i=0; i<10; ++i)
		A[i][0]=A[0][i]=A[9][i]=A[i][9]=sent;
	
	while (cin >> word)
	{
		++step;
		if (step%2==0)
			color=black;
		else
			color=white;
		int k=word[0]-'a'+1, l=word[1]-'1'+1;
		A[k][l]=color;
		for (int i=0; i<4; ++i)
		{
			if (A[k+dx[i]][l+dy[i]]!=empty && A[k+dx[i]][l+dy[i]]!=sent && A[k+dx[i]][l+dy[i]]!=color && (A[k+2*dx[i]][l+2*dy[i]]==empty || A[k-dx[i]][l-dy[i]]==empty))
			{
				res=true;
				break;
			}
		}
		if (res)
			break;
	}

	if (res)
		cout << step;
	else
		cout << "Draw";
	

	return 0;
}