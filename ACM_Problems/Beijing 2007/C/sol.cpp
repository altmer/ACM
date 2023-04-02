#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int Q[256], R[256], D[3][3];
int cur_hash;
int cnt_step[2000000];
int best_step[10][10][10][10];
char cnt_b;
char cnt_r;
char cnt_g;
char cnt_y;

class grid{
public:
	char A[3][3];
	int score;
	grid(){
		score=0;
		for (int i=0; i<3; ++i)
			for (int j=0; j<3; ++j)
				A[i][j]=' ';
	}
	int hash(){
		int cur=0;
		for (int i=0; i<3; ++i){
			for (int j=0; j<3; ++j){
				cur+=Q[A[i][j]]*D[i][j];
			}
		}
		return cur;
	}
	char GetCell(int &x, int &y){
		if (x<0 || y<0 || x>2 || y>2)
			return ' ';
		return A[x][y];
	}
	int GetScore ()const{
		int cur=0;
		for (int i=0; i<3; ++i){
			for (int j=0; j<3; ++j){
				cur+=R[A[i][j]];
			}
		}
		return cur;
	}
	void GetBlock ()const{
		cnt_b=cnt_r=cnt_g=cnt_y=0;
		for (int i=0; i<3; ++i){
			for (int j=0; j<3; ++j){
				switch (A[i][j]){
					case 'b': cnt_b+=1;
						break;
					case 'r': cnt_r+=1;
						break;
					case 'g': cnt_g+=1;
						break;
					case 'y': cnt_y+=1;
						break;
				}
			}
		}
	}
	bool operator < (const grid &t) const{
		for (int i=0; i<3; ++i){
			for (int j=0; j<3; ++j){
				if (A[i][j]!=t.A[i][j]){
					return A[i][j]<t.A[i][j];
				}
			}
		}
		return false;
	}
};

int dx[]={1,-1,0,0};
int dy[]={0, 0,1,-1};
int w1, w2, w3, w4, w;
int ans, cas=0;
bool s[2000000];
grid q1[130000];
int q2[130000];
int head, tail;

void push (const int& it, const grid& gt){
	q1[tail]=gt;
	q2[tail++]=it;
	if (tail==130000)
		tail=0;
	gt.GetBlock();
	best_step[cnt_b][cnt_r][cnt_g][cnt_y]=min(best_step[cnt_b][cnt_r][cnt_g][cnt_y], it);
}

int main (void)
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	for (int i=0; i<10; ++i)
		for (int j=0; j<10; ++j)
			for (int k=0; k<10; ++k)
				for (int l=0; l<10; ++l){
					best_step[i][j][k][l]=20;
				}
	Q[' ']=0;
	Q['b']=1;
	Q['r']=2;
	Q['g']=3;
	Q['y']=4;
	int deg=1;
	for (int i=0; i<3; ++i){
		for (int j=0; j<3; ++j){
			D[i][j]=deg;
			deg*=5;
		}
	}


		head=tail=0;
		w1=w2=w3=1;
		w4=100;
		w=5000;
		ans=-1;
		R[' ']=0;
		R['b']=w1;
		R['r']=w2;
		R['g']=w3;
		R['y']=w4;

		cur_hash=0;
		s[0]=true;
		push(0, grid());
				
		while (head!=tail){
			grid u=q1[head];
			int v=q2[head++];
			if (head==130000)
				head=0;
			for (int i=0; i<3; ++i){
				for (int j=0; j<3; ++j){
					grid tmp=u;
					tmp.A[i][j]=' ';
					tmp.score=u.score-R[u.A[i][j]];
					cur_hash=tmp.hash();
					if (!s[cur_hash]){
						s[cur_hash]=true;
						push(v+1, tmp);
					}
					tmp=u;
					tmp.A[i][j]='b';
					tmp.score=u.score-R[u.A[i][j]]+R['b'];
					cur_hash=tmp.hash();
					if (!s[cur_hash]){
						s[cur_hash]=true;
						push(v+1, tmp);
					}
					tmp=u;
					int bl,red,gr;
					bl=red=gr=0;
					for (int k=0; k<4; ++k){
						int x=i+dx[k];
						int y=j+dy[k];
						switch(u.GetCell(x, y)){
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
							push(v+1, tmp);
						}
					}
					tmp=u;
					if (bl && red){
						tmp.A[i][j]='g';
						tmp.score=u.score-R[u.A[i][j]]+R['g'];
						cur_hash=tmp.hash();
						if (!s[cur_hash]){
							s[cur_hash]=true;
							push(v+1, tmp);
						}
					}
					tmp=u;
					if (bl && red && gr){
						tmp.A[i][j]='y';
						tmp.score=u.score-R[u.A[i][j]]+R['y'];
						cur_hash=tmp.hash();
						if (!s[cur_hash]){
							s[cur_hash]=true;
							push(v+1, tmp);
						}
					}
				}
			}
			if (u.score>=w){
				ans=v;
				head=tail;
			}
		}

	while (true){
		cas++;
		int ans=1e+9;
		scanf ("%d%d%d%d%d", &w1, &w2, &w3, &w4, &w);
		R[' ']=0;
		R['b']=w1;
		R['r']=w2;
		R['g']=w3;
		R['y']=w4;

		if (!w1)
			break;

		for (int i=0; i<10; ++i)
			for (int j=0; j<10; ++j)
				for (int k=0; k<10; ++k)
					for (int l=0; l<10; ++l){
						if (best_step[i][j][k][l]!=20 && i*w1+j*w2+k*w3+l*w4>=w){
							ans=min(ans, best_step[i][j][k][l]);
						}
					}
		if (ans==1e+9){
			cout << "Case "  << cas << ": " << "Impossible" << endl;
		}
		else{
			cout << "Case "  << cas << ": " << ans << endl;

		}
	}

	return 0;
}