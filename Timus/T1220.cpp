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

int cnt=0;
unsigned short Aprev[100000];
unsigned int Ait[100000];
int stck[1001];
int n, num, it;
char str[5];

int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

    scanf("%d", &n);

    for (int i=0; i<n; ++i){
        scanf("%s", str);

        if(str[1]=='U'){
            scanf("%d%d", &num, &it);
            Ait[cnt]=it;
            Ait[cnt]+=(stck[num]%4)<<30;
            Aprev[cnt]=stck[num]/4;
            stck[num]=cnt++;
        }else{
            scanf("%d", &num);
            printf("%d\n", Ait[stck[num]]%(1<<30));
            stck[num]=Aprev[stck[num]]*4 + Ait[stck[num]]/(1<<30);
        }
    }

    return 0;
}