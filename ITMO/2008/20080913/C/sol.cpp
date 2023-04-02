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

class opentag{
public:
	char type;
	int line, pos;
	int num;
	opentag(char ch=' ', int l=-1, int p=-1, int n=-1) : type(ch), line(l),pos(p), num(n) {}
};

vector <string> text;
string s;
stack <int> ti, tb, tu;
vector <opentag> v;

int main (void)
{
	freopen ("bbcodes.in", "r", stdin);
	freopen ("bbcodes.out", "w", stdout);

	while (getline(cin, s)){
		text.push_back(s);
	}
	
	for (int i=0; i<text.size(); ++i){
		for (int j=0; j<text[i].size(); ++j){
			if (text[i][j]=='[' && j+2<text[i].size()){
				if (text[i][j+1]=='/'){
					if (j+3<text[i].size() && text[i][j+3]==']' && (tolower(text[i][j+2])=='i' 
						|| tolower(text[i][j+2])=='b' || tolower(text[i][j+2])=='u')){
							// new closetag
							int from;
							switch (tolower(text[i][j+2])){
								case 'i':
									if (!ti.empty()){
										from=ti.top();
										ti.pop();
										text[v[from].line][v[from].pos]='<';
										text[v[from].line][v[from].pos+1]=v[from].type;
										text[v[from].line][v[from].pos+2]='>';
										text[i][j]='<';
										text[i][j+2]=tolower(text[i][j+2]);
										text[i][j+3]='>';
									}
									break;
								case 'b':
									if (!tb.empty()){
										from=tb.top();
										tb.pop();
										text[v[from].line][v[from].pos]='<';
										text[v[from].line][v[from].pos+1]=v[from].type;
										text[v[from].line][v[from].pos+2]='>';
										text[i][j]='<';
										text[i][j+2]=tolower(text[i][j+2]);
										text[i][j+3]='>';
									}
									break;
								case 'u':
									if (!tu.empty()){
										from=tu.top();
										tu.pop();
										text[v[from].line][v[from].pos]='<';
										text[v[from].line][v[from].pos+1]=v[from].type;
										text[v[from].line][v[from].pos+2]='>';
										text[i][j]='<';
										text[i][j+2]=tolower(text[i][j+2]);
										text[i][j+3]='>';
									}
									break;
							}
					}
				}
				else if (text[i][j+2]==']' && (tolower(text[i][j+1])=='i' || tolower(text[i][j+1])=='b' || 
					tolower(text[i][j+1])=='u')){
					// new opentag
						v.push_back(opentag(tolower(text[i][j+1]), i, j,v.size()));
						switch(v.back().type){
							case'i': ti.push(v.back().num);
									 break;
							case'b': tb.push(v.back().num);
									 break;
							case 'u': tu.push(v.back().num);
									 break;
						}
				}
			}
		}
	}

	for (int i=0; i<text.size(); ++i){
		cout << text[i] << "\n";
	}

	return 0;
}