#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
using namespace std;

int book, perep, st, fin;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> book >> perep >> st >> fin;
	book+=perep;
	book+=perep;
	if(st<fin)cout << 2*perep+(fin-st-1)*book;else
		cout << (book-2*perep)+(st-fin)*book; 
	return 0;
}