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

class IngredientProportions{
public:
	template <typename T>
	T gcd ( T a,  T b){
		while(b){
			T tmp=a%b;
			a=b;
			b=tmp;
		}
		return a;
	}

	vector <int> getMasses(vector <string> pr){
		vector<vector <pair <int, int> > > rel (pr.size()+1,vector<pair<int, int> >(pr.size()+1, make_pair(0,0)));
		vector<int> val (pr.size()+1, 1L);
		for (int i=0; i<pr.size(); ++i){
			int fr, to, p, q;
			sscanf(pr[i].c_str(), "#%d and #%d as %d:%d", &fr, &to, &p, &q);
			rel[to][fr]=make_pair(q,p);
			rel[fr][to]=make_pair(p,q);
		}
		for (int i=0; i<rel.size(); ++i){
			for (int j=i+1; j<rel.size(); ++j){
				if(rel[i][j].first){
					int mni=(val[i]/gcd(val[i],val[j])*val[j]*rel[i][j].first)/val[i];
					int mnj=(val[i]/gcd(val[i],val[j])*val[j]*rel[i][j].second)/val[j];
					val[i]*=mni;
					val[j]*=mnj;
					for (int k=0; k<j; ++k){
						if(rel[i][k].first){
							val[k]*=mni;
						}
					}
					for (int k=0; k<i; ++k){
						if(rel[k][j].first){
							val[k]*=mnj;
						}
					}
				}
			}
		}
		int gc=val[0];
		for (int i=1; i<val.size(); ++i){
			gc=gcd(gc,val[i]);
		}
		for (int i=0; i<val.size(); ++i){
			val[i]/=gc;
		}
		return val;
	}
};

//declarations


void input (void){
	IngredientProportions solve;
	vector<string> in;
	in.push_back("#2 and #3 as 6:8");
	in.push_back("#0 and #1 as 9:3");
	in.push_back("#3 and #0 as 7:5");
	solve.getMasses(in);
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