#include <iostream>
#include <sstream>
#include <cstdio>
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
#include <map>
#include <set>
using namespace std;

struct client{
	int ID, P;
	client():ID(0), P(0){}
	client(int x, int y):ID(x),P(y){}
	bool operator < (const client& t)const{
		return P<t.P;
	}
};

set <client> Q;
int quer=-1;
int k, p;

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	while (quer){
		scanf ("%d", &quer);
		switch (quer){
			case 1: scanf ("%d%d", &k, &p);
				Q.insert(client(k, p));
				break;
			case 3:if (!Q.empty()){
					printf ("%d\n", Q.begin()->ID);
					Q.erase(Q.begin());
				   }
				   else{
					   printf ("0\n");
				   }
				   break;
			case 2:
				if (!Q.empty()){
					printf ("%d\n", (--Q.end())->ID);
					Q.erase((--Q.end()));
				}
				else{
				  printf ("0\n");
				}
			break;		
		}
	}

	return 0;
}