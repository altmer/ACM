#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <limits>
#include <map>
#include <list>
#include <set>
using namespace std;

unsigned char vert=179;
unsigned char hor=196;
unsigned char ul=218;
unsigned char ur=191;
unsigned char bl=192;
unsigned char br=217;
unsigned char pl='#';
unsigned char table[21][52];

class Answer{
public:
    int x, y, len;
    Answer (int a, int b, int c){
        x=b;
        y=a;
        len=c;
    }
};
vector<Answer> v;

void erase(int x, int y, int a) {
    for (int cx=x, cy=y; cx<x+a; ++cx, ++cy){
        table[x][cy]=table[x+a-1][cy]=pl;
        table[cx][y]=table[cx][y+a-1]=pl;
    }
}

bool exist(int x, int y, int a) {
    bool ex=false;
    if(table[x][y]!=ul && table[x][y]!=pl)
        return false;
    if(table[x][y+a-1]!=ur && table[x][y+a-1]!=pl)
        return false;
    if(table[x+a-1][y]!=bl && table[x+a-1][y]!=pl)
        return false;
    if(table[x+a-1][y+a-1]!=br && table[x+a-1][y+a-1]!=pl)
        return false;
    ex= table[x][y]==ul || table[x][y+a-1]==ur || table[x+a-1][y]==bl || table[x+a-1][y+a-1]==br;

    for (int cx=x+1, cy=y+1; cx<x+a-1; ++cx, ++cy){
        if((table[x][cy]!=hor && table[x][cy]!=pl) ||(table[x+a-1][cy]!=hor && table[x+a-1][cy]!=pl))
            return false;
        if((table[cx][y]!=vert && table[cx][y]!=pl) ||(table[cx][y+a-1]!=vert && table[cx][y+a-1]!=pl))
            return false;
        ex = ex || table[x][cy]==hor || table[x+a-1][cy]==hor || table[cx][y]==vert || table[cx][y+a-1]==vert;
     }
    return ex;
}

int main (void){
	//freopen("in.txt", "w", stdout);
//	freopen("in.txt", "r", stdin);




	for (int i=0; i<20; ++i){
		for (int j=0; j<50; ++j){
			table[i][j]=getchar();
		}
		getchar();
	}

    bool fin=false;
    while(!fin){
        fin=true;
        for (int i=0; i<20; ++i){
            for (int j=0; j<50; ++j){
                if(table[i][j]==ul || table[i][j]==pl){
                    for (int k=2; k<=min(20-i, 50-j)+1; ++k){
                        if(exist(i,j,k)){
                            fin=false;
                            v.push_back(Answer(i,j,k));
                            erase(i,j,k);
                            break;
                        }
                    }
                }
            }
        }
    }

	printf("%d\n", v.size());
	for (int i=v.size()-1; i>=0; --i){
		printf("%d %d %d\n", v[i].x,v[i].y,v[i].len);
	}



/*
	for (int i=0; i<20; ++i){
		for (int j=0; j<50; ++j){
			table[i][j]='.';
		}
		
	}
	int n;
	cin>>n;
    for (int i=0; i<n; ++i){
		int y;
		int x;
		int a;
		cin >> y >> x >> a;
		table[x][y]=ul;
		for (int cx=x+1, cy=y+1; cx<x+a-1; ++cx, ++cy){
			table[x][cy]=table[x+a-1][cy]=hor;
			table[cx][y]=table[cx][y+a-1]=vert;
		}
		table[x][y+a-1]=ur;
		table[x+a-1][y]=bl;
		table[x+a-1][y+a-1]=br;
	}
	for (int i=0; i<20; ++i){
		for (int j=0; j<50; ++j){
			putchar(table[i][j]);
		}
		putchar('\n');
	}
*/
	return 0;
}
