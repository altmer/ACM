#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int Q[256], R[256], D[5][5];

struct grid{
	char A[5][5];
	int score;
	grid(){
		score=0;
		for (int i=0; i<5; ++i)
			for (int j=0; j<5; ++j)
				A[i][j]=' ';
	}
	int hash(){
		int cur=0;
		for (int i=1; i<=3; ++i){
			for (int j=1; j<=3; ++j){
				cur+=Q[A[i][j]]*D[i][j];
			}
		}
		return cur;
	}
	bool operator < (const grid &t) const{
		for (int i=1; i<=3; ++i){
			for (int j=1; j<=3; ++j){
				if (A[i][j]!=t.A[i][j]){
					return A[i][j]<t.A[i][j];
				}
			}
		}
		return false;
	}
};

queue <grid> q1;
queue <int> q2;
int dx[]={1,-1,0,0};
int dy[]={0, 0,1,-1};
int w1, w2, w3, w4, w;
int ans, cas=0;
bool s[2000000];
int cur_hash;

int main (void)
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	Q[' ']=0;
	Q['b']=1;
	Q['r']=2;
	Q['g']=3;
	Q['y']=4;
	int deg=1;
	for (int i=1; i<=3; ++i){
		for (int j=1; j<=3; ++j){
			D[i][j]=deg;
			deg*=5;
		}
	}

	while (true){
		++cas;
		memset(s, 0, sizeof(s));
		scanf ("%d%d%d%d%d", &w1, &w2, &w3, &w4, &w);
		if (!w1)
			break;
		ans=-1;
		R[' ']=0;
		R['b']=w1;
		R['r']=w2;
		R['g']=w3;
		R['y']=w4;

		q1.push(grid());
		q2.push(0);

		while (!q1.empty()){
			grid u=q1.front();
			q1.pop();
			int v=q2.front();
			q2.pop();
			for (int i=1; i<=3; ++i){
				for (int j=1; j<=3; ++j){
					grid tmp=u;
					tmp.A[i][j]=' ';
					tmp.score=u.score-R[u.A[i][j]];
					cur_hash=tmp.hash();
					if (!s[cur_hash]){
						s[cur_hash]=true;
						q1.push(tmp);
						q2.push(v+1);
					}
					tmp=u;
					tmp.A[i][j]='b';
					tmp.score=u.score-R[u.A[i][j]]+R['b'];
					cur_hash=tmp.hash();
					if (!s[cur_hash]){
						s[cur_hash]=true;
						q1.push(tmp);
						q2.push(v+1);
					}
					tmp=u;
					int bl,red,gr;
					bl=red=gr=0;
					for (int k=0; k<4; ++k){
						int x=i+dx[k];
						int y=j+dy[k];
						switch(u.A[x][y]){
							case 'b': bl++;
								break;
							case 'r': red++;
								break;
							case 'g': gr++; 
								break;
						}
					}
					if (bl){
						tmp.A[i][j]='r';
						tmp.score=u.score-R[u.A[i][j]]+R['r'];
						cur_hash=tmp.hash();
						if (!s[cur_hash]){
							s[cur_hash]=true;
							q1.push(tmp);
							q2.push(v+1);
						}
					}
					tmp=u;
					if (bl && red){
						tmp.A[i][j]='g';
						tmp.score=u.score-R[u.A[i][j]]+R['g'];
						cur_hash=tmp.hash();
						if (!s[cur_hash]){
							s[cur_hash]=true;
							q1.push(tmp);
							q2.push(v+1);
						}
					}
					tmp=u;
					if (bl && red && gr){
						tmp.A[i][j]='y';
						tmp.score=u.score-R[u.A[i][j]]+R['y'];
						cur_hash=tmp.hash();
						if (!s[cur_hash]){
							s[cur_hash]=true;
							q1.push(tmp);
							q2.push(v+1);
						}
					}
				}
			}
			if (u.score>=w){
				ans=v;
				while (!q1.empty()){
					q1.pop();
					q2.pop();
				}
			}
		}
		if (ans==-1){
			cout << "Case "  << cas << ": " << "Impossible" << endl;
		}
		else
			cout << "Case "  << cas << ": " << ans << endl;
	}
	return 0;
}