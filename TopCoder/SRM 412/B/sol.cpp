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

class StringsAndTabs{
public:
	vector <string> transformTab(vector <string> tab, vector <int> stringsA, vector <int> stringsB, int d)
	{
		vector <string> ans(stringsB.size());
		for (int i=0; i<ans.size(); ++i){
			ans[i].assign(tab[0].size(), '-');
		}
		// columns
		for (int i=0; i<tab[0].size(); ++i){
			// search notes
			vector <int> nott;
			for (int j=0; j<tab.size(); ++j){
				int tmp;
				if (isdigit(tab[j][i])){
					tmp=tab[j][i]-'0'+stringsA[j];
					nott.push_back(tmp);
				}
				else if (isalpha(tab[j][i])){
					tmp=tab[j][i]-'A'+10+stringsA[j];
					nott.push_back(tmp);
				}
			}
			//sort notes
			sort(nott.rbegin(), nott.rend());
			
			// try to play
			for (int k=0; k<nott.size(); ++k){
				int toplay=nott[k]+d;
				int wher=-1;
				int how=1e+9;
				for (int j=0; j<ans.size(); ++j){
					if (ans[j][i]=='-' &&toplay-stringsB[j]>=0 && toplay-stringsB[j]<=35){
						if (how>=toplay-stringsB[j]){
							how=toplay-stringsB[j];
							wher=j;
						}
					}
				}
				if (wher==-1){
					for (int j=0; j<ans.size(); ++j){
						ans[j][i]='x';
					}
					break;
				}
				else{
					if (how<=9){
						ans[wher][i]='0'+how;
					}
					else{
						ans[wher][i]='A'+how-10;
					}
				}
			}
		}
		return ans;
	}
};
//declarations
StringsAndTabs solve;
vector <string> a;
vector <int> b, c;

void input (void){
	a.push_back("-4457754-20024422-4457754-20024200-");
	b.push_back(0);
	c.push_back(28);
	c.push_back(23);
	c.push_back(19);
	c.push_back(14);
	c.push_back(9);
	c.push_back(4);
}

void output (void){
	 solve.transformTab(a, b, c, 12);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}