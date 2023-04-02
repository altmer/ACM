#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct node{
	int par, lev;
	vector <int> child, user;
	node():par(0){};
};

int cur=1;

class PermissionTree{
public:
	map <string, int> ID;
	vector <node> T;
	int ret, nod;
	vector <int> genID (string &s){
		vector <int> ans;
		string t;
		int pos=0;
		while (pos<s.size()){
			t.clear();
			while (pos<s.size() && s[pos]!=','){
				t+=s[pos];
				++pos;
			}
			++pos;
			if (!ID.count(t)){
				ID[t]=cur++;
			}
			ans.push_back(ID[t]);
		}
		return ans;
	}
	int dfs (int u, int id){
		int ans=0;
		for (int i=0; i<T[u].user.size(); ++i){
			if (T[u].user[i]==id){
				if (ret<1){
					ret=1;
					nod=u;
				}
				else if (ret==1){
					if(T[u].lev>T[nod].lev)
						nod=u;
				}
				return 1;
			}
		}
		for (int i=0; i<T[u].child.size(); ++i){
			ans+=dfs(T[u].child[i], id);
		}
		if (ans>ret){
			ret=ans;
			nod=u;
		}
		else if (ans==ret && T[u].lev>T[nod].lev){
			nod=u;
		}
		return ans;
	}
	vector <int> findHome(vector <string> F, vector <string> U){
		T.resize(F.size());
		vector <int> ans;
		// database, tree
		for (int i=0; i<F.size(); ++i){
			istringstream str_in(F[i]);
			int par;
			str_in>>par;
			if (par==i){
				par=-1;
				T[i].lev=0;
			}
			else{
				T[par].child.push_back(i);
				T[i].lev=T[par].lev+1;
			}
			T[i].par=par;
			string us;
			str_in>>us;
			T[i].user=genID(us);			
		}
		//solve
		for (int i=0; i<U.size(); ++i){
			ret=0;
			nod=-1;
			if (ID(U[i]).count())
				dfs(0, ID[U[i]]);
			ans.push_back(nod);
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