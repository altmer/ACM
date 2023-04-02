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

struct coord{
	long long  x, y, z;
	bool operator < (coord t){
		if (x==t.x){
			if (y==t.y){
				return z<t.z;
			}
			return y<t.y;
		}
		return x<t.x;
	}
};

coord A, st;
string path;
vector <coord> ans;

coord dfs (coord st){
	for (int i=0; i<path.size(); ++i){
		switch (path[i]){
			case 'u':
				if (st.y<A.y)
					st.y++;
				break;
			case 'd':
				if (st.y>1)
					st.y--;
				break;
			case 'l':
				if (st.x>1)
					st.x--;
				break;
			case 'r':
				if (st.x<A.x)
					++st.x;
				break;
			case 'f':
				if (st.z<A.z)
					++st.z;
				break;
			case 'b':
				if (st.z>1)
					--st.z;
				break;
		}
	}
	return st;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1525.in", "r", stdin);
	freopen ("T1525.out", "w", stdout);
#endif

	cin >> A.x >> A.y >> A.z;
	getline (cin, path);
	getline (cin, path);

	st.x=1; st.y=1; st.z=1;
	ans.push_back(dfs(st));
	st.x=A.x; st.y=1; st.z=1;
	ans.push_back(dfs(st));
	st.x=1; st.y=A.y; st.z=1;
	ans.push_back(dfs(st));
	st.x=1; st.y=1; st.z=A.z;
	ans.push_back(dfs(st));
	st.x=A.x; st.y=A.y; st.z=1;
	ans.push_back(dfs(st));
	st.x=A.x; st.y=1; st.z=A.z;
	ans.push_back(dfs(st));
	st.x=1; st.y=A.y; st.z=A.z;
	ans.push_back(dfs(st));
	st.x=A.x; st.y=A.y; st.z=A.z;
	ans.push_back(dfs(st));

	sort (ans.begin(), ans.end());

	long long res=(ans.back().x-ans.front().x+1)*(ans.back().y-ans.front().y+1)*(ans.back().z-ans.front().z+1);

	cout << res;
	
	return 0;
}