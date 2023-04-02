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

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	string t="1.2 2.3    3.2   1.5 4.3432 4.3213 ";
	double tpd;
/*	
	while(sscanf(t.c_str(), "%lf", &tpd)!=-1)
		cout << tpd << endl;
*/
	istringstream iss;
	iss.str(t);
	while((iss>>tpd)){
		cout << tpd << endl;
	}

	return 0;
}