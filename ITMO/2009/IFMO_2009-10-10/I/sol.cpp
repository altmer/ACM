#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

struct point{
	int x, y;
	point() : x(-1), y(-1) {}
	point(int nx, int ny) : x(nx), y(ny) {}
};

char str[1010];
int len;
point cur (0, 0);
point mt[256];
char table[5][5];

void encrypt(char a, char b){
	if (mt[a].x == mt[b].x){
		printf("%c%c", toupper(table[mt[a].x][ (mt[a].y + 1) %5] ), toupper(table[mt[b].x][ (mt[b].y + 1) %5] ));
	}else if (mt[a].y == mt[b].y){
		printf("%c%c", toupper(table[(mt[a].x + 1) % 5][ mt[a].y] ), toupper(table[(mt[b].x + 1) % 5][mt[b].y] ));
	}else{
		printf("%c%c", toupper(table[mt[a].x][ mt[b].y]), toupper(table[mt[b].x][ mt[a].y]));
	}
}

int main (void){
    freopen ("i.in", "r", stdin);
    freopen ("i.out", "w", stdout);


	gets(str);
	len = strlen(str);

	for (int i = 0; i < len; ++i){
		if (isalpha(str[i])){
			if ( mt[ str[i] ].x == -1 ){
				table[cur.x][cur.y] = str[i];
				mt[ str[i] ] = cur;
				cur.y++;
				if(cur.y >= 5){
					cur.y = 0;
					cur.x++; 
				}
			}
		}
	}

	for (char c = 'a'; c<='z'; ++c){
		if(c == 'q') continue;
		if ( mt[ c ].x == -1 ){
			table[cur.x][cur.y] = c;
			mt[ c ] = cur;
			cur.y++;
			if(cur.y >= 5){
				cur.y = 0;
				cur.x++; 
			}
		}		
	}

	gets(str);
	len = strlen(str);

	char prev(0), next(0);
	for (int i = 0; i < len; ++i){
		if(!isalpha(str[i])) continue;

		if(prev == 0){
			prev = str[i];
		}else if (next == 0){
			next = str[i];

			if(prev == next){
				encrypt(prev, 'x');
				prev = next;
				next = 0;
			}else{
				encrypt(prev,next);
				prev = next = 0;
			}
		}
	}

	if(prev != 0)
		encrypt(prev, 'x');

    return 0;
}