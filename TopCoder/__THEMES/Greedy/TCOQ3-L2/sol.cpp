#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct edge{
	int st, end, len;
	const bool operator < (const edge &t) const{
		return len<t.len;
	}
};

class CableDonation{
public:
	int cable(vector <string> L){
		vector <edge> E;

		for (int i=0; i<L.size(); ++i){
			for (int j=0; j<L[i].size(); ++j){
				if (isalpha(L[i][j])){
					edge T;
					T.st=i;
					T.end=j;
					if (islower(L[i][j])){
						T.len=L[i][j]-'a'+1;
					}
					else{
						T.len=L[i][j]-'A'+27;
					}
					E.push_back(T);
				}
			}
		}
		//

		sort (E.begin(), E.end());
		vector <bool> U (E.size());
		vector <int> mark(L.size());
		bool fin=false;
		int col=1;
		for (int i=0; !fin && i<E.size(); ++i){

			int a=E[i].st;
			int b=E[i].end;
			if (a==b || U[i])
				continue;

			//
			if(!mark[a] && !mark[b]){
				U[i]=true;
				mark[a]=mark[b]=col++;
			}
			//
			else if (!mark[a]){
				U[i]=true;
				mark[a]=mark[b];
			}
			else if (!mark[b]){
				U[i]=true;
				mark[b]=mark[a];
			}
			else if (mark[a]!=mark[b]){
				U[i]=true;
				int rec=mark[a];
				for (int j=0; j<mark.size(); ++j){
					if (mark[j]==rec)
						mark[j]=mark[b];
				}
			}
			fin=true;
			for (int j=1; fin && j<mark.size(); ++j){
				if (!mark[j] || mark[j]!=mark[j-1]){
					fin=false;
				}
			}
		}
		fin=true;
		for (int j=1; fin && j<mark.size(); ++j){
			if (!mark[j] || mark[j]!=mark[j-1]){
				fin=false;
			}
		}		

		if (!fin)
			return -1;

		int ret=0;
		for (int i=0; i<U.size(); ++i){
			if (!U[i]){
				ret+=E[i].len;
			}
		}

		return ret;

		// end of method
	}	
};

//declarations
vector <string> A;
CableDonation solve;

void input (void){
	int n;
	scanf ("%d\n", &n);
	string s;
	for (int i=0; i<n; ++i){
		getline (cin, s);
		A.push_back(s);
	}
}

void output (void){
	cout << solve.cable(A);
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}