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
#include <list>
#include <set>
using namespace std;

int maxx = 0;
char win = '?';

class Square{
public:
	char sym;
	int hor, ver, rdiag, ldiag;
	void check(){
		if (hor>maxx){
			maxx=hor;
			win=sym;
		}
		else if (hor==maxx && sym!=win){
			win='?';
		}
		if (ver>maxx){
			maxx=ver;
			win=sym;
		}
		else if (ver==maxx && sym!=win){
			win='?';
		}
		if (rdiag>maxx){
			maxx=rdiag;
			win=sym;
		}
		else if (rdiag==maxx && sym!=win){
			win='?';
		}
		if (ldiag>maxx){
			maxx=ldiag;
			win=sym;
		}
		else if (ldiag==maxx && sym!=win){
			win='?';
		}

	}
};

vector <Square> v1, v2;
int n;
string s;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1287.in", "r", stdin);
	freopen ("T1287.out", "w", stdout);
#endif

	scanf ("%d\n", &n);
	v1.resize(n);
	v2.resize(n);
	getline(cin, s);
	for (int i=0; i<n; ++i){
		v1[i].sym=s[i];
		v1[i].ver=1;
		v1[i].rdiag=1;
		v1[i].ldiag=1;
		if (i>0)
			v1[i-1].sym==v1[i].sym ? v1[i].hor=v1[i-1].hor+1 : v1[i].hor=1;
		else
			v1[i].hor=1;
		v1[i].check();
	}
	for (int i=1; i<n; ++i){
		getline (cin, s);
		for (int j=0; j<n; ++j){
			v2[j].sym=s[j];
			if (j>0){
				if (v2[j-1].sym==v2[j].sym)
					v2[j].hor=v2[j-1].hor+1;
				else
					v2[j].hor=1;
				if (v1[j-1].sym==v2[j].sym)
					v2[j].rdiag=v1[j-1].rdiag+1;
				else
					v2[j].rdiag=1;
			}
			else{
				v2[j].hor=1;
				v2[j].rdiag=1;
			}
			if (v1[j].sym==v2[j].sym)
				v2[j].ver=v1[j].ver+1;
			else
				v2[j].ver=1;
			if (j<n-1){
				if (v1[j+1].sym==v2[j].sym){
					v2[j].ldiag=v1[j+1].ldiag+1;
				}
				else{
					v2[j].ldiag=1;
				}
			}
			else{
				v2[j].ldiag=1;
			}
			v2[j].check();
		}
		v1=v2;
	}

	printf ("%c\n%d", win, maxx);

	return 0;
}