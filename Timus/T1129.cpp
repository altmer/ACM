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
#pragma comment(linker, "/STACK:65777216")
using namespace std;

char res[110][110];
int A[110][110];
int D[110];
int n;

bool paint (int i, int col){
    for (int j=1; j<=A[i][0]; ++j){
        int k=A[i][j];
        if(res[i][k]!='Y' && res[i][k]!='G'){
            D[i]+=col;
            D[k]-=col;
            res[i][k]=col>0 ? 'Y' : 'G';
            res[k][i]=col<0 ? 'Y' : 'G';
            paint(k,col);
            return true;
        }
    }
    return false;
}

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &A[i][0]);

        for (int j=1; j<=A[i][0]; ++j){
            scanf("%d", &A[i][j]);
            A[i][j]--;
        }
    }

    for (int i=0; i<n; ++i){
        while(paint(i, D[i]>=0 ? -1 : 1)){}
    }
    for (int i=0; i<n; ++i){
        if(abs(D[i])>1){
            printf("Impossible\n");
            return 0;
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=1; j<=A[i][0]; ++j){
            printf("%c ", res[i][A[i][j]]);
        }
        printf("\n");
    }

    return 0;
}