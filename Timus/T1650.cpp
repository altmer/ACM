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

struct burj {
	string city; 
	long long money;
	burj(string c="", long long tmp=0) : city(c),money(tmp) {}
};

struct city{
	int days;
	long long money;
	city(int d=0, long long tmp=0) : days(d),money(tmp) {}
};

map <string, burj> bur;
map <string, city> town;
multiset<pair<long long,string>, greater<pair<long long, string> > > q;
char str1[30],str2[30];
string name,cit;
int n, m;

void scopy(string& s, char* p){
	while(*p){
		s+=*p++;
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	scanf("%d\n",&n);
	for (int i=0; i<n; ++i){
		name=cit="";
		long long tmp;
		scanf("%s%s%I64d",str1,str2,&tmp);
		scopy(name,str1);
		scopy(cit,str2);
		bur[name]=burj(cit,tmp);
		town[cit].money+=tmp;
	}

	for (map <string, city>::iterator it=town.begin(); it!=town.end(); ++it){
		q.insert(make_pair(it->second.money,it->first));
	}

	scanf("%d%d", &m,&n);
	int curd=0, tmp;

	for (int i=0; i<n; ++i){
		name=cit="";
		scanf("%d%s%s", &tmp, str1,str2);
		scopy(name,str1);
		scopy(cit,str2);
		// 
		if(curd != tmp){
			if(q.size()>1){
				multiset<pair<long long,string>, greater<pair<long long, string> > >::iterator it=q.begin();
				it++;
				if(q.begin()->first!=it->first){
					town[q.begin()->second].days+=tmp-curd;
				}
			}
			else if (!q.empty()){
				town[q.begin()->second].days+=tmp-curd;
			}
			curd=tmp;
		}
		// flight
		burj& olig = bur[name];
		city& c1 = town[olig.city];
		city& c2 = town[cit];

		q.erase(q.find(make_pair(c1.money,olig.city)));
		multiset<pair<long long,string>, greater<pair<long long, string> > >::iterator it=q.find(make_pair(c2.money,cit));
		if(it!=q.end())
			q.erase(it);

		c1.money-=olig.money;
		c2.money+=olig.money;

		q.insert(make_pair(c1.money,olig.city));
		q.insert(make_pair(c2.money,cit));

		olig.city=cit;
	}
	if(curd!=m){
		if(q.size()>1){
			multiset<pair<long long,string>, greater<pair<long long, string> > >::iterator it=q.begin();
			it++;
			if(q.begin()->first!=it->first){
				town[q.begin()->second].days+=m-curd;
			}
		}
		else if (!q.empty()){
			town[q.begin()->second].days+=m-curd;
		}
	}

	for (map <string, city>::iterator it=town.begin(); it!=town.end(); ++it){
		if(it->second.days){
			cout << it->first << ' ' << it->second.days << '\n';
		}
	}

	return 0;
}