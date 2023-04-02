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

struct point
{
	int x, y;
};

point L, R;
point A;
int dist, n;

double MOD (point A)
{
	return sqrt (double (A.x*A.x+A.y*A.y));
}

int VecP (point A, point B)
{
	return (A.x*B.y-B.x*A.y);
}


int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    scanf ("%d%d%d%d%d%d", &dist, &R.x, &R.y, &L.x, &L.y, &n);

    for (int i=0; i<n; ++i){
        scanf ("%d%d", &A.x, &A.y);
        if (VecP(A, R)<0 && VecP(A, L)>0 && MOD(A)<=dist)
            printf ("YES\n");
        else if (VecP(A, R)==0 && MOD(A)<=dist && A.x*R.x>=0 && A.y*R.y>=0)
            printf ("YES\n");
        else if (VecP(A, L)==0 && MOD(A)<=dist && A.x*L.x>=0 && A.y*L.y>=0)
            printf ("YES\n");
        else
            printf ("NO\n");
    }


    return 0;
}