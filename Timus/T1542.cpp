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

class Word{
public:
	string s;
	int count;
	bool operator <(const Word& w){
		if(count!=w.count){
			return count<w.count;
		}
		return s>w.s;
	}
};

const int MOD = 999983;

struct Node{
	long long h1, h2;
	int next, link;

	Node() : h1(0), h2(0), next(0), link(0) {}

    int hashCode(){
        return (int)(h1%MOD+h2%MOD)%MOD;
    }
};

Word arr[100100];
int fst[MOD];
Node mas [2000000];
int cnt=0;

void insert (const string& str, int wh){
    for (int i=0; i<min(8, (int)str.size()); ++i){
        mas[cnt].h1 = (mas[cnt].h1+str[i])*31;
    }
    for (int i=8; i<str.size(); ++i){
        mas[cnt].h2 = (mas[cnt].h2+str[i])*31;
    }
	
    int h = mas[cnt].hashCode();

    mas[cnt].link = wh;
	mas[cnt].next = fst[h];
	fst[h] = cnt++;
}	

void printOut(const string& s){
    long long h1=0, h2=0;
            
    for (int i=0; i<min(8, (int)s.length()); ++i){
         h1 = (h1+s[i])*31;
    }

	for (int i=8; i<s.length(); ++i){
		h2 = (h2+s[i])*31;
	}

	int h = (int)(h1%MOD+h2%MOD)%MOD;

	int c=0;

	for (int ind=fst[h]; ind!=-1 && c<10; ind=mas[ind].next){
		if(h1==mas[ind].h1 && h2==mas[ind].h2){
			printf("%s\n", arr[mas[ind].link].s.c_str());
			++c;
		}
	}
}


int main (void){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	int n;
	scanf("%d\n", &n);

	for (int i=0; i<MOD; ++i){
		fst[i]=-1;
	}

    for (int i=0; i<n; ++i){
		char str[20];
		int tmp;
		scanf("%s %d\n", str, &tmp);
		int len = strlen(str);
		for (int j=0; j<len; ++j){
			arr[i].s+=str[j];
		}
		arr[i].count=tmp;
    }

	sort(arr, arr+n);

    for (int i=0; i<n; ++i){
        for (int j=0; j<arr[i].s.size(); ++j){
            insert(arr[i].s.substr(0, j+1), i);
        }
    }

	int q;
	scanf("%d", &q);

	for (int i=0; i<q; ++i){
		string t;
		char str[20];
		int tmp;
		scanf("%s %d\n", str, &tmp);
		int len = strlen(str);
		for (int j=0; j<len; ++j){
			t+=str[j];
		}
		printOut(t);

		if(i!=q-1)
			printf("\n");
	}


    return 0;
}