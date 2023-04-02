#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

struct zver{
	string name, beg, end;
	long long num;
	zver() :name(),beg(),end(),num(0) {}
};

const int MOD=1000000007;
vector <zver> z;
string godz, z1, z2;
int m;

int cnt_num(const string& s){
	int cnt=0;
	for (int i=s.find(godz); i<s.size() && i!=-1; i=s.find(godz,i+1) ){
		++cnt;
	}
	return cnt;
}

void part(zver& t){
	if(godz.size()>1){
		t.beg=t.name.substr(0, godz.size()-1);
		t.end=t.name.substr(t.name.size()-godz.size()+1);
	}
	t.name="";
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	cin >> godz >> z1 >> z2 >> m;
	z.resize(m+2);

	z[0].name=z1;
	if(z[0].name.size()>=godz.size()){
		z[0].num=cnt_num(z[0].name);
	}
	if(z[0].name.size()>=2*godz.size()){
		part(z[0]);
	}

	z[1].name=z2;
	if(z[1].name.size()>=godz.size()){
		z[1].num=cnt_num(z[1].name);
	}
	if(z[1].name.size()>=2*godz.size()){
		part(z[1]);
	}

	for (int i=2; i<m+2; ++i){
		int fr, to;
		scanf("%d%d", &fr, &to);
		fr--; to--;
		if(z[fr].name.empty() && z[to].name.empty()){
			z[i].beg=z[fr].beg;
			z[i].num=z[fr].num+z[to].num;
			z[i].end=z[to].end;
			z[i].num+=cnt_num(z[fr].end+z[to].beg);
		}
		else if(z[fr].name.empty()){
			z[i].beg=z[fr].beg;
			z[i].num=z[fr].num+z[to].num;
			if(godz.size()>1){
				if(z[to].name.size()>godz.size()-1){
					z[i].num += cnt_num(z[fr].end+z[to].name.substr(0, godz.size()-1));
				}
				else{
					z[i].num += cnt_num(z[fr].end+z[to].name);
				}
			}
			if(godz.size()>1){
				z[i].end=(z[fr].end+z[to].name);
				z[i].end=z[i].end.substr(z[i].end.size()-godz.size()+1);
			}
			else{
				z[i].end="";
			}
		}
		else if(z[to].name.empty()){
			z[i].num=z[fr].num+z[to].num;
			z[i].end=z[to].end;
			if(godz.size()>1){
				if(z[fr].name.size()>godz.size()-1){
					z[i].num += cnt_num(z[fr].name.substr(z[fr].name.size()-godz.size()+1)+z[to].beg);
				}
				else{
					z[i].num += cnt_num(z[fr].name+z[to].beg);
				}
			}
			if(godz.size()>1){
				z[i].beg=(z[fr].name+z[to].beg);
				z[i].beg=z[i].beg.substr(0,godz.size()-1);
			}
			else{
				z[i].beg="";
			}
		}
		else{
			z[i].name=z[fr].name+z[to].name;
			z[i].num=cnt_num(z[i].name);
			if(z[i].name.size()>=2*godz.size()){
				part(z[i]);
			}
		}
		z[i].num%=MOD;
	}
	printf("%d", z.back().num);

	return 0;
}