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

class team{
public:
	string name;
	int pts;
	team (string s="") : name(s), pts(0) {}
};

map <string, int> D;
vector <team> v;
int nj=0;
int t,w;
string s;
vector <string> tour;

int main (void)
{
	freopen ("zavalinka.in", "r", stdin);
	freopen ("zavalinka.out", "w", stdout);

	scanf ("%d%d", &t, &w);
	v.reserve(t);
	
	for (int i=0; i<t; ++i){
		cin >> s;
		v.push_back(team(s));
		D[s]=i;
	}

	for (int i=0; i<w; ++i){
		cin >> s;
	}

	for (int i=0; i<w; ++i){
		cin >> s;
		tour.assign(t+2, "");
		for (int i=0; i<t+2; ++i){
			cin>>tour[i];
		}
		int n;
		for (int i=0; i<t; ++i){
			cin >> s >> n;
			n--;
			if (tour[n]=="$jury$"){
				nj++;
			}
			else if (tour[n]=="$answer$"){
				v[D[s]].pts+=2;
			}
			else if (tour[n]==s){
				v[D[s]].pts-=10;
			}
			else{
				++v[D[tour[n]]].pts;
			}
		}
	}

	for (int i=0; i<v.size(); ++i){
		cout << v[i].name << " " << v[i].pts << "\n";
	}
	cout << "$jury$ " << nj << "\n";
	
	return 0;
}