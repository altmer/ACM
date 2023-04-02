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

int ntest, n;
string s;
vector <string> male(30), female(30);
set <char> lex_ord;
int num[256];
vector <char> name_mal (30), name_fem(30);
bool free_mal[30], free_fem[30];
int mar_mal[30], mar_fem[30];

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	scanf ("%d", &ntest);

	for (int test=0; test<ntest; ++test){
		scanf ("%d\n", &n);
		for (int i=0; i<n; ++i){
			free_mal[i]=true;
			free_fem[i]=true;
		}
		lex_ord.clear();
		getline(cin, s);
		// males
		for (int i=0; i<n; ++i){
			getline(cin, s);
			name_mal[i]=s[0];
			num[s[0]]=i;
			lex_ord.insert(s[0]);
			male[i]=s.substr(2);
		}
		// females
		for (int i=0; i<n; ++i){
			getline(cin, s);
			name_fem[i]=s[0];
			num[s[0]]=i;
			female[i]=s.substr(2);
		}
		// marrying
		bool fin=false;
		while (!fin){
			for (int i=0; i<n; ++i){
				if (free_mal[i]){
					for (int j=0; j<male[i].size(); ++j){
						int wom=num[male[i][j]];
						if (free_fem[wom]){
							free_fem[wom]=false;
							free_mal[i]=false;
							mar_mal[i]=wom;
							mar_fem[wom]=i;
						}
						else{
							int cont=mar_fem[wom];
							for (int k=0; k<female[wom].size(); ++k){
								if (num[female[wom][k]]==cont){
									break;
								}
								else if (num[female[wom][k]]==i){
									free_mal[cont]=true;
									free_fem[wom]=false;
									free_mal[i]=false;
									mar_mal[i]=wom;
									mar_fem[wom]=i;
								}
							}
						}
						if (!free_mal[i])
							break;
					}
					break;
				}
			}
			fin=true;
			for (int i=0; i<n; ++i){
				if(free_mal[i]){
					fin=false;
					break;
				}
			}
		}
		for (set<char>::iterator it=lex_ord.begin(); it!=lex_ord.end(); ++it){
			cout << *it << " " << name_fem [ mar_mal [ num[*it] ] ] << "\n";
		}
		if (test!=ntest-1)
			cout <<  "\n";
	}

	return 0;
}