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

struct expr{
	int coef, deg;
	vector <int> pol;
	expr(){
		coef=0;
		deg=0;
		pol.assign(26, 0);
	}
	void print(void){
		bool ent=false;
		if (coef!=1){
			ent=true;
			printf ("%d", coef);
		}
		for (int i=0; i<pol.size(); ++i){
			if (pol[i]){
				if (ent)
					printf ("*");
				ent=true;
				printf ("%c", 'a'+i);
				if (pol[i]>1){
					printf ("^%d", pol[i]);
				}
			}
		}
		if (!ent)
			printf ("1");
		printf (" ");
	}
	bool operator < (expr t){
		if (deg==t.deg){
			for (int i=0; i<pol.size(); ++i){
				if (pol[i]!=t.pol[i]){
					return pol[i]>t.pol[i];
				}
			}
			return false;
		}
		return deg>t.deg;
	}
};

string line;
vector <expr> p1, p2,p3, p4;

int get_num (string s){
	int res=0;
	int t=1;
	if (s.empty())
		return 1;
	for (int i=s.size()-1; i>=0; --i){
		res+=(s[i]-'0')*t;
		t*=10;
	}
	return res;
}

expr get_expr (string s){
	expr t;
	// get coef
	int pos=0;
	int end=0;
	while (end<s.size() && isdigit(s[end]))
		end++;
	t.coef=get_num(s.substr(pos, end-pos));
	if (t.coef==0){
		return t;
	}
	pos=end;
	while (pos<s.size()){
		if (!isalpha(s[pos])){
			pos++;
		}
		else{
			char ch=s[pos];
			int degr=1;
			pos++;
			if (pos<s.size() && s[pos]=='^'){
				pos++;
				end=pos;
				while (end<s.size() && isdigit(s[end])){
					end++;
				}
				degr=get_num(s.substr(pos, end-pos));
				pos=end+1;
			}
			t.pol[ch-'a']+=degr;
		}
	}
	return t;
}

vector <expr> work (string s){
	vector <expr> t;
	for (int i=0; i<s.size(); ++i){
		if (isspace(s[i])){
			s.erase(i,1);
			--i;
		}
	}
	int pos=0;
	while (pos<s.size()){
		bool minus=false;
		if (s[pos]=='-'){
			minus=true;
			pos++;
		}
		else if (s[pos]=='+')
			pos++;

		int end=pos;

		while (end<s.size() && s[end]!='+' && s[end]!='-'){
			end++;
		}
		expr q=get_expr(s.substr(pos, end-pos));
		pos=end;
		if (minus)
			q.coef*=-1;
		if (q.coef!=0)
			t.push_back(q);
	}
	return t;
}

vector <expr> mult (){
	vector<expr> t;
	for (int i=0; i<p1.size(); ++i){
		for (int j=0; j<p2.size(); ++j){
			expr q;
			q.coef=p1[i].coef*p2[j].coef;
			int w=0;
			for (int k=0; k<p1[i].pol.size(); ++k){
				q.pol[k]=p1[i].pol[k]+p2[j].pol[k];
				w+=q.pol[k];
			}
			q.deg=w;
			if (q.coef!=0)
				t.push_back(q);
		}
	}
	return t;
}

vector <expr> sokr(void){
	vector <expr> t;
	vector <bool> used (p3.size(), false);
	for (int i=0; i<p3.size(); ++i){
		if (used[i])
			continue;
		for (int j=i+1; j<p3.size(); ++j){
			if (!used[j]&&p3[i].deg==p3[j].deg){
				bool eq=true;
				for (int k=0; k<26; ++k){
					if (p3[i].pol[k]!=p3[j].pol[k]){
						eq=false;
						break;
					}
				}
				if (eq){
					used[j]=true;
					p3[i].coef+=p3[j].coef;
				}
			}
		}
		if (p3[i].coef!=0)
			t.push_back(p3[i]);
	}
	return t;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1408.in", "r", stdin);
	freopen ("T1408.out", "w", stdout);
#endif

	getline (cin, line);
	p1=work(line);
	getline(cin, line);
	p2=work(line);

	p3=mult();

	p4=sokr();

	sort (p4.begin(), p4.end());

	if (p4.size()!=0){
		if (p4[0].coef<0){
			printf ("-");
			p4[0].coef*=-1;
		}
		p4[0].print();
	}
	else
		printf ("0");

	int k=1;
	while (k<p4.size()){
		if (p4[k].coef<0){
			printf ("- ");
			p4[k].coef*=-1;
		}
		else{
			printf ("+ ");
		}
		p4[k].print();
		++k;
	}
	return 0;
}