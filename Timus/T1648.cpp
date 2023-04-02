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

struct yacht{
	long long month, num;
	yacht(int a, int b) : month(a), num(b) {}
};

long long prod, zatr;
int n, d;
vector <yacht> v;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf ("%d%d", &n, &d);

	for (int i=0; i<n; ++i){
		int a;
		scanf ("%d", &a);
		if (d>a){
			prod+=a;
			v.push_back(yacht(i,d-a));
		}
		else if (d==a){
			prod+=a;
		}
		else{
			prod+=d;
			a-=d;
			while (a && !v.empty() ){
				if (v.back().num>=a){
					v.back().num-=a;
					prod+=a;
					zatr+=a*(i-v.back().month);
					a=0;
				}
				else{
					prod+=v.back().num;
					zatr+=v.back().num*(i-v.back().month);
					a-=v.back().num;
					v.pop_back();
				}
			}
		}
	}

	cout << prod << ' ' << zatr;

	return 0;
}