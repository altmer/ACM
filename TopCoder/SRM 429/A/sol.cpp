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
using namespace std;

class SubrectanglesOfTable{
public:
	vector<long long> getQuantity(vector <string> table){
		vector<long long> ans(26);
		for (int i=0; i<table.size(); ++i){
			table[i]+=table[i];
		}
		table.insert(table.end(), table.begin(), table.end());
		vector <vector<long long> > T (table.size(), vector<long long>(table[0].size(),0));
		for (int i=0; i<table.size(); ++i){
			for (int j=0; j<table[i].size(); ++j){
/*				if(i>0)
					T[i][j]+=T[i-1][j];
				if(j>0)
					T[i][j]+=T[i][j-1];
				if(i>0 && j>0)
					T[i][j]-=T[i-1][j-1];*/
				T[i][j]+=(int(table.size())-i)*(int(table[i].size())-j);
				T[i][j]+=(int(table.size())-i)*(int(table[i].size())-j)*((i+1)*(j+1)-1);
			}
		}
		for (int i=0; i<table.size(); ++i){
			for (int j=0; j<table[i].size(); ++j){
				ans[table[i][j]-'A']+=T[i][j];
			}
		}
		return ans;
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