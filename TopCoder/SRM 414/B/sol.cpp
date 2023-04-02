#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class StringInterspersal{
public:
	string minimum(vector <string> W){
		vector <int> v(W.size(), 0);
		string ans="";
		bool fin=false;
		while (!fin){
			fin=true;
			char cand=127;
			int num=-1;
			for (int i=0; i<W.size(); ++i){
				if (v[i]<W[i].size()){
					fin=false;
					if (cand>W[i][v[i]]){
						cand=W[i][v[i]];
						num=i;
					}
					else if (cand==W[i][v[i]]){
						int j=v[num]+1;
						int k=v[i]+1;
						while (j<W[num].size() && k<W[i].size()){
							if (W[num][j]<W[i][k]){
								break;
							}
							else if (W[num][j]>W[i][k]){
								cand=W[i][k];
								num=i;
								break;
							}
							++j;
							++k;
						}
					}
				}
			}
			if (!fin){
				ans+=cand;
				v[num]++;
			}
		}
		return ans;
	}
};

//declarations
StringInterspersal solve;

void input (void){
	vector <string> v;
	v.push_back("DESIGN");
	v.push_back("ALGORITHM");
	v.push_back("MARATHON");
	solve.minimum(v);

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