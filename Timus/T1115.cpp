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

class rr{
public:
	int len, num;
	rr () : len(-1), num(-1) {}
	rr(int a, int b) : len(a), num (b) {}
	bool operator < (const rr& t) const{
		return len<t.len;
	}
};

vector <rr> row;
vector <int> ship, ship_row;
vector <vector <int> > ans;
int n, m;
bool fin;

void rec (int n_row, int n_ship){
	if (n_row==m-1){
		int sum=0;
		for (int i=0; i<n; ++i){
			if (ship_row[i]==-1){
				sum+=ship[i];
			}
		}
		if (sum==row[n_row].len){
			fin=true;
			for (int i=0; i<n; ++i){
				if (ship_row[i]==-1){
					ship_row[i]=row[n_row].num;
				}
			}
		}
		return;
	}
	if (fin)
		return;
	for (int i=n_ship; i<n; ++i){
		if(fin)
			return;
		if (ship_row[i]==-1 && ship[i]<=row[n_row].len){
			ship_row[i]=row[n_row].num;
			if (row[n_row].len==ship[i]){
				row[n_row].len-=ship[i];
				rec(n_row+1, 0);
			}
			else{
				row[n_row].len-=ship[i];
				rec(n_row, i+1);
			}
			if (fin)
				return;
			ship_row[i]=-1;
			row[n_row].len+=ship[i];
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1115.in", "r", stdin);
	freopen ("T1115.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	
	ship.resize(n);
	ship_row.assign(n, -1);
	for (int i=0; i<n; ++i){
		scanf ("%d", &ship[i]);
	}
	
	row.reserve(m);
	ans.resize(m);
	for (int i=0; i<m; ++i){
		int l;
		scanf ("%d", &l);
		row.push_back(rr(l, i));
	}

	sort(ship.rbegin(), ship.rend());
	sort(row.begin(), row.end());

	rec (0, 0);

	for (int i=0; i<n; ++i){
		ans[ship_row[i]].push_back(ship[i]);
	}

	for (int i=0; i<m; ++i){
		printf ("%d\n", ans[i].size());
		for (int j=0; j<ans[i].size(); ++j){
			printf ("%d ", ans[i][j]);
		}
		printf ("\n");
	}

	return 0;
}