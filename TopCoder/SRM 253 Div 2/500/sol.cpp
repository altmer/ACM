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

class Decipher{
public:
	vector <string> decipher(vector <string> en, string f){
		struct let{
			char l;
			int num;
			bool operator < (let t){
				if (num==t.num)
					return l<t.l;
				return num<t.num;
			}
		};
		map <char, int> dict;
		map <char, char> link;
		vector <let> v;
		for (int i=0; i<en.size(); ++i){
			for (int j=0; j<en[i].size(); ++j){
				if (isalpha(en[i][j])){
					dict[en[i][j]]++;
				}
			}
		}
		for (map <char, int> ::iterator it=dict.begin(); it!=dict.end(); ++it){
			let t;
			t.l=it->first;
			t.num=it->second;
			v.push_back(t);
		}
		sort (v.begin(), v.end());
		for (int i=0;i<v.size(); ++i){
			link[v[i].l]=f[i];
		}
		for (int i=0; i<en.size(); ++i){
			for (int j=0; j<en[i].size(); ++j){
				if (isalpha(en[i][j])){
					en[i][j]=link[en[i][j]];
				}
			}
		}
		return en;
	}
};

//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}