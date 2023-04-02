#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

double eps=1e-6;

struct melod{
	int q, p;
	double dif;
};

bool cmp(melod &t1, melod &t2){
	return t1.dif<t2.dif || (fabs(t1.dif-t2.dif)<eps && t1.p>t2.p);
}

map <string, melod> A;
map <string, melod>::iterator it;
set <string> app;
int n, m, k;
string s, ans;
melod cur;
bool guess;
int cas=1;

int main (void)
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	while (true){
		A.clear();
		scanf ("%d%d%d\n", &n, &m, &k);
		if (n==0)
			break;
		cur.dif=10;
		
		for (int i=0; i<n; ++i){
			cin >> s >> ans;
			app.clear();
			ans=="Yes"? guess=1 : guess=0;
			for (int j=0; j<=int(s.size())-k; ++j){
				string temp=s.substr(j, k);
				if (app.find(temp)==app.end()){
					app.insert(temp);
					A[temp].q+=guess;
					A[temp].p+=1;
				}
			}
		}

		ans="No solution";

		for (it=A.begin(); it!=A.end(); ++it){
			if (it->second.p<m)
				continue;
			it->second.dif=double(it->second.q)/double(it->second.p);
			if (cmp(it->second,cur)){
				cur=it->second;
				ans=it->first;
			}
		}

		cout<< "Case " << cas <<": " << ans << "\n";
		++cas;
	}

	return 0;
}