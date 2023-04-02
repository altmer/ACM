#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string x, y, z;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1558.in", "r", stdin);
	freopen ("T1558.out", "w", stdout);
#endif
	
	getline (cin, x);
	getline (cin, y);
	x=x.substr(1, x.size()-2);
	y=y.substr(1, y.size()-2);
	int lim=x.size();
	for (int i=0; i<5; ++i){
		x+=x;
		y+=y;
	}
	z=y;

	int car=0;
	for (int i=x.size()-1; i>=0; --i){
		int res=(x[i]-'0')+(y[i]-'0')+car;
		car=res/10;
		z[i]=(res%10)+'0';
	}

	for (int i=z.size()-1; i>=0; --i){
		for (int len=1; len<=lim; ++len){
			int st=i-len+1;
			int j=st-len;
			while (j>=0 && z.substr(st, len)==z.substr(j,len)){
				j-=len;
			}
			if (j<0){
				cout << "(" << z.substr(st, len) << ")";
				if (i<z.size()-1){
					cout << z.substr(i+1, z.size()-1-i);
				}
				return 0;
			}
		}
	}

	return 0;
}