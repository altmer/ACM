#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

struct Point{
	int x, y;

	Point() : x(-1), y(-1) {}
	Point(int nx, int ny) : x(nx), y(ny) {}
};

struct Figure{
	int color, size;
	Point bottom;

	Figure() : color(-1), size(0) {}
};

int index[256];
char colors[5] = {'B', 'G', 'R', 'W', 'Y'};
bool exist[5];
int n, m;
char grid[52][52];
char cgrid[52][52];
bool vis[52][52];
int mainCol;
Point q[3000];
int head, tail;
int dx[4] = {0,  0, 1, -1};
int dy[4] = {1, -1, 0,  0};
Figure figures[3000];
int len;

Figure bfs(Point start){
	Figure ret;

	head = tail = 0;
	char col = cgrid[start.x][start.y];
	ret.color = index[col];

	vis[start.x][start.y] = true;
	ret.size++;
	ret.bottom = start;

	q[tail++] = start;

	while(head != tail){
		Point cur = q[head++];

		for (int i = 0; i < 4; ++i){
			Point np = Point(cur.x + dx[i], cur.y + dy[i]);
			
			if(cgrid[np.x][np.y] == col && !vis[np.x][np.y]){
				q[tail++] = np;
				vis[np.x][np.y] = true;

				ret.size++;
				if(np.x > ret.bottom.x || (np.x == ret.bottom.x && np.y < ret.bottom.y))
					ret.bottom = np;
			}
		}
	}

	return ret;
}

void deleteBfs(Point start){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j<=m; ++j){
			vis[i][j] = false;
		}
	}
	head = tail = 0;
	char col = cgrid[start.x][start.y];

	vis[start.x][start.y] = true;
	cgrid[start.x][start.y] = 'X';
	q[tail++] = start;

	while(head != tail){
		Point cur = q[head++];

		for (int i = 0; i < 4; ++i){
			Point np = Point(cur.x + dx[i], cur.y + dy[i]);
			
			if(cgrid[np.x][np.y] == col && !vis[np.x][np.y]){
				q[tail++] = np;
				vis[np.x][np.y] = true;
				cgrid[np.x][np.y] = 'X';
			}
		}
	}
	
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	for (int i = 0; i < 52; ++i){
		for (int j = 0; j < 52; ++j){
			grid[i][j] = ' ';
		}
	}
	index['B'] = 0;
	index['G'] = 1;
	index['R'] = 2;
	index['W'] = 3;
	index['Y'] = 4;

	scanf("%d%d\n", &n, &m);

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			scanf("%c", &grid[i][j]);
			exist[ index[ grid[ i ][ j ] ] ] = true;
		}
		scanf("\n");
	}

	bool fin = false;

	for (mainCol = 0; mainCol < 5; ++mainCol){
		int score = 0;
	
		if(!exist[mainCol]) continue;

		for (int i = 0; i < n+2; ++i){
			for (int j = 0; j < m+2; ++j){
				cgrid[i][j] = grid[i][j];
			}
		}

		bool done = true;
		while (done){
			bool existNotMain = false;
			done = false;
			do{
				existNotMain = false;
				for (int i = 1; i <= n; ++i){
					for (int j = 1; j<=m; ++j){
						vis[i][j] = false;
					}
				}

				len = 0;

				for (int i = 1; i <= n; ++i){
					for (int j = 1; j <= m; ++j){
						if( vis[i][j] || cgrid[i][j] == ' ' ) continue;
						Figure f = bfs(Point(i, j));

						if(f.size == 1) continue;
						
						figures[len++] = f;

						existNotMain = existNotMain || f.color != mainCol;
					}
				}

				if(!existNotMain) break;
				done = true;
				Figure cur;
				for (int i = 0; i < len; ++i){
					if (figures[i].color != mainCol && (figures[i].size > cur.size || 
						(figures[i].size == cur.size && figures[i].bottom.x > cur.bottom.x) || 
						(figures[i].size == cur.size && figures[i].bottom.x == cur.bottom.x && figures[i].bottom.y < cur.bottom.y)) ){

							cur = figures[i];
					}
				}

				score += cur.size * (cur.size - 1);

				deleteBfs(cur.bottom);

				for (int i = 1; i <= m; ++i){
					int jump = 0;
					for (int j = n; j>=1; --j){
						if (cgrid[j][i] == 'X'){
							jump++;
							cgrid[j][i] = ' ';
						}
						else{
							cgrid[j+jump][i] = cgrid[j][i];
							if (jump!=0) cgrid[j][i] = ' ';
						}
					}
				}

				int jump = 0;
				for (int i = 1; i <= m; ++i){

					for (int j = 1; j <= n; ++j){
						cgrid[j][i - jump] = cgrid[j][i];
						if (jump!=0 && cgrid[j][i] != ' ')cgrid[j][i] = 'X';
					}

					bool jmp = true;
					for (int j = 1; j <= n; ++j){
						jmp = jmp && cgrid[j][i] == ' ';
						if(cgrid[j][i] == 'X')
							cgrid[j][i] = ' ';
					}
					jump += jmp;

				}

				break;
			}while(existNotMain);

			bool existMain = false;
			if(done) continue;

			do{
				existMain = false;
				for (int i = 1; i <= n; ++i){
					for (int j = 1; j<=m; ++j){
						vis[i][j] = false;
					}
				}

				len = 0;

				for (int i = 1; i <= n; ++i){
					for (int j = 1; j <= m; ++j){
						if( vis[i][j] || cgrid[i][j] == ' ' ) continue;
						Figure f = bfs(Point(i, j));

						if(f.size == 1) continue;
						
						figures[len++] = f;

						existMain = existMain || f.color == mainCol;
					}
				}

				if(!existMain) break;
				done = true;

				Figure cur;
				for (int i = 0; i < len; ++i){
					if (figures[i].color == mainCol && (figures[i].size > cur.size || 
						(figures[i].size == cur.size && figures[i].bottom.x > cur.bottom.x) || 
						(figures[i].size == cur.size && figures[i].bottom.x == cur.bottom.x && figures[i].bottom.y < cur.bottom.y)) ){

							cur = figures[i];
					}
				}

				score += cur.size * (cur.size - 1);

				deleteBfs(cur.bottom);

				for (int i = 1; i <= m; ++i){
					int jump = 0;
					for (int j = n; j>=1; --j){
						if (cgrid[j][i] == 'X'){
							jump++;
							cgrid[j][i] = ' ';
						}
						else{
							cgrid[j+jump][i] = cgrid[j][i];
							if (jump!=0) cgrid[j][i] = ' ';
						}
					}
				}

				int jump = 0;
				for (int i = 1; i <= m; ++i){

					for (int j = 1; j <= n; ++j){
						cgrid[j][i - jump] = cgrid[j][i];
						if (jump!=0 && cgrid[j][i] != ' ')cgrid[j][i] = 'X';
					}

					bool jmp = true;
					for (int j = 1; j <= n; ++j){
						jmp = jmp && cgrid[j][i] == ' ';
						if(cgrid[j][i] == 'X')
							cgrid[j][i] = ' ';
					}
					jump += jmp;

				}


				break;
			}while(existMain);
		}

		printf("%c: %d\n", colors[mainCol], score);
	}

    return 0;
}