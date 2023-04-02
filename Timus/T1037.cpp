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

struct block{
	int num, time;
};

const int M=30000;
const int T=600;

vector <int> v (M+1, 0);
multimap <int, int> q;
multimap <int, int>::iterator it;
set <int> w;
string s;
int tail=1;
int time;

int get_num (string str){
	int res=0;
	int t=1;
	for (int i=str.size()-1; i>=0; --i){
		res+=(str[i]-'0')*t;
		t*=10;
	}
	return res;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1037.in", "r", stdin);
	freopen ("T1037.out", "w", stdout);
#endif
	for (int i=1; i<=M; ++i){
		w.insert(i);
	}

	while (getline(cin, s)){
		bool mem=false;
		bool req=false;

		int pos=0;
		while (isdigit(s[pos]))
			++pos;
		time=get_num(s.substr(0, pos));
		it=q.begin();
		int d=time-T;
		while(it!=q.end() && it->first<=d){
			if (v[it->second]!=it->first){
				q.erase(q.begin());
				it=q.begin();
			}
			else{
				w.insert(it->second);
				v[it->second]=0;
				q.erase(q.begin());
				it=q.begin();
			}
		}
		for (int i=pos; i<s.size(); ++i){
			if (s[i]=='+'){
				mem=true;
				break;
			}
			else if (s[i]=='.'){
				req=true;
				break;
			}
		}
		if (mem){
			bool done=false;
			printf ("%d\n", *w.begin());
			v[*w.begin()]=time;
			q.insert(make_pair(time, *w.begin()));
			w.erase(w.begin());
		}
		else{
			while (!isdigit(s[pos]))
				pos++;
			int end=pos;
			while (end<s.size() && isdigit(s[end])){
				end++;
			}
			int addr=get_num (s.substr(pos, end-pos));

			if (w.find(addr)!=w.end()){
				printf ("-\n");
			}
			else{
				printf ("+\n");
				v[addr]=time;
				q.insert(make_pair(time, addr));
			}
		}
		
	}

	return 0;
}