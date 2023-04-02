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

struct dir{
	string name;
	int lev;
	vector <int> child;
	bool operator < (dir t){
		if (lev==t.lev){
			return name<t.name;
		}
		return lev<t.lev;
	}
};

int n;
vector <dir> v;
string s;

int find_name (int num, string name){
	for (int i=0; i<v[num].child.size(); ++i){
		if (v[v[num].child[i]].name==name){
			return v[num].child[i];
		}
	}
	return -1;
}

bool cmp (int a, int b){
	return v[a].name<v[b].name;
}

void outp (int num){
	for (int i=0; i<v[num].child.size(); ++i){
		int w=v[num].child[i];
		for (int j=0; j<v[w].lev; ++j)
			printf (" ");
		cout << v[w].name << "\n";
		outp(w);
	}
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1067.in", "r", stdin);
	freopen ("T1067.out", "w", stdout);
#endif

	scanf ("%d\n", &n);

	dir t;
	t.name="ROOT";
	t.lev=-1;
	v.push_back(t);

	for (int i=0; i<n; ++i){
		string s1, s2;
		int d1, d2;
		getline (cin, s);
		// get s1
		int pos=0;
		while (pos<s.size() && s[pos]!='\\' ){
			++pos;
		}
		s1=s.substr(0, pos++);
		d1=find_name(0, s1);

		if (d1<0){
			dir t;
			t.name=s1;
			t.lev=0;
			v.push_back(t);
			d1=v.size()-1;
			v[0].child.push_back(d1);
		}

		// add childs
		while (pos<s.size()){
			int end=pos;
			while (end<s.size() && s[end]!='\\')
				end++;
			s2=s.substr(pos, end-pos);
			pos=end+1;

			d2=find_name(d1, s2);
			if (d2<0){
				dir t;
				t.name=s2;
				t.lev=v[d1].lev+1;
				v.push_back(t);
				d2=v.size()-1;
				v[d1].child.push_back(d2);
			}
			d1=d2;
			s1=s2;
		}
	}

	for (int i=0; i<v.size(); ++i){
		sort (v[i].child.begin(), v[i].child.end(), cmp);
	}

	outp (0);

	return 0;
}