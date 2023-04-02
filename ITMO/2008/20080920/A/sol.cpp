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
#include <limits>
#include <map>
#include <set>
using namespace std;

class team{
public:
	string name;
	int runs[10], time[10];
	team (const string& n) : name(n)
	{
		for (int i=0; i<10; ++i){
			runs[i]=0;
			time[i]=-1;
		}
	}
};

map <string, int> T;
vector <team> v;
int n;
int tm[10], rn[10], slv[10];

int main (void)
{
	freopen ("a.in", "r", stdin);
	/* comment this!*/	//freopen ("a.out", "w", stdout);

	cin >> n;

	v.reserve(100);

	for (int i=0; i<n; ++i){
		int time;
		string s, prob, res;
		int numt;

		cin >> time >> s >> prob >> res;
		if (T.count(s)==0){
			T[s]=numt=v.size();
			v.push_back(team(s));
		}
		else{
			numt=T[s];
		}
		if (v[numt].time[prob[0]-'A']==-1){
			if (res=="A"){
				++v[numt].runs[prob[0]-'A'];
				v[numt].time[prob[0]-'A']=time;
			}
			else{
				++v[numt].runs[prob[0]-'A'];
			}
		}
	}

	for (int i=0; i<v.size(); ++i){
		for (int j=0; j<9; ++j){
			if (v[i].time[j]!=-1){
				tm[j]+=v[i].time[j];
				rn[j]+=v[i].runs[j];
				++slv[j];
			}
		}
	}

	for (int i=0; i<9; ++i){
		printf ("%c %d ", 'A'+i, slv[i]);
		if (slv[i]){
			printf ("%.2lf %.2lf\n", double(rn[i])/double(slv[i]), double(tm[i])/double(slv[i]));
		}
		else{
			printf ("\n");
		}
	}
			

	return 0;
}